//������������� ������� ������� ������ ����� �� �������� ����� ������������� ����� � ������ ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������� ��� ���������� ����� ������ �������� ����� � ������
int longestWordLength(char* str) {
    int maxLen = 0, currentLen = 0; // ������������ �����; ����� �������� ����� � ������
    while (*str) {
        // ���������� ����� �����
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            if (currentLen > maxLen) {
                // ��������� ������������ �����, ���� ������� ����� ������ ���������� ������������
                maxLen = currentLen;
            }
            currentLen = 0; // ���������� ������� ����� ��� ���������� �����
        }
        else {
            currentLen++; // ����������� ����� �������� �����
        }

        str++; // ��������� � ���������� ������� � ������
    }
    if (currentLen > maxLen)
    {
        maxLen = currentLen; // ��������� ��������� ����� ����� ������������ ������� ������
    }
    return maxLen; // ���������� ����� ������ �������� ����� � ������
}

// ������� ���������� ������� ����� ������� �������
void insertionSort(char** array, int n) {
    for (int i = 1; i < n; i++) {
        char* temp = array[i];  // ������� �������, ������� ����� �������� � ��������������� �����
        int j = i - 1;

        /* ���� �� ���������� ������ ������� � ����� ������������� ����� � ��������������� ����� ������
           ����� ������������� ����� �������� ��������, �������� �������� ������.*/
        while (j >= 0 && longestWordLength(array[j]) < longestWordLength(temp)) {
            array[j + 1] = array[j];
            j--;
        }

        // ��������� ������� ������� �� ���������� ����� � ��������������� �����.
        array[j + 1] = temp;
    }
}

int main(int argc, char** argv) {
    system("chcp 1251 > nul");
    
    // argc - ���������� ��������� � ������� argv (��������� ��������� ������)
    // argv - ������ �����, ��� ������ ������ - ���� �� ���������� ��������� ������

   
    if (argc > 1) {
        
        insertionSort(argv + 1, argc - 1);

        printf("��������������� ������ �����:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }
    else {
        printf("������ �� ���� �������������.\n");
    }

    return 0;
}