/*��������� ������ ������������ ������� � ����������. ������� �� ������� ��� ���������� �����.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fillArray(int** array, int* size) {
    printf("������� ������ �������: ");
    if (scanf_s("%d", size) != 1 || *size <= 0) {
        printf("������ ����� ������� �������\n");
        exit(EXIT_FAILURE);
    }

    *array = (int*)malloc(*size * sizeof(int));

    if (*array == NULL) {
        printf("������ ��������� ������\n");
        exit(EXIT_FAILURE);
    }

    printf("������� ����������� ����� ��� ���������� �������:\n");
    for (int i = 0; i < *size; ++i) {
        printf("������� %d: ", i + 1);
        if (scanf_s("%d", &(*array)[i]) != 1) {
            printf("������ ����� �������� �������\n");
            exit(EXIT_FAILURE);
        }
    }
}

void removeTwoDigitNumbers(int** array, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*array)[i] < 10 || (*array)[i] > 99) {
            // ���� ����� �� ����������, ��������� ��� � �������
            (*array)[newSize++] = (*array)[i];
        }
    }

    if (newSize < *size) {
        // ���� ���� ������� ��������, �������������� ������
        *array = (int*)realloc(*array, newSize * sizeof(int));

        if (*array == NULL) {
            printf("������ ������������� ������\n");
            exit(EXIT_FAILURE);
        }

        *size = newSize;
        printf("���������� ����� ������� �� �������.\n");
    }
    else {
        printf("� ������� ��� ���������� �����.\n");
    }
}

void printArray(int* array, int size) {
    printf("������ ����� �������� ���������� �����:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void freeArray(int* array) {
    free(array);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int* array = NULL;
    int size;

    fillArray(&array, &size);
    removeTwoDigitNumbers(&array, &size);
    printArray(array, size);
    freeArray(array);

    return 0;
}