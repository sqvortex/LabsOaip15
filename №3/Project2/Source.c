//В массиве из n элементов циклически сдвинуть все четные элементы на k влево. Нечетные оставить на своих местах (например, k=2: 0,1,2,3,4,5,6,7 =>4,1,6,3,0,5,2,7)


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void EvenElements(int arr[], int elQuantity, int k) {
    k = k % elQuantity;  // Убедимся, что k не больше кол-ва элементов

    for (int i = 0; i < elQuantity; i++) 
    {
        if (arr[i] % 2 == 0) // Проверяем, является ли элемент четным
        { 
            int newIndex = (i - k + elQuantity) % elQuantity;  // Вычисляем новый индекс после сдвига
            int temp = arr[i];

            arr[i] = arr[newIndex];
            arr[newIndex] = temp;
     
        }
    }
}

int main()
{

    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    int elQuantity, i, arr[100], k;
    int choice;

    printf("Количество элементов массива (20 достаточно):");
    scanf_s("%d", &elQuantity);
   
  
    printf("Если хотите инициализировать массив случайными значениями нажмите '1', в ином случае любой дугой символ:\n");
    scanf_s("%d", &choice);
    
    
    if (choice == 1)
    {
        for (int i = 0; i < elQuantity; i++)
        {
            arr[i] = -50 + rand() % 100;
            printf(" %d", arr[i]);
            printf("\n");
        }

    }

    else 
    {
        printf("Введите элементы массива:\n");
     

        for (i = 0; i < elQuantity; i++)
        {
            scanf_s("%d", &arr[i]);

        }
    }
    printf("Введите значение k: ");
    scanf_s("%d", &k);
    printf("Исходный массив: ");

    for (int i = 0; i < elQuantity; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    EvenElements(arr, elQuantity, k);

    printf("Массив после циклического сдвига четных элементов на k: ");
    for (int i = 0; i < elQuantity; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}