#include <stdio.h>

void display(int A[][10], int m, int n);
void sparseMatrix(int A[][10], int m, int n, int B[10][3]);
void simpleTranspose(int B[][3]);
void fastTranspose(int B[][3]);

int main()
{
    int A[10][10], m, n, B[10][3];
    int choice;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the element %d %d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    sparseMatrix(A, m, n, B);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display Matrix\n");
        printf("2. Generate Sparse Matrix\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(A, m, n);
            break;
        case 2:
            sparseMatrix(A, m, n, B);
            break;
        case 3:
            simpleTranspose(B);
            break;
        case 4:
            fastTranspose(B);
            break;
        case 5:
            return 0; // Exit the program
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void display(int A[][10], int m, int n)
{
    printf("\n--------\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("--------\n");
}

void sparseMatrix(int A[][10], int m, int n, int B[10][3])
{
    int k = 0;
    B[0][0] = m;
    B[0][1] = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                k++;
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
            }
        }
    }
    B[0][2] = k;
    printf("\nSparse Matrix: \n");
    printf("%d %d %d\n", B[0][0], B[0][1], B[0][2]);
    printf("------\n");
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }

}

void simpleTranspose(int B[][3])
{
    int rows, cols, integer;
    rows = B[0][0];
    cols = B[0][1];
    integer = B[0][2];
    if (integer > 0)
    {
        int D[10][3];
        D[0][0] = cols;
        D[0][1] = rows;
        D[0][2] = integer;
        int k = 1;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j <= integer; j++)
            {
                if (B[j][1] == i)
                {
                    D[k][0] = B[j][1];
                    D[k][1] = B[j][0];
                    D[k][2] = B[j][2];
                    k++;
                }
            }
        }
        printf("\nTranspose of Sparse Matrix: \n");
        printf("%d %d %d\n", D[0][0], D[0][1], D[0][2]);
        printf("------\n");
        for (int i = 1; i <= integer; i++)
        {
            printf("%d %d %d\n", D[i][0], D[i][1], D[i][2]);
        }
    }
}

void fastTranspose(int B[][3]){
    int rows, cols, integer;
    rows = B[0][0];
    cols = B[0][1];
    integer = B[0][2];
    if(integer > 0){
        int D[10][3];
        D[0][0] = cols;
        D[0][1] = rows;
        D[0][2] = integer;
        int k = 1;
        int rowTerms[cols], startingPos[cols];
        for(int i = 0; i < cols; i++){
            rowTerms[i] = 0;
        }
        for(int i = 1; i <= integer; i++){
            rowTerms[B[i][1]]++;
        }
        startingPos[0] = 1;
        for(int i = 1; i < cols; i++){
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        }
        for(int i = 1; i <= integer; i++){
            int j = startingPos[B[i][1]];
            D[j][0] = B[i][1];
            D[j][1] = B[i][0];
            D[j][2] = B[i][2];
            startingPos[B[i][1]]++;
        }
        printf("\nTranspose of Sparse Matrix(fast): \n");
        printf("%d %d %d\n", D[0][0], D[0][1], D[0][2]);
        printf("------\n");
        for (int i = 1; i <= integer; i++)
        {
            printf("%d %d %d\n", D[i][0], D[i][1], D[i][2]);
        }
    }
}