#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void initializeMatrix(int** matrix, int rows, int cols) {
    printf("������� �������� ��� ������� %d x %d:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("������� [%d][%d]: ", i + 1, j + 1);

            // �������� �� ���� ��������
            if (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("������ �����. ����������, ������� ����� �����.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void findPositiveRowAndReduceMatrix(int** matrix, int rows, int cols) {
    int positiveRow = -1;
    int sum = 0;

    // ������� ������ ������, ��� �������� ������� ������������
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

    // ���� ����� ������ �������, ��������� ����� ��������� ���� ������
    if (positiveRow != -1) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[positiveRow][j];
        }

        // ��������� ��� �������� ������� �� �����
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] -= sum;
            }
        }

        // ������� ���������
        printf("������� ������ � �������������� ���������� (������ %d)\n", positiveRow + 1);
        printf("����� ��������� ���� ������: %d\n", sum);
        printf("������� ����� ����������:\n");

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("� ������� ��� ������, ��� �������� ������� ������������.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int rows, cols;

    printf("������� ���������� ����� �������: ");
    scanf_s("%d", &rows);

    printf("������� ���������� �������� �������: ");
    scanf_s("%d", &cols);

    // �������� ������ ��� �������
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    initializeMatrix(matrix, rows, cols);

    printf("�������� �������:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    findPositiveRowAndReduceMatrix(matrix, rows, cols);

    // ����������� ���������� ������
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}