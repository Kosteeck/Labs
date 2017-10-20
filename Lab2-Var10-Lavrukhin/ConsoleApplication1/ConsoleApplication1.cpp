	/*
	Лаврухин Константин Максимович
	Лабораторная работа №2.
	Вариант №10
	Задание:Написать программу, которая вычисляет среднее арифметическое четных элементов массива.
	Массив и его длина вводятся пользователем.
	*/

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "conio.h"
#define SIZE 100
	int scanf_check();
float scanf_check2();
int main()
{
	int lenght, j = 0, i;
	float Array[SIZE], summEvenNum = 0, ArithMean;
	printf("Please, enter the lenght of the array: ");
	lenght = scanf_check();
	while (lenght < 0)
	{
		printf("Please try again and enter a positive number: ");
		lenght = scanf_check();
	}
	for (i = 0; i < lenght; i = i + 1)
	{
		printf("%d element of array: ", i);
		Array[i] = scanf_check2();
		if (i % 2 == 0)
		{
			summEvenNum = summEvenNum + Array[i];
			j = j + 1;
		}
	}
	ArithMean = summEvenNum / j;
	printf("\nArithmetic mean of even elements of the array is: %f", ArithMean);
	_getch();
	return 0;
}

int scanf_check()
{
	int number;
	while (!scanf("%d", &number))
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
	}
	if (getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
		number = scanf_check();
	}
	return number;
}

float scanf_check2()
{
	float number2;
	while (!scanf("%f", &number2))
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
	}
	if (getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
		number2 = scanf_check2();
	}
	return number2;
}