#include <stdio.h>

// Function to read a matrix
void readMatrix(int mat[10][10], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
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

// Function to add two matrices
void addMatrix(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrix B from matrix A
void subtractMatrix(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int rows, cols;

    // Input dimensions
    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Read Matrix A
    printf("Matrix A:\n");
    readMatrix(A, rows, cols);

    // Read Matrix B
    printf("Matrix B:\n");
    readMatrix(B, rows, cols);

    // Display matrices
    printf("\nMatrix A:\n");
    displayMatrix(A, rows, cols);

    printf("\nMatrix B:\n");
    displayMatrix(B, rows, cols);

    // Add matrices
    addMatrix(A, B, result, rows, cols);
    printf("\nAddition of A and B:\n");
    displayMatrix(result, rows, cols);

    // Subtract matrices
    subtractMatrix(A, B, result, rows, cols);
    printf("\nSubtraction of B from A:\n");
    displayMatrix(result, rows, cols);

    return 0;
}
