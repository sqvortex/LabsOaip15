/* � ���������� �������, ��������� �� n ������������ ���������, ���������:
- ���������� ��������� �������, ������ 0;
- ����� ��������� �������, ������������� ����� ������������ ��������.*/

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

    printf("���������� ��������� �������:");
    scanf("%d", &elQuantity);

    if (elQuantity <= 0)     //��������
    {
        printf("�������� ����!");
        return 1;

    }


    printf("���� ������ ���������������� ������ ���������� ���������� ������� '1', � ���� ������ ����� ����� ������:");
    scanf("%d", &choice);


    if (choice == 1) //��� ������ "1" ���������� �������������
    {
        for (int i = 0; i < elQuantity; i++)
        {
            array[i] = -50 + rand() % 101;
            printf(" %d", array[i]);
            printf("\n");
        }

    }

    else  //������ ���� ���������
    {
        printf("������� �������� �������:\n");
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
    printf("���������� ��������� ������ ���� = %d\n", elEqualZero);


    elMin = array[0];  //����������� �������
    int minIndex = 0; //����� ������������ �����
    for (int i = 1; i < elQuantity; i++)
    {

        if (array[i] < elMin)
        {

            elMin = array[i];
            minIndex = i; //���������� �������
        }
    }
    printf("����������� ������� = %d\n", elMin);

    int sum = 0;
    for (i = minIndex + 1; i < elQuantity; i++)
    {
        sum += array[i];
    }
    printf("����� ��������� ����� ������������ ��������: %d\n", sum);
    return 0;
}