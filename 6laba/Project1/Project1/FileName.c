/*� ���������� ������� ��������� ���������� ��������� ������� k �������������
����� ������������� ������� ��������*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void bubbleSort(int* arr, int start, int end, int k);
int findMaxIndex(int* arr, int start, int end);
void swap(int* a, int* b);
void displayArray(int* arr, int n);
void manualInput(int* arr, int n);

int main() {
    setlocale(LC_ALL, "Rus");
    int n, k, choice;

    // ���� ������� �������
    printf("������� ������ �������: ");
    while (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("������ �����. ������� ������������� ����� �����: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ��������� ������������ ������ ��� ������
    int* arr = (int*)malloc(n * sizeof(int));

    // ���� ��� ������ �����
    printf("�������� ������ ����� �������:\n");
    printf("1. ������ �������\n");
    printf("2. ���������������� ���������� ����������\n");
    printf("��� �����: ");
    while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("������ �����. �������� 1 ��� 2: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ���� �������
    if (choice == 1) {
        manualInput(arr, n);
    }
    else {
        // ������������� ������� ���������� ����������
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 100;
        }
    }

    // ����� ��������� �������
    printf("\n�������� ������:\n");
    displayArray(arr, n);

    // ���� k
    printf("\n������� �������� k: ");
    while (scanf_s("%d", &k) != 1) {
        printf("������ �����. ������� ����� �����: ");
        while (getchar() != '\n'); // ������� ������ �����
    }

    // ������� ������ ������������� ��������
    int maxIndex = findMaxIndex(arr, 0, n - 1);

    // ���������� ��������� ������� k, ������������� ����� �������������
    bubbleSort(arr, maxIndex + 1, n - 1, k);

    // ����� ���������������� �������
    printf("\n��������������� ������:\n");
    displayArray(arr, n);

    // ����� ��������� ������� k, ������������� ����� ������������� ��������
    printf("\n�������� ������� %d, ������������� ����� ������������� ��������:\n", k);
    for (int i = maxIndex + 1; i < n; ++i) {
        if (arr[i] % k == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    // ������������ ���������� ������
    free(arr);

    return 0;
}
//����������
void bubbleSort(int* arr, int start, int end, int k) {
    for (int i = end; i >= start; --i) {
        for (int j = start; j < i; ++j) {
            for (int m = j; m <= end; m++) {
                if (arr[j] % k == 0 && arr[j] > arr[m] && arr[m] % k == 0) {
                    swap(&arr[j], &arr[m]);
                    break;
                }
            }
        }
    }
}
//���������� ������������� �������� (��� �������)
int findMaxIndex(int* arr, int start, int end) {
    // ������������� ������� ������������� ��������
    int maxIndex = start;
    // ����� ������������� �������� � ���������
    for (int i = start + 1; i <= end; ++i) {
        // ���� ������� ������� ������ �������������, ��������� ������ ������������� ��������
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    // ���������� ������ ������������� ��������
    return maxIndex;
}
//���� ��� ��������
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//����� �������
void displayArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//���������� �������
void manualInput(int* arr, int n) {
    printf("������� �������� �������:\n");
    for (int i = 0; i < n; ++i) {
        while (scanf_s("%d", &arr[i]) != 1) {
            printf("������ �����. ������� ����� �����: ");
            while (getchar() != '\n'); // ������� ������ �����
        }
    }
}
