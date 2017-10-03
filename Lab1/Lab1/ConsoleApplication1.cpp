/*
Лаврухин Константин Максимович
Лабораторная работа №1.
Вариант №10
Задание: Перевести из метров в пяди и аршины.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <conio.h>
#define Span 4.37445
#define Arsh 1.40607424072


int main()
{

	float meters, arshins, span;

	printf("Please, enter positive number of meters: ");
	scanf("%f", &meters);
			if (meters >= 0)
		{
			arshins = meters * Arsh;
			printf("\n Your number of meters in arshins: %f", arshins);
			span = meters * Span;
			printf("\n Your number of meters in spans: %f", span);
		}
		else
		{
			printf("invalid input \n");

		}
			_getch();
		return 0;
	}

