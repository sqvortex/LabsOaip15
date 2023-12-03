﻿//Дано натуральное число  n. Выяснить, можно ли представить n! = 1 ⋅ 2 ⋅ 3 ⋅...⋅ n в виде произведения трёх последовательных целых чисел.

#include <stdio.h>  
#include <locale.h>
#include <math.h>
int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    printf("Введите натуральное число: ");
    scanf_s("%d", &n);

    if (isProductOfConsecutiveIntegers(n)) {
        printf("%d! может быть выражено как произведение трех последовательных целых чисел.\n", n);
    }
    else {
        printf("%d! не может быть выражено как произведение трех последовательных целых чисел.\n", n);
    }

    return 0;
}
int isProductOfConsecutiveIntegers(int n) {   // is Product Of Consecutive Integers - является произведением последовательных целых чисел
    if (n < 3) {    // Если n меньше 3  - выразить как произведение невозможно!
        return 0;
    }

    for (int i = 1; i <= n - 2; i++) {
        if (i * (i + 1) * (i + 2) == n) {
            return 1;  // Найдены три последовательных целых числа, которые умножаются на n!.
        }
    }

    return 0; // Не найдено трех последовательных целых чисел, которые умножаются на n!.
}
