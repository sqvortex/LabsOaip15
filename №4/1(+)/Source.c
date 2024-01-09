#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

// Функция для проверки, является ли массив магическим квадратом
int isMagicSquare(int arr[MAX_SIZE][MAX_SIZE], int n) {
    // Вычисление суммы для первой строки
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += arr[0][j];
    }

    // Проверка суммы по строкам
    for (int i = 1; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += arr[i][j];
        }
        if (rowSum != sum) {
            return 0; // Не является магическим квадратом
        }
    }

    // Проверка суммы по столбцам
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += arr[i][j];
        }
        if (colSum != sum) {
            return 0; // Не является магическим квадратом
        }
    }

    // Проверка суммы по главной диагонали
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        mainDiagonalSum += arr[i][i];
    }
    if (mainDiagonalSum != sum) {
        return 0; // Не является магическим квадратом
    }

    // Проверка суммы по побочной диагонали
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        secondaryDiagonalSum += arr[i][n - i - 1];
    }
    if (secondaryDiagonalSum != sum) {
        return 0; // Не является магическим квадратом
    }

    return 1; // Является магическим квадратом
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;

    // Ввод размеров массива с клавиатуры
    printf("Введите размер квадратной матрицы (от 1 до %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Неверный ввод! Размер матрицы должен быть от 1 до %d.\n", MAX_SIZE);
        return 1;
    }

    int array[MAX_SIZE][MAX_SIZE];

    // Ввод элементов массива с клавиатуры
    printf("Введите элементы матрицы поочередно:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%d", &array[i][j]);
        }
    }

    // Вывод итоговой матрицы
    printf("Итоговая матрица:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // Проверка является ли массив магическим квадратом
    if (isMagicSquare(array, n)) {
        printf("Эта матрица является магическим квадратом!\n");
    }
    else {
        printf("Эта матрица не является магическим квадратом.\n");
    }

    return 0;
}
