//	����������, ������� �� ����� ����� ����� a, b � c ���� �� ���� ������.
#include <stdio.h> //�����. ����������
#include <locale.h>  //�����. ���������� ��� �������� �����

main() {
	setlocale(LC_ALL, "Rus"); //������� ����
	int a, b, c;
	printf("������� 3 ����� �����:\n");
	scanf_s("%d%d%d", &a, &b, &c);
	if ((a == 0) || (b == 0) || (c == 0)) {
		printf("�����  ����� ������������ ����.\n");
	}
	if ((a % 2 == 0) && (a != 0) || (b % 2 == 0) && (b != 0) || (c % 2 == 0) && (c != 0))
	{
		printf("���� ������ �����!\n");
	}
	else {
		printf("������� ����� ���!\n");
	}


}
