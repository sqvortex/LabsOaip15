#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
    int i, n, m, A, B, count = 0, max, choice, index, sum = 0, input;
    setlocale(LC_ALL, "Russian");
start:
    printf("Введите кол-во строк и столбцов матрицы\n");
    scanf_s("%d\t%d", &n, &m);
    if (n <= 0 || m <= 0) {
        printf("Некорректный ввод\n");
        goto start;
    }
    int mas[100][100];
    srand(time(0));
Start:
    printf("Выберите способ заполнения массива 1: вручную, 2: рандом\t");
    scanf_s("%d", &choice);
    if (choice == 2) {
        printf("Сгенерированный массив:\n");
        for (i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mas[i][j] = rand() % (0 + 1 - (-10)) + (-10);  // диапазон - от 0 до -10
        }
    }
    else if (choice == 1) {
        printf("Введите %d элемента(ов)", m * n);
        for (i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                scanf_s("%d", &mas[i][j]);
        }
    }
    else {
        printf("Некорректный ввод\n");
        getchar() != "\n";
        goto Start;
    }


    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            printf("[%d][%d]=%d \t", i, j, mas[i][j]);
        }
        printf("\n");
    }
    if (n % 2 == 0 && m % 2 == 0) {
        for (int k = 0; k < n / 2 - 1; k++) {
            for (int cc = 0; cc < m; cc++) {
                sum += mas[k][cc];
            }
        }
        for (i = n / 2 - 1; i <= n / 2 - 1; i++) {
            for (int j = m / 2 - i; j < m / 2 + i; j++) {
                sum += mas[i][j];
            }
        }
    }

    else if (n % 2 == 1 && m % 2 == 1) {
        for (int k = 0; k < n / 2; k++) {
            for (int cc = 0; cc < m; cc++) {
                sum += mas[k][cc];
            }
        }
        for (i = n / 2; i <= n / 2; i++) {
            for (int j = m / 2 + 1 - i; j < m / 2 + i; j++) {
                sum += mas[i][j];
            }
        }
    }
    else {
        printf("Матрица не квадратная\n");
        goto start;
    }
    printf("\nCумма элементов в первой области - %d", sum);
}