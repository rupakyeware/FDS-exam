#include <stdio.h>

void accept_values(int matrix[10][10], int row, int col);
void display_matrix(int matrix[10][10], int rows, int cols);
void addition(int matrix[10][10], int matrix1[10][10], int r1, int r2, int c1, int c2);
void subtraction(int matrix[10][10], int matrix1[10][10], int r1, int r2, int c1, int c2);
void multiplication(int matrix[10][10], int matrix1[10][10], int r1, int c1, int r2, int c2);

int main(){
    int matrix1[10][10], matrix2[10][10], row1, row2, col1, col2, operation;
    printf("Enter the size of matrix 1 you want: ");
    scanf("%d %d", &row1, &col1); 
    printf("Enter the size of matrix 2 you want: ");
    scanf("%d %d", &row2, &col2);

    accept_values(matrix1, row1, col1);
    display_matrix(matrix1, row1, col1);

    printf("\nEnter values for matrix 2\n");
    accept_values(matrix2, row2, col2);
    display_matrix(matrix2, row2, col2);
    
    printf("Enter the operation you want to perform:\n1. Addition\n2. Substraction\n3. Multiplication\n4. Quit\n----------:  ");
    scanf("%d", &operation);
    switch(operation){
        case 1:
            addition(matrix1, matrix2, row1, row2, col1, col2);
            break;
        case 2:
            subtraction(matrix1, matrix2, row1, row2, col1, col2);
            break;
        case 3:
            multiplication(matrix1, matrix2, row1, col1, row2, col2);
            break;
        case 4:
            break;
        default:
            printf("Wrong choice! try again");
            break;
    }
}

void accept_values(int matrix[10][10], int row, int col){
    for(int i=0; i<row; i++){
        for(int j =0; j<col; j++){
            printf("Enter the value of matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[10][10], int rows, int cols){
    printf("\n------------------\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}

void addition(int matrix[10][10], int matrix1[10][10], int r1, int r2, int c1, int c2){
    if (r1 == r2 && c1 == c2){
        int result[10][10];
        for (int i=0; i<r1; i++){
            for (int j=0; j<c1; j++){
                result[i][j] = matrix[i][j] + matrix1[i][j];
            }
        }
        display_matrix(result, r1, c1);
    }
    else
    {
        printf("Addition is not possible\n");
    }
}

void subtraction(int matrix[10][10], int matrix1[10][10], int r1, int r2, int c1, int c2){
    if (r1 == r2 && c1 == c2)
    {
        int result[10][10];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                result[i][j] = matrix[i][j] - matrix1[i][j];
            }
        }
        display_matrix(result, r1, c1);
    }
    else
    {
        printf("Addition is not possible\n");
    }
}

void multiplication(int matrix[10][10], int matrix1[10][10], int r1, int c1, int r2, int c2){
    if(c1 == r2){
        int result[10][10];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                result[i][j] = 0;
                for(int k=0; k<c1; k++){
                    result[i][j] += matrix[i][k] * matrix1[k][j];
                }
            }
        }
        display_matrix(result, r1, c2);
    }else{
        printf("Multiplication is not possible");
    }
}
