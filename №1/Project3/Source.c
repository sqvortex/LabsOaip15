
// ��������� �������� ������� ����������� ax2+bx+c<0.
#include <stdio.h>
#include <locale.h>  //�����. ���������� ��� �������� �����
#include <math.h> //�����. �����������, ������� �������� �� ����������.

main() {
	setlocale(LC_ALL, "Rus"); //������� ����
	float a, b, c, D, x1, x2, S;
	printf("������� a : ");
	scanf_s("%f", &a);
	printf("������� b : ");
	scanf_s("%f", &b);
	printf("������� c : ");
	scanf_s("%f", &c);
	D = (b * b) - (4 * a * c);
	printf("������������ = (%f*%f)-(4*%f*%f) = %f\n", b, b, a, c, D);
	S = sqrt(D);
	printf("������ ������������� ����� = %f\n", S);

	if (D == 0 && a > 0)
	{
		printf("��� �������!");
	}
	if (D == 0 && a < 0)
	{
		x1 = (-b + S) / (2 * a);
		printf("�������: (-�������������; +�������������)U{x1} = %f", x1);
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
		printf("�������: (-�������������; %f)U(%f; +�������������)", x1, x2);
	}
	if (D < 0 && a < 0)
	{
		printf(" �������: ��� ��������!");
	}
	if (a == 0)
	{
		double x = 0;
		x = -c / b;
		printf("x= %f\n(-�������������; %f)", x,x);
	}
}

