//� ������� �� n ��������� ������� ������ k-�� ������� (k=2: 012345 => 024)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("chcp 1251 > nul"); 

    int n, k; 
    int array[100]; 

    printf("�������� ������ ����� ��������� �������:\n");
    printf("1. ������ �������\n");
    printf("2. ��������� ��������\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("������� ������ �������: ");
        scanf("%d", &n);

        if (n <= 0 || n > 100)
        {
            printf("������������ ������ �������\n");
            return 1;
        }

        printf("������� �������� �������:\n");
        for (int i = 0; i < n; i++)
        {
            printf("������� %d: ", i + 1);
            scanf("%d", &array[i]);
        }
    }
    else if (choice == 2)
    {
        printf("������� ������ �������: ");
        scanf("%d", &n);

        if (n <= 0 || n > 100)
        {
            printf("������������ ������ �������\n");
            return 1;
        }

        srand((unsigned int)time(NULL)); // ������������� ���������� ��������� �����

        for (int i = 0; i < n; i++)
        {
            array[i] = -50 + rand() % 100; // ���������� ������� ���������� ����������
            printf("%3d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("������������ �����\n");
        return 1;
    }

    printf("������� �������� k: ");
    scanf("%d", &k);

    if (k < 1)
    {
        printf("�������� k ������ ���� ������ ��� ����� 1\n");
        return 1;
    }

    int newSize = 0; // ����� ������ ������� ����� �������� ���������

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % k != 0) // ���������� ��������� �� ������� k
        {
            array[newSize] = array[i];
            newSize++;
        }
    }

    printf("������ ����� �������� ������� %d-�� ��������:\n", k);
    for (int i = 0; i < newSize; i++)
    {
        printf("%3d ", array[i]);
    }

    return 0;
}
