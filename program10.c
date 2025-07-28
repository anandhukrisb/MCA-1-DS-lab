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

// Function to find transpose of a matrix
void transposeMatrix(int mat[10][10], int transposed[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

int main() {
    int mat[10][10], transposed[10][10];
    int rows, cols;

    // Input dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Read matrix
    readMatrix(mat, rows, cols);

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    displayMatrix(mat, rows, cols);

    // Find transpose
    transposeMatrix(mat, transposed, rows, cols);

    // Display transposed matrix
    printf("\nTranspose of the Matrix:\n");
    displayMatrix(transposed, cols, rows);

    return 0;
}
