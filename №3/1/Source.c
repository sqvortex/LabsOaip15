/* В одномерном массиве, состоящем из n вещественных элементов, вычислить:
- количество элементов массива, равных 0;
- сумму элементов массива, расположенных после минимального элемента.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    int elQuantity, choice, i, array[100], elEqualZero = 0, elMin;

    printf("Количество элементов массива:");
    scanf("%d", &elQuantity);

    if (elQuantity <= 0)     //проверка
    {
        printf("Неверный ввод!");
        return 1;

    }


    printf("Если хотите инициализировать массив случайными значениями нажмите '1', в ином случае любой дугой символ:");
    scanf("%d", &choice);


    if (choice == 1) //При выборе "1" происходит инициализация
    {
        for (int i = 0; i < elQuantity; i++)
        {
            array[i] = -50 + rand() % 101;
            printf(" %d", array[i]);
            printf("\n");
        }

    }

    else  //Ручной ввод элементов
    {
        printf("Введите элементы массива:\n");
        for (i = 0; i < elQuantity; i++)
        {
            scanf("%d", &array[i]);

        }
    }


    for (int i = 0; i < elQuantity; i++)
    {
        if (array[i] == 0)
        {
            elEqualZero += 1;
        }
    }
    printf("Количество элементов равных нулю = %d\n", elEqualZero);


    elMin = array[0];  //Минимальный элемент
    int minIndex = 0; //Номер минимального числа
    for (int i = 1; i < elQuantity; i++)
    {

        if (array[i] < elMin)
        {

            elMin = array[i];
            minIndex = i; //Присвоение позиции
        }
    }
    printf("Минимальный элемент = %d\n", elMin);

    int sum = 0;
    for (i = minIndex + 1; i < elQuantity; i++)
    {
        sum += array[i];
    }
    printf("Сумма элементов после минимального элемента: %d\n", sum);
    return 0;
}