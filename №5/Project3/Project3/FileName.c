/*Из двумерной матрицы размером NxM удалить элементы, находящиеся ниже побочной диагонали.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void removeBelowSecondaryDiagonal(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + j >= rows) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int N, M;

    printf("Введите размеры матрицы (NxM): ");
    // Проверка на ввод символов
    if (scanf_s("%d %d", &N, &M) != 2 || N <= 0 || M <= 0) {
        printf("Неверные размеры матрицы.\n");
        return 1;
    }

    int** matrix = allocateMatrix(N, M);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Проверка на ввод символов
            if (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("Ошибка ввода. Введите целое число.\n");
                freeMatrix(matrix, N);
                return 1;
            }
        }
    }

    removeBelowSecondaryDiagonal(matrix, N, M);

    printf("Матрица после удаления элементов ниже побочной диагонали:\n");
    printMatrix(matrix, N, M);

    freeMatrix(matrix, N);

    return 0;
}