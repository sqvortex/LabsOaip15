// 	��� ������������ ����� � ���������� ����� "�� ����� � ������ � ����", ���������� ��������� ����� "����" � ������ �. 
//fmod ������� �� �������
#include <stdio.h>
#include<locale.h>
#include <math.h>
main() {
	setlocale(LC_ALL, "Rus"); //������� ����
	float K;
	printf("������� ���������� ��������� ������ � ����:");
	scanf_s("%f", &K);
	if (K < 0) {
		printf("�� �������� ����� � ����!");
	}
	else if (K == 0) {
		printf("�� �� ����� ����� � ����.");
	}
	else {
		if (K == 1) {
			printf("�� ����� %f ���� � ����!", K);
		}
		else if (K >= 2 && K <= 4) {
			printf("�� ����� %f ����� � ����!", K);
		}
		else if (K > 4 && K <= 20) {
			printf("�� ����� %f ������ � ����!", K);
		}
		else if (fmod(K, 10) > 4 && fmod(K, 10) < 10) {
			printf("�� ����� %f ������ � ����!", K);
		}
		else if (fmod(K, 10) > 1 && fmod(K, 10) < 5) {
			printf("�� ����� %f ����� � ����!", K);
		}
		else if (fmod(K, 100) == 1) {
			printf("�� ����� %f ���� � ����!", K);
		}
		else if (fmod(K, 100) == 11) {
			printf("�� ����� %f ������ � ����!", K);
		}
		else if (fmod(K, 10) == 0) {
			printf("�� �� ����� ������ � ����.");
		}
	}
}