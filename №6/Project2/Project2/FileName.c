/*� ������� �������� NxM ��������� ���������� ����� �� ����������� 
����� ������������� ��������� ������� �����*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int sum;
    int* row;
} RowSum;

void shellSort(RowSum* array, int size) {
    int gap, i, j;
    RowSum temp;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; i++) {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap].sum > temp.sum; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void sortMatrixRows(int** matrix, int numRows, int numCols) {
    RowSum* sums = (RowSum*)malloc(numRows * sizeof(RowSum));

    for (int i = 0; i < numRows; i++) {
        int sum = 0;
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
        sums[i].sum = sum;
        sums[i].row = matrix[i];
    }

    shellSort(sums, numRows);

    int** tempMatrix = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        tempMatrix[i] = sums[i].row;
    }

    for (int i = 0; i < numRows; i++) {
        matrix[i] = tempMatrix[i];
    }

    free(sums);
    free(tempMatrix);
}

int main() {
    int numRows, numCols;
    setlocale(LC_ALL, "Rus");

    printf("������� ���������� �����: ");
    while (scanf_s("%d", &numRows) != 1 || numRows <= 0) {
        printf("������ �����! ������� ���������� ���������� �����: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    printf("������� ���������� ��������: ");
    while (scanf_s("%d", &numCols) != 1 || numCols <= 0) {
        printf("������ �����! ������� ���������� ���������� ��������: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    int** matrix = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc(numCols * sizeof(int));
    }

    printf("������� �������� �������:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            while (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("������ �����! ������� ���������� ������� �������: ");
                while (getchar() != '\n'); // ������� ������ �����
            }
        }
    }

    sortMatrixRows(matrix, numRows, numCols);

    printf("��������������� �������:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}