/*В матрице размером NxM выполнить сортировку строк по возрастанию
суммы положительных элементов методом Шелла*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция сортировки Шелла
void shellSort(int** array, int* sums, int size) {
    int gap, i, j, temp;

    // Начинаем с большего шага, постепенно уменьшая его до 1
    for (gap = size / 2; gap > 0; gap /= 2) {
        // Проходим по элементам, начиная с gap-ого элемента
        for (i = gap; i < size; i++) {
            // Сохраняем текущую сумму и соответствующую строку
            temp = sums[i];
            int* tempRow = array[i];

            // Перемещаем элементы влево, пока не находим правильную позицию для текущего элемента
            for (j = i; j >= gap && sums[j - gap] > temp; j -= gap) {
                sums[j] = sums[j - gap];
                array[j] = array[j - gap];
            }

            // Вставляем текущий элемент на правильное место
            sums[j] = temp;
            array[j] = tempRow;
        }
    }
}

// Функция сортировки строк матрицы
void sortMatrixRows(int** matrix, int numRows, int numCols) {
    int* sums = (int*)malloc(numRows * sizeof(int));

    // Вычисляем суммы положительных элементов в каждой строке
    for (int i = 0; i < numRows; i++) {
        int sum = 0;
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
        sums[i] = sum;
    }
    
    // Вызываем функцию сортировки Шелла для отсортировки строк матрицы
    shellSort(matrix, sums, numRows);

    // Освобождаем память, выделенную для массива сумм
    free(sums);
}

int main() {
    int numRows, numCols, fillOption;
    setlocale(LC_ALL, "Rus");

    // Ввод количества строк
    printf("Введите количество строк: ");
    while (scanf_s("%d", &numRows) != 1 || numRows <= 0) {
        printf("Ошибка ввода! Введите корректное количество строк: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Ввод количества столбцов
    printf("Введите количество столбцов: ");
    while (scanf_s("%d", &numCols) != 1 || numCols <= 0) {
        printf("Ошибка ввода! Введите корректное количество столбцов: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Выбор способа заполнения массива
    printf("Выберите способ заполнения массива:\n");
    printf("1. Ввод вручную\n");
    printf("2. Заполнение случайными значениями\n");

    while (scanf_s("%d", &fillOption) != 1 || (fillOption != 1 && fillOption != 2)) {
        printf("Ошибка ввода! Выберите 1 или 2: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }

    // Выделение памяти под матрицу
    int** matrix = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc(numCols * sizeof(int));
    }

    // Заполнение матрицы
    if (fillOption == 1) { // Ввод вручную
        printf("Введите элементы матрицы:\n");
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                while (scanf_s("%d", &matrix[i][j]) != 1) {
                    printf("Ошибка ввода! Введите корректный элемент матрицы: ");
                    while (getchar() != '\n'); // Очистка буфера ввода
                }
            }
        }
    }
    else if (fillOption == 2) { // Заполнение случайными значениями
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                matrix[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
            }
        }
    }

    // Сортировка строк матрицы
    sortMatrixRows(matrix, numRows, numCols);

    // Вывод отсортированной матрицы
    printf("Отсортированная матрица:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
