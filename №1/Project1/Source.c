//������ ����� ����� ����. ����� ����� ���� � ������� ��� ������� �����������. ��������� ������� � ��������� �� ���� ������ ����� �������.

#include <stdio.h> //�����. ����������
#include <locale.h>  //�����. ����������

main() {           //���� ���������
	setlocale(LC_ALL, "Rus");
	float lenght;

	printf("������� ����� ����:"); //����� ������ �� �����
	scanf_s("%f", &lenght);
	if (lenght <= 0) {
		printf("������� ��������� ��������!\n");
	}
	else {
		float square;
		square = (lenght * lenght) * 6;
		printf("������� ������� ����������� = %.3f*%.3f*6 = %.3f\n", lenght, lenght, square); //����� ������� ���. ���������� ����
		float volume;
		volume = lenght * lenght * lenght;
		printf("����� ���� = %.3f*%.3f*.%.3f=%.3f\n", lenght, lenght, lenght, volume);
		scanf_s("%f", &volume);
	}
}
