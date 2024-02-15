/*В одномерном массиве выполнить сортировку элементов кратных k расположенных
после максимального методом пузырька*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void bubbleSort(int* arr, int start, int end, int k);
int findMaxIndex(int* arr, int start, int end);
void swap(int* a, int* b);
void displayArray(int* arr, int n);
void manualInput(int* arr, int n);

int main() {
    setlocale(LC_ALL, "Rus");
    int n, k, choice;

    // Ввод размера массива
    printf("Введите размер массива: ");
    while (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода. Введите положительное целое число: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Выделение динамической памяти под массив
    int* arr = (int*)malloc(n * sizeof(int));

    // Меню для выбора ввода
    printf("Выберите способ ввода массива:\n");
    printf("1. Ввести вручную\n");
    printf("2. Инициализировать случайными значениями\n");
    printf("Ваш выбор: ");
    while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Ошибка ввода. Выберите 1 или 2: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Ввод массива
    if (choice == 1) {
        manualInput(arr, n);
    }
    else {
        // Инициализация массива случайными значениями
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 100;
        }
    }

    // Вывод исходного массива
    printf("\nИсходный массив:\n");
    displayArray(arr, n);

    // Ввод k
    printf("\nВведите значение k: ");
    while (scanf_s("%d", &k) != 1) {
        printf("Ошибка ввода. Введите целое число: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Находим индекс максимального элемента
    int maxIndex = findMaxIndex(arr, 0, n - 1);

    // Сортировка элементов кратных k, расположенных после максимального
    bubbleSort(arr, maxIndex + 1, n - 1, k);

    // Вывод отсортированного массива
    printf("\nОтсортированный массив:\n");
    displayArray(arr, n);

    // Вывод элементов кратных k, расположенных после максимального элемента
    printf("\nЭлементы кратные %d, расположенные после максимального элемента:\n", k);
    for (int i = maxIndex + 1; i < n; ++i) {
        if (arr[i] % k == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    // Освобождение выделенной памяти
    free(arr);

    return 0;
}
//Сортировка
void bubbleSort(int* arr, int start, int end, int k) {
    for (int i = end; i >= start; --i) {
        for (int j = start; j < i; ++j) {
            for (int m = j; m <= end; m++) {
                if (arr[j] % k == 0 && arr[j] > arr[m] && arr[m] % k == 0) {
                    swap(&arr[j], &arr[m]);
                    break;
                }
            }
        }
    }
}
//Нахождение максимального элемента (Его позицию)
int findMaxIndex(int* arr, int start, int end) {
    // Инициализация индекса максимального элемента
    int maxIndex = start;
    // Поиск максимального элемента в диапазоне
    for (int i = start + 1; i <= end; ++i) {
        // Если текущий элемент больше максимального, обновляем индекс максимального элемента
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    // Возвращаем индекс максимального элемента
    return maxIndex;
}
//Свап для пузырька
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Вывод массива
void displayArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//Заполнение массива
void manualInput(int* arr, int n) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; ++i) {
        while (scanf_s("%d", &arr[i]) != 1) {
            printf("Ошибка ввода. Введите целое число: ");
            while (getchar() != '\n'); // Очистка буфера ввода
        }
    }
}
