#include <stdio.h>


void create(int[10][10], int, int, int[10][3]);
void display(int[10][3]);
void simple_transpose(int[10][3], int [10][3]);
void fast_transpose(int[10][3], int[10][3]);

int main()
{
	printf("\n----------SPARSE MATRIX---------- ");	

	int rows, columns;
	printf("\nEnter the number of rows and columns: ");
	scanf("%d %d", &rows, &columns);

	int s_matrix[10][10];
	int c_matrix[10][3];

	printf("\nEnter the values\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("\n[%d][%d] = ", i, j);
			scanf("\n%d", &s_matrix[i][j]);
		}
	}

	while(1)
	{
		int choice;
		printf("\nChoose Operation\n");
		printf("\n1. DISPLAY\n2. CREATE SPARSE MATRIX\n3. SIMPLE TRANSPOSE\n4. FAST TRANSPOSE\n5. EXIT\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: //display
				display(c_matrix);
				break;
	
			case 2: //create compact matrix
				
				create(s_matrix, rows, columns, c_matrix);
				break;

			case 3: //simple transpose
			{
				int transpose[10][3];
				simple_transpose(c_matrix, transpose);
				break;
			}

			case 4: //fast transpose
			{
				int transpose[10][3];
				fast_transpose(c_matrix, transpose);
				break;
			}
			case 5:
				return 0;
				break;
		}
	}
}

void create(int S[][10], int r, int c, int C[10][3])
{
	C[0][0] = r;
	C[0][1] = c;
	int k = 0;

	for(int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (S[i][j] != 0)
			{
				k++;
				C[k][0] = i;
				C[k][1] = j;
				C[k][2] = S[i][j];
			}
		}
	}

	C[0][2] = k;
}

void display(int C[10][3])
{
	int r = C[0][0] + 1;
	int c = C[0][1];

	for (int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			printf("[%d]", C[i][j]);
		}
		printf("\n");
	}
}

void simple_transpose(int A[10][3], int T[10][3])
{
	int columns = A[0][1];
	int num = A[0][2];

	if (num > 0)
	{
		T[0][0] = A[0][1];
		T[0][1] = A[0][0];
		T[0][2] = A[0][2];
		int k = 1;

		for (int i = 0; i < columns; i++)	
		{
			for (int j = 0; j < num; j++)
			{
				if (i == A[j][1])
				{
					T[k][0] = A[j][1];
					T[k][1] = A[j][0];
					T[k][2] = A[k][2];
					k++;
				}
			}
		}	
	}

	display(T);
}

void fast_transpose(int A[10][3], int T[10][3])
{
	int rows = A[0][0], cols = A[0][1], num = A[0][2];
	if (num > 0)
	{
		T[0][0] = cols;
		T[0][1] = rows;
		T[0][2] = num;
		int k = 1;
		int row_terms[cols], starting_pos[cols];

		for (int i = 0; i < cols; i++)
		{
			row_terms[i] = 0;
		}

		for (int i = 1; i <= num; i++)
		{
			row_terms[A[i][1]]++;
		}
		
		starting_pos[0] = 1;
		
		for(int i = 1; i < cols; i++)
		{
			starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
		}

		for (int i = 1; i <= num; i++)
		{
			int j = starting_pos[A[i][1]];
			T[j][0] = A[i][1];
			T[j][1] = A[i][0];
			T[j][2] = A[i][2];
			starting_pos[A[i][1]]++;
		}
	}

	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("[%d]", T[i][j]);
		}
		printf("\n");
	}	
}