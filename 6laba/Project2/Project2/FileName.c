/*� ������� �������� NxM ��������� ���������� ����� �� �����������
����� ������������� ��������� ������� �����*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ���������� �����
void shellSort(int** array, int* sums, int size) {
    int gap, i, j, temp;

    // �������� � �������� ����, ���������� �������� ��� �� 1
    for (gap = size / 2; gap > 0; gap /= 2) {
        // �������� �� ���������, ������� � gap-��� ��������
        for (i = gap; i < size; i++) {
            // ��������� ������� ����� � ��������������� ������
            temp = sums[i];
            int* tempRow = array[i];

            // ���������� �������� �����, ���� �� ������� ���������� ������� ��� �������� ��������
            for (j = i; j >= gap && sums[j - gap] > temp; j -= gap) {
                sums[j] = sums[j - gap];
                array[j] = array[j - gap];
            }

            // ��������� ������� ������� �� ���������� �����
            sums[j] = temp;
            array[j] = tempRow;
        }
    }
}

// ������� ���������� ����� �������
void sortMatrixRows(int** matrix, int numRows, int numCols) {
    int* sums = (int*)malloc(numRows * sizeof(int));

    // ��������� ����� ������������� ��������� � ������ ������
    for (int i = 0; i < numRows; i++) {
        int sum = 0;
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
        sums[i] = sum;
    }
    
    // �������� ������� ���������� ����� ��� ������������ ����� �������
    shellSort(matrix, sums, numRows);

    // ����������� ������, ���������� ��� ������� ����
    free(sums);
}

int main() {
    int numRows, numCols, fillOption;
    setlocale(LC_ALL, "Rus");

    // ���� ���������� �����
    printf("������� ���������� �����: ");
    while (scanf_s("%d", &numRows) != 1 || numRows <= 0) {
        printf("������ �����! ������� ���������� ���������� �����: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ���� ���������� ��������
    printf("������� ���������� ��������: ");
    while (scanf_s("%d", &numCols) != 1 || numCols <= 0) {
        printf("������ �����! ������� ���������� ���������� ��������: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ����� ������� ���������� �������
    printf("�������� ������ ���������� �������:\n");
    printf("1. ���� �������\n");
    printf("2. ���������� ���������� ����������\n");

    while (scanf_s("%d", &fillOption) != 1 || (fillOption != 1 && fillOption != 2)) {
        printf("������ �����! �������� 1 ��� 2: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ��������� ������ ��� �������
    int** matrix = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc(numCols * sizeof(int));
    }

    // ���������� �������
    if (fillOption == 1) { // ���� �������
        printf("������� �������� �������:\n");
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                while (scanf_s("%d", &matrix[i][j]) != 1) {
                    printf("������ �����! ������� ���������� ������� �������: ");
                    while (getchar() != '\n'); // ������� ������ �����
                }
            }
        }
    }
    else if (fillOption == 2) { // ���������� ���������� ����������
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                matrix[i][j] = rand() % 100; // ��������� ���������� ����� �� 0 �� 99
            }
        }
    }

    // ���������� ����� �������
    sortMatrixRows(matrix, numRows, numCols);

    // ����� ��������������� �������
    printf("��������������� �������:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // ������������ ������
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
