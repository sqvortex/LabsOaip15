#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void initializeMatrix(int** matrix, int rows, int cols) {
    printf("Введите значения для матрицы %d x %d:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);

            // Проверка на ввод символов
            if (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void findPositiveRowAndReduceMatrix(int** matrix, int rows, int cols) {
    int positiveRow = -1;
    int sum = 0;

    // Находим первую строку, все элементы которой положительны
    for (int i = 0; i < rows; ++i) {
        int allPositive = 1;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] <= 0) {
                allPositive = 0;
                break;
            }
        }

        if (allPositive) {
            positiveRow = i;
            break;
        }
    }

    // Если такая строка найдена, вычисляем сумму элементов этой строки
    if (positiveRow != -1) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[positiveRow][j];
        }

        // Уменьшаем все элементы матрицы на сумму
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] -= sum;
            }
        }

        // Выводим результат
        printf("Найдена строка с положительными элементами (строка %d)\n", positiveRow + 1);
        printf("Сумма элементов этой строки: %d\n", sum);
        printf("Матрица после уменьшения:\n");

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("В матрице нет строки, все элементы которой положительны.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int rows, cols;

    printf("Введите количество строк матрицы: ");
    scanf_s("%d", &rows);

    printf("Введите количество столбцов матрицы: ");
    scanf_s("%d", &cols);

    // Выделяем память для матрицы
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    initializeMatrix(matrix, rows, cols);

    printf("Исходная матрица:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    findPositiveRowAndReduceMatrix(matrix, rows, cols);

    // Освобождаем выделенную память
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}