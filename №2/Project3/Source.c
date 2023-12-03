//Дано число Х в градусах. Найти значение cos X, используя разложение в ряд Тейлора.
#include <stdio.h>  
#include <math.h>   
#include <corecrt_math_defines.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Rus");
    double x;
    printf("Введите угол в градусах: ");
    scanf_s("%lf", &x);
    double cosValue = cosTaylorSeries(x);
    printf("cos(%lf) = %lf (рад)\n", x, cosValue);
    return 0;
}


int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double cosTaylorSeries(double x) {
    double radians = x * M_PI / 180.0;
    double result = 1.0;
    for (int n = 1; n <= 10; n++) {
        double term = pow(radians, 2 * n) / factorial(2 * n);
        if (n % 2 == 0) {
            result += term;
        }
        else {
            result -= term;
        }
    }
    return result;
}
