/* Двумерный массив, содержащий равное число строк и столбцов, называется магическим квадратом,
 если суммы чисел, записанных в каждой строке, каждом столбце и каждой из двух больших диагоналей,
 равны одному и тому же числу.
 Определить, является ли данный массив А из n строк и n столбцов магическим квадратом.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX_SIZE 100

// Функция для проверки, является ли массив магическим квадратом
int isMagicSquare(int arr[MAX_SIZE][MAX_SIZE], int elQuantity) {
    // Вычисление суммы для первой строки
    int sum = 0;
    for (int j = 0; j < elQuantity; ++j) {
        sum += arr[0][j];
    }

    // Проверка суммы по строкам
    for (int i = 1; i < elQuantity; ++i) {
        int rowSum = 0;
        for (int j = 0; j < elQuantity; ++j) {
            rowSum += arr[i][j];
        }
        if (rowSum != sum) {
            return 0; // Не является магическим квадратом
        }
    }

    // Проверка суммы по столбцам
    for (int j = 0; j < elQuantity; ++j) {
        int colSum = 0;
        for (int i = 0; i < elQuantity; ++i) {
            colSum += arr[i][j];
        }
        if (colSum != sum) {
            return 0; // Не является магическим квадратом
        }
    }

    // Проверка суммы по главной диагонали
    int mainDiagonalSum = 0;
    for (int i = 0; i < elQuantity; ++i) {
        mainDiagonalSum += arr[i][i];
    }
    if (mainDiagonalSum != sum) {
        return 0; // Не является магическим квадратом
    }

    // Проверка суммы по побочной диагонали
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < elQuantity; ++i) {
        secondaryDiagonalSum += arr[i][elQuantity - i - 1];
    }
    if (secondaryDiagonalSum != sum) {
        return 0; // Не является магическим квадратом
    }

    return 1; // Является магическим квадратом
}

int main() {
    setlocale(LC_ALL, "Rus");
    int elQuantity;

    // Ввод размеров массива с клавиатуры
    printf("Введите размер матрицы (<= %d): ", MAX_SIZE);
    scanf_s("%d", &elQuantity);

    if (elQuantity > MAX_SIZE) {
        printf("Неверный ввод!\n");
        return 1;
    }

    int array[MAX_SIZE][MAX_SIZE];

    // Ввод элементов массива с клавиатуры
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < elQuantity; ++i) {
        for (int j = 0; j < elQuantity; ++j) {
            scanf_s("%d", &array[i][j]);
        }
    }

    // Проверка является ли массив магическим квадратом
    if (isMagicSquare(array, elQuantity)) {
        printf("Эта матрица является магическим квадратом!.\n");
    }
    else {
        printf("Эта матрица не является магическим квадратом.\n");
    }

    return 0;
}
