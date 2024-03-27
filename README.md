
#include <stdio.h>
#include <stdlib.h>

double** allocate_matrix(int n, int m) {
    double** matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(double));
    }
    return matrix;
}

void input_matrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double** matrix_operation(double** matrix1, double** matrix2, int n, int m, char operation) {
    double** result = allocate_matrix(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (operation == '+') result[i][j] = matrix1[i][j] + matrix2[i][j];
            else if (operation == '-') result[i][j] = matrix1[i][j] - matrix2[i][j];
            else if (operation == '*') result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    double** matrix1 = allocate_matrix(rows, cols);
    double** matrix2 = allocate_matrix(rows, cols);

    printf("Enter the elements of the first matrix:\n");
    input_matrix(matrix1, rows, cols);

    printf("Enter the elements of the second matrix:\n");
    input_matrix(matrix2, rows, cols);

    char operation;
    printf("Enter the operation (+, -, *): ");
    scanf(" %c", &operation);

    double** result = matrix_operation(matrix1, matrix2, rows, cols, operation);

    printf("Resultant matrix:\n");
    print_matrix(result, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
