#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������� ��� ����� ������ � ������������ ���������� ������
char* inputString() {
    char* str;   // ��������� �� ������, ������� �� ����� �������
    int ch, size = 10, len = 0;  // ���������� ��� �������, ������� ������ � ������� ����� ������
    // �������� ��������� ������ ��� ������
    str = realloc(NULL, sizeof(char) * size);
    // �������� ��������� ��������� ������
    if (!str) return str;
    // ������ �������� � ����������, ���� �� ��������� ����� ����� (EOF) ��� ������ ����� ������
    while (EOF != (ch = fgetc(stdin)) && ch != '\n') {
        str[len++] = ch;
        // ���� ��������� ����� �������, ����������� ������ ������
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += 16));
            // �������� ��������� ��������� ������ ����� ����������
            if (!str) return str;
        }
    }
    // ��������� ����������� ������ ���� � ������
    str[len++] = '\0';
    // ���������������� ������, ����� ������ ������ �������� �����
    return realloc(str, sizeof(char) * len);
}

// ������� ����������� ������� �����
int isWordBoundary(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\0';
}

// ������� �������� ���������� ���������� ����� � ������
int countOccurrences(char* line, char* word) {
    int count = 0, wordLen = 0, lineLen = 0, i = 0, j = 0;
    while (word[wordLen] != '\0') {
        wordLen++;
    }
    while (line[lineLen] != '\0') {
        lineLen++;
    }
    for (i = 0; i <= lineLen - wordLen; i++) {
        if ((i == 0 || isWordBoundary(line[i - 1])) && isWordBoundary(line[i + wordLen])) {
            for (j = 0; j < wordLen; j++) {
                if (line[i + j] != word[j])
                    break;
            }
            if (j == wordLen) {
                count++;
                i += wordLen - 1;
            }
        }
    }
    return count;
}

// ������� ��������, �������� �� ������ S ���������� ������ S0
int isSubstring(char* S, char* S0) {
    int SLen = 0, S0Len = 0, i = 0, j = 0;
    while (S[SLen] != '\0') {
        SLen++;
    }
    while (S0[S0Len] != '\0') {
        S0Len++;
    }
    for (i = 0; i <= SLen - S0Len; i++) {
        for (j = 0; j < S0Len; j++) {
            if (S[i + j] != S0[j])
                break;
        }
        if (j == S0Len)
            return 1;
    }
    return 0;
}

// ������� ���������� ������ ������
void task1() {
    printf("������� ������: ");
    char* line = inputString();
    printf("������� �����: ");
    char* word = inputString();
    printf("����� '%s' ����������� %d ���.\n", word, countOccurrences(line, word));
    free(line);
    free(word);
}

// ������� ���������� ������ ������
void task2() {
    printf("������� ������ S: ");
    char* S = inputString();
    printf("������� ������ S0: ");
    char* S0 = inputString();
    if (isSubstring(S, S0)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    free(S);
    free(S0);
}

int main(void) {
    system("chcp 1251 > nul");
    int choice;
    void(*task)() = NULL;

Start:
    printf("������� ����� ������ (1 ��� 2): ");
    scanf("%d", &choice);
    getchar(); // ������� ������ ����� ������ ����� ����� �����

    if (choice == 1) {
        task = task1;
        task();
    }
    else if (choice == 2) {
        task = task2;
        task();
    }
    else {
        printf("�������� ����� ������.\n");
        goto Start;
    }

    return 0;
}
