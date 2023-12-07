/*Заполнить массив натуральными числами с клавиатуры. Удалить из массива все двузначные числа.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fillArray(int** array, int* size) {
    printf("Введите размер массива: ");
    if (scanf_s("%d", size) != 1 || *size <= 0) {
        printf("Ошибка ввода размера массива\n");
        exit(EXIT_FAILURE);
    }

    *array = (int*)malloc(*size * sizeof(int));

    if (*array == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    printf("Введите натуральные числа для заполнения массива:\n");
    for (int i = 0; i < *size; ++i) {
        printf("Элемент %d: ", i + 1);
        if (scanf_s("%d", &(*array)[i]) != 1) {
            printf("Ошибка ввода элемента массива\n");
            exit(EXIT_FAILURE);
        }
    }
}

void removeTwoDigitNumbers(int** array, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*array)[i] < 10 || (*array)[i] > 99) {
            // Если число не двузначное, оставляем его в массиве
            (*array)[newSize++] = (*array)[i];
        }
    }

    if (newSize < *size) {
        // Если были удалены элементы, переаллоцируем память
        *array = (int*)realloc(*array, newSize * sizeof(int));

        if (*array == NULL) {
            printf("Ошибка перевыделения памяти\n");
            exit(EXIT_FAILURE);
        }

        *size = newSize;
        printf("Двузначные числа удалены из массива.\n");
    }
    else {
        printf("В массиве нет двузначных чисел.\n");
    }
}

void printArray(int* array, int size) {
    printf("Массив после удаления двузначных чисел:\n");
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