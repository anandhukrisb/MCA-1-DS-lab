#include <stdio.h>

// Function to read a square matrix (up to 3x3)
void readMatrix(int mat[3][3], int size) {
    printf("Enter elements (%dx%d):\n", size, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display the matrix
void displayMatrix(int mat[3][3], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate determinant of 2x2 matrix
int determinant2x2(int mat[3][3]) {
    return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
}

// Function to calculate determinant of 3x3 matrix
int determinant3x3(int mat[3][3]) {
    int det = mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])
            - mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])
            + mat[0][2]*(mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0]);
    return det;
}

int main() {
    int mat[3][3];
    int size, det;

    // Choose matrix size
    printf("Enter size of square matrix (2 or 3): ");
    scanf("%d", &size);

    if(size != 2 && size != 3) {
        printf("Only 2x2 or 3x3 matrices are supported.\n");
        return 1;
    }

    // Read matrix
    readMatrix(mat, size);

    // Display matrix
    printf("\nMatrix:\n");
    displayMatrix(mat, size);

    // Compute determinant
    if(size == 2) {
        det = determinant2x2(mat);
    } else {
        det = determinant3x3(mat);
    }

    // Display result
    printf("\nDeterminant = %d\n", det);

    return 0;
}
