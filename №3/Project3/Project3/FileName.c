#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

const int NumDigits = 30;

void readNum(char buffer[]) {
    printf("Введите число\n");
    int success = 1;
    while (1) {
        scanf("%30s", buffer);  
        int strLength = strlen(buffer);
        printf("strLength = %d\n", strLength);
        if (strLength == 30) {
            for (int i = 0; buffer[i]; i++) {
                if ((buffer[i] < '0') || ('9' < buffer[i])) {
                    printf("Ошибка, введён неверный символ, введите 30-значное число\n");
                    success = 0;
                    break;
                }
                buffer[i] -= '0';
            }
            if (success == 1) {
                return;
            }
        }
        else {
            printf("Ошибка, неверная длина, введите 30-значное число\n");
        }
    }
}

void add(char arr1[], char arr2[], char arrResult[]) {
    int carry = 0;
    for (int i = NumDigits - 1; i >= 0; i--) {
        arrResult[i] = arr1[i] + arr2[i] + carry;
        carry = arrResult[i] / 10;
        arrResult[i] %= 10;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    char num1[31], num2[31], sum[31];
    readNum(num1);
    readNum(num2);

    add(num1, num2, sum);

    printf("Сумма: ");
    for (int i = 0; i < NumDigits; i++) {
        printf("%d", sum[i]);  
    }

    printf("\n");

    char* ptr = sum;
    while (*ptr == '0' && *(ptr + 1) != 0) {
        ++ptr;
    }

    printf("%s\n", ptr);

    return 0;
}
