#include <stdio.h>
#include <math.h>
#include <iostream>
#include <windows.h>


void minmax(int& x, int& y)
{
	if (x > y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
}

int main()
{
	int a, b , c;

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите A: "); scanf("%d", &a);
	printf("Введите B: "); scanf("%d", &b);
	printf("Введите C: "); scanf("%d", &c);

	minmax(b ,c);
	minmax(a, b);
	minmax(b, c);

	printf("A = %d <= B = %d <= C = %d\n", a,b,c);

    return 0;
}