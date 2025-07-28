#include <stdio.h>

// Function to read a matrix
void readMatrix(int mat[10][10], int rows, int cols) {
    printf("Enter elements (%d x %d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int r1, c1, r2, c2;

    // Input dimensions
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Validate dimensions
    if(c1 != r2) {
        printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
        return 1;
    }

    // Read matrices
    printf("Matrix A:\n");
    readMatrix(A, r1, c1);

    printf("Matrix B:\n");
    readMatrix(B, r2, c2);

    // Multiply matrices
    multiplyMatrix(A, B, result, r1, c1, c2);

    // Display result
    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    printf("\nResult of A x B:\n");
    displayMatrix(result, r1, c2);

    return 0;
}
