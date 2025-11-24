#include <stdio.h>

int main() {
    int m, n, p, q;
    int i, j, k;

    // Get dimensions for matrix A
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &n);

    // Get dimensions for matrix B
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &p);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &q);

    // Check for matrix multiplication compatibility
    if (n != p) {
        printf("Matrix multiplication is not possible: Number of columns in A (%d) must equal the number of rows in B (%d)\n", n, p);
        return 1; // Exit if not compatible
    }

    int matrixA[m][n];
    int matrixB[p][q];
    int resultMatrix[m][q]; // The resultant matrix will have dimensions m x q

    // Read elements of matrix A in row-major order
    printf("\nEnter elements of matrix A (row-major order):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Read elements of matrix B in row-major order
    printf("\nEnter elements of matrix B (row-major order):\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Initialize the result matrix to zero
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < m; i++) { // rows of result
        for (j = 0; j < q; j++) { // columns of result
            for (k = 0; k < n; k++) { // columns of A (or rows of B)
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Print matrix A
    printf("\nMatrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrixA[i][j]);
        }
        printf("\n");
    }

    // Print matrix B
    printf("\nMatrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", matrixB[i][j]);
        }
        printf("\n");
    }

    // Print the resultant matrix
    printf("\nResultant Matrix (A * B):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}