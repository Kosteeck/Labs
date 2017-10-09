/*
Лаврухин Константин Максимович
Лабораторная работа №1.
Вариант №10
Задание: Перевести из метров в пяди и аршины.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <conio.h>
#define SPAN 4.37445
#define ARSH 1.40607424072

int main()
{
	float meters, arshins, span;
	printf("Please, enter positive number of meters: ");
	int result = scanf("%f", &meters);
		if (meters >= 0 && result == 1)
		{
			arshins = meters * ARSH;
			printf("\n Your number of meters in arshins: %f", arshins);
			span = meters * SPAN;
			printf("\n Your number of meters in spans: %f", span);
		}
		else
		{
			printf("Please, enter positive number of meters next time");
		}
	_getch();
	return 0;
}
