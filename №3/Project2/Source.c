//� ������� �� n ��������� ���������� �������� ��� ������ �������� �� k �����. �������� �������� �� ����� ������ (��������, k=2: 0,1,2,3,4,5,6,7 =>4,1,6,3,0,5,2,7)


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void EvenElements(int arr[], int elQuantity, int k) {
    k = k % elQuantity;  // ��������, ��� k �� ������ ���-�� ���������

    for (int i = 0; i < elQuantity; i++) 
    {
        if (arr[i] % 2 == 0) // ���������, �������� �� ������� ������
        { 
            int newIndex = (i - k + elQuantity) % elQuantity;  // ��������� ����� ������ ����� ������
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

    printf("���������� ��������� ������� (20 ����������):");
    scanf_s("%d", &elQuantity);
   
  
    printf("���� ������ ���������������� ������ ���������� ���������� ������� '1', � ���� ������ ����� ����� ������:\n");
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
        printf("������� �������� �������:\n");
     

        for (i = 0; i < elQuantity; i++)
        {
            scanf_s("%d", &arr[i]);

        }
    }
    printf("������� �������� k: ");
    scanf_s("%d", &k);
    printf("�������� ������: ");

    for (int i = 0; i < elQuantity; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    EvenElements(arr, elQuantity, k);

    printf("������ ����� ������������ ������ ������ ��������� �� k: ");
    for (int i = 0; i < elQuantity; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}