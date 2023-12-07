/*� ��������� ������� �������� NxM ����� ������� � ���������� ������ ��������� � ������� ���.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void allocateMatrix(int*** matrix, int rows, int cols) {
    *matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        (*matrix)[i] = (int*)malloc(cols * sizeof(int));
    }
}

void deallocateMatrix(int*** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}

void fillMatrix(int** matrix, int rows, int cols) {
    printf("������� �������� ������� %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // ���������, ������� �� ����������� ������
            if (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("������ �����. ����������, ������� ������ ����� �����.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    printf("������� %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void findAndRemoveMaxSumColumn(int** matrix, int rows, int* cols) {
    int maxSum = 0;
    int maxSumColumn = 0;

    // ������� ������� � ���������� ������
    for (int j = 0; j < *cols; ++j) {
        int currentSum = 0;
        for (int i = 0; i < rows; ++i) {
            currentSum += matrix[i][j];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxSumColumn = j;
        }
    }

    // ������� ��������� �������
    for (int i = 0; i < rows; ++i) {
        for (int j = maxSumColumn; j < *cols - 1; ++j) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }

    // ��������� ���������� ��������
    *cols -= 1;

    printf("������� � ���������� ������ (%d) ������.\n", maxSum);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int** matrix = NULL;
    int rows, cols;

    printf("������� ���������� ����� �������: ");
    if (scanf_s("%d", &rows) != 1) {
        printf("������ �����. ����������, ������� ������ ����� �����.\n");
        return EXIT_FAILURE;
    }

    printf("������� ���������� �������� �������: ");
    if (scanf_s("%d", &cols) != 1) {
        printf("������ �����. ����������, ������� ������ ����� �����.\n");
        return EXIT_FAILURE;
    }

    allocateMatrix(&matrix, rows, cols);

    fillMatrix(matrix, rows, cols);

    printf("�������� ");
    printMatrix(matrix, rows, cols);

    findAndRemoveMaxSumColumn(matrix, rows, &cols);

    printf("������� ����� �������� �������:\n");
    printMatrix(matrix, rows, cols);

    deallocateMatrix(&matrix, rows);

    return 0;
}
