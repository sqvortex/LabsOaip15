//Ввести длины ребер куба. Найти объем куба и площадь его боковой поверхности. Результат вывести с точностью до трех знаков после запятой.

#include <stdio.h> //Подкл. библиотеки
#include <locale.h>  //Подкл. библиотеки

main() {           //Тело программы
	setlocale(LC_ALL, "Rus");
	float lenght;

	printf("Введите длину куба:"); //вывод текста на экран
	scanf_s("%f", &lenght);
	if (lenght <= 0) {
		printf("Введите коректное значение!\n");
	}
	else {
		float square;
		square = (lenght * lenght) * 6;
		printf("Площадь боковой поверхности = %.3f*%.3f*6 = %.3f\n", lenght, lenght, square); //вывод площади бок. повехности куба
		float volume;
		volume = lenght * lenght * lenght;
		printf("Объём куба = %.3f*%.3f*.%.3f=%.3f\n", lenght, lenght, lenght, volume);
		scanf_s("%f", &volume);
	}
}
