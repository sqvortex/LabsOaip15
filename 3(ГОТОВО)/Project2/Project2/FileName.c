//В массиве из n элементов удалить каждый k-ый элемент (k=2: 012345 => 024)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("chcp 1251 > nul"); 

    int n, k; 
    int array[100]; 

    printf("Выберите способ ввода элементов массива:\n");
    printf("1. Ввести вручную\n");
    printf("2. Случайные значения\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Введите размер массива: ");
        scanf("%d", &n);

        if (n <= 0 || n > 100)
        {
            printf("Недопустимый размер массива\n");
            return 1;
        }

        printf("Введите элементы массива:\n");
        for (int i = 0; i < n; i++)
        {
            printf("Элемент %d: ", i + 1);
            scanf("%d", &array[i]);
        }
    }
    else if (choice == 2)
    {
        printf("Введите размер массива: ");
        scanf("%d", &n);

        if (n <= 0 || n > 100)
        {
            printf("Недопустимый размер массива\n");
            return 1;
        }

        srand((unsigned int)time(NULL)); // Инициализация генератора случайных чисел

        for (int i = 0; i < n; i++)
        {
            array[i] = -50 + rand() % 100; // Заполнение массива случайными значениями
            printf("%3d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Некорректный выбор\n");
        return 1;
    }

    printf("Введите значение k: ");
    scanf("%d", &k);

    if (k < 1)
    {
        printf("Значение k должно быть больше или равно 1\n");
        return 1;
    }

    int newSize = 0; // Новый размер массива после удаления элементов

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % k != 0) // Сортировка элементов не кратных k
        {
            array[newSize] = array[i];
            newSize++;
        }
    }

    printf("Массив после удаления каждого %d-го элемента:\n", k);
    for (int i = 0; i < newSize; i++)
    {
        printf("%3d ", array[i]);
    }

    return 0;
}
