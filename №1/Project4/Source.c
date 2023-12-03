// 	Для натурального числа К напечатать фразу "мы нашли К грибов в лесу", согласовав окончание слова "гриб" с числом К. 
//fmod отсаток от деления
#include <stdio.h>
#include<locale.h>
#include <math.h>
main() {
	setlocale(LC_ALL, "Rus"); //Русский язык
	float K;
	printf("Введите количество найденных грибов в лесу:");
	scanf_s("%f", &K);
	if (K < 0) {
		printf("Вы потеряли грибы в лесу!");
	}
	else if (K == 0) {
		printf("Мы не нашли грибы в лесу.");
	}
	else {
		if (K == 1) {
			printf("Мы нашли %f гриб в лесу!", K);
		}
		else if (K >= 2 && K <= 4) {
			printf("Мы нашли %f гриба в лесу!", K);
		}
		else if (K > 4 && K <= 20) {
			printf("Мы нашли %f грибов в лесу!", K);
		}
		else if (fmod(K, 10) > 4 && fmod(K, 10) < 10) {
			printf("Мы нашли %f грибов в лесу!", K);
		}
		else if (fmod(K, 10) > 1 && fmod(K, 10) < 5) {
			printf("Мы нашли %f гриба в лесу!", K);
		}
		else if (fmod(K, 100) == 1) {
			printf("Мы нашли %f гриб в лесу!", K);
		}
		else if (fmod(K, 100) == 11) {
			printf("Мы нашли %f грибов в лесу!", K);
		}
		else if (fmod(K, 10) == 0) {
			printf("Мы не нашли грибов в лесу.");
		}
	}
}