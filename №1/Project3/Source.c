
// Составьте алгоритм решения неравенства ax2+bx+c<0.
#include <stdio.h>
#include <locale.h>  //Подкл. библиотеки для русского языка
#include <math.h> //Подкл. бибилиотеку, которая отвечает за математику.

main() {
	setlocale(LC_ALL, "Rus"); //Русский язык
	float a, b, c, D, x1, x2, S;
	printf("Введите a : ");
	scanf_s("%f", &a);
	printf("Введите b : ");
	scanf_s("%f", &b);
	printf("Введите c : ");
	scanf_s("%f", &c);
	D = (b * b) - (4 * a * c);
	printf("Дискриминант = (%f*%f)-(4*%f*%f) = %f\n", b, b, a, c, D);
	S = sqrt(D);
	printf("Корень дискриминанта равен = %f\n", S);

	if (D == 0 && a > 0)
	{
		printf("Нет решений!");
	}
	if (D == 0 && a < 0)
	{
		x1 = (-b + S) / (2 * a);
		printf("Решение: (-Бесконечность; +Бесконечность)U{x1} = %f", x1);
	}
	if (D > 0 && a > 0)
	{
		x1 = (-b + S) / (2 * a);
		x2 = (-b - S) / (2 * a);
		printf("x1= %f\n", x1);
		printf("x2= %f ", x2);
	}
	if (D > 0 && a < 0)
	{
		x1 = (-b + S) / (2 * a);
		x2 = (-b - S) / (2 * a);
		printf("x1= %f\n", x1);
		printf("x2= %f\n ", x2);
		printf("Решение: (-Бесконечность; %f)U(%f; +Бесконечность)", x1, x2);
	}
	if (D < 0 && a < 0)
	{
		printf(" Решение: Все значения!");
	}
	if (a == 0)
	{
		double x = 0;
		x = -c / b;
		printf("x= %f\n(-Бесконечность; %f)", x,x);
	}
}

