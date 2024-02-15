#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Функция для ввода строки с динамическим выделением памяти
char* inputString() {
    char* str;   // Указатель на строку, которую мы будем вводить
    int ch, size = 10, len = 0;  // Переменные для символа, размера строки и текущей длины строки
    // Выделяем начальную память под строку
    str = realloc(NULL, sizeof(char) * size);
    // Проверка успешного выделения памяти
    if (!str) return str;
    // Чтение символов с клавиатуры, пока не достигнут конец файла (EOF) или символ новой строки
    while (EOF != (ch = fgetc(stdin)) && ch != '\n') {
        str[len++] = ch;
        // Если достигнут лимит размера, увеличиваем размер строки
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += 16));
            // Проверка успешного выделения памяти после увеличения
            if (!str) return str;
        }
    }
    // Добавляем завершающий символ нуля к строке
    str[len++] = '\0';
    // Перераспределяем память, чтобы убрать лишний ненужный запас
    return realloc(str, sizeof(char) * len);
}

// Функция определения границы слова
int isWordBoundary(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\0';
}

// Функция подсчета повторений введенного слова в строке
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

// Функция проверки, является ли строка S подстрокой строки S0
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

// Функция выполнения первой задачи
void task1() {
    printf("Введите строку: ");
    char* line = inputString();
    printf("Введите слово: ");
    char* word = inputString();
    printf("Слово '%s' встречается %d раз.\n", word, countOccurrences(line, word));
    free(line);
    free(word);
}

// Функция выполнения второй задачи
void task2() {
    printf("Введите строку S: ");
    char* S = inputString();
    printf("Введите строку S0: ");
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
    printf("Введите номер задачи (1 или 2): ");
    scanf("%d", &choice);
    getchar(); // Удаляем символ новой строки после ввода числа

    if (choice == 1) {
        task = task1;
        task();
    }
    else if (choice == 2) {
        task = task2;
        task();
    }
    else {
        printf("Неверный номер задачи.\n");
        goto Start;
    }

    return 0;
}
