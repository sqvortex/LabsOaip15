/* ��������� ������, ���������� ������ ����� ����� � ��������, ���������� ���������� ���������,
 ���� ����� �����, ���������� � ������ ������, ������ ������� � ������ �� ���� ������� ����������,
 ����� ������ � ���� �� �����.
 ����������, �������� �� ������ ������ � �� n ����� � n �������� ���������� ���������.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX_SIZE 100

// ������� ��� ��������, �������� �� ������ ���������� ���������
int isMagicSquare(int arr[MAX_SIZE][MAX_SIZE], int elQuantity) {
    // ���������� ����� ��� ������ ������
    int sum = 0;
    for (int j = 0; j < elQuantity; ++j) {
        sum += arr[0][j];
    }

    // �������� ����� �� �������
    for (int i = 1; i < elQuantity; ++i) {
        int rowSum = 0;
        for (int j = 0; j < elQuantity; ++j) {
            rowSum += arr[i][j];
        }
        if (rowSum != sum) {
            return 0; // �� �������� ���������� ���������
        }
    }

    // �������� ����� �� ��������
    for (int j = 0; j < elQuantity; ++j) {
        int colSum = 0;
        for (int i = 0; i < elQuantity; ++i) {
            colSum += arr[i][j];
        }
        if (colSum != sum) {
            return 0; // �� �������� ���������� ���������
        }
    }

    // �������� ����� �� ������� ���������
    int mainDiagonalSum = 0;
    for (int i = 0; i < elQuantity; ++i) {
        mainDiagonalSum += arr[i][i];
    }
    if (mainDiagonalSum != sum) {
        return 0; // �� �������� ���������� ���������
    }

    // �������� ����� �� �������� ���������
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < elQuantity; ++i) {
        secondaryDiagonalSum += arr[i][elQuantity - i - 1];
    }
    if (secondaryDiagonalSum != sum) {
        return 0; // �� �������� ���������� ���������
    }

    return 1; // �������� ���������� ���������
}

int main() {
    setlocale(LC_ALL, "Rus");
    int elQuantity;

    // ���� �������� ������� � ����������
    printf("������� ������ ������� (<= %d): ", MAX_SIZE);
    scanf_s("%d", &elQuantity);

    if (elQuantity > MAX_SIZE) {
        printf("�������� ����!\n");
        return 1;
    }

    int array[MAX_SIZE][MAX_SIZE];

    // ���� ��������� ������� � ����������
    printf("������� �������� �������:\n");
    for (int i = 0; i < elQuantity; ++i) {
        for (int j = 0; j < elQuantity; ++j) {
            scanf_s("%d", &array[i][j]);
        }
    }

    // �������� �������� �� ������ ���������� ���������
    if (isMagicSquare(array, elQuantity)) {
        printf("��� ������� �������� ���������� ���������!.\n");
    }
    else {
        printf("��� ������� �� �������� ���������� ���������.\n");
    }

    return 0;
}
