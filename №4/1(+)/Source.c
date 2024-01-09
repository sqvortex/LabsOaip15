#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

// ������� ��� ��������, �������� �� ������ ���������� ���������
int isMagicSquare(int arr[MAX_SIZE][MAX_SIZE], int n) {
    // ���������� ����� ��� ������ ������
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += arr[0][j];
    }

    // �������� ����� �� �������
    for (int i = 1; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += arr[i][j];
        }
        if (rowSum != sum) {
            return 0; // �� �������� ���������� ���������
        }
    }

    // �������� ����� �� ��������
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += arr[i][j];
        }
        if (colSum != sum) {
            return 0; // �� �������� ���������� ���������
        }
    }

    // �������� ����� �� ������� ���������
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        mainDiagonalSum += arr[i][i];
    }
    if (mainDiagonalSum != sum) {
        return 0; // �� �������� ���������� ���������
    }

    // �������� ����� �� �������� ���������
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        secondaryDiagonalSum += arr[i][n - i - 1];
    }
    if (secondaryDiagonalSum != sum) {
        return 0; // �� �������� ���������� ���������
    }

    return 1; // �������� ���������� ���������
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;

    // ���� �������� ������� � ����������
    printf("������� ������ ���������� ������� (�� 1 �� %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("�������� ����! ������ ������� ������ ���� �� 1 �� %d.\n", MAX_SIZE);
        return 1;
    }

    int array[MAX_SIZE][MAX_SIZE];

    // ���� ��������� ������� � ����������
    printf("������� �������� ������� ����������:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%d", &array[i][j]);
        }
    }

    // ����� �������� �������
    printf("�������� �������:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // �������� �������� �� ������ ���������� ���������
    if (isMagicSquare(array, n)) {
        printf("��� ������� �������� ���������� ���������!\n");
    }
    else {
        printf("��� ������� �� �������� ���������� ���������.\n");
    }

    return 0;
}
