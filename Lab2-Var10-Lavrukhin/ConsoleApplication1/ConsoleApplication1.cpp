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
#include "windows.h"
#define SIZE 100
<<<<<<< HEAD
int scanf_check_int();
float scanf_check_float();
=======
int scanf_check();
float scanf_check2();
>>>>>>> 6abecdc5c361147147250a7cbd1cba6e5d8ca6b4
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int lenght, j = 0, i;
	float Array[SIZE], summEvenNum = 0, ArithMean;
	printf("Please, enter the lenght of the array: ");
	lenght = scanf_check_int();
	while (lenght < 0)
	{
		printf("Please try again and enter a positive number: ");
		lenght = scanf_check_int();
	}
	for (i = 0; i < lenght; i = i + 1)
	{
		printf("%d element of array: ", i);
		Array[i] = scanf_check_float();
		if (i % 2 == 0)
		{
			summEvenNum = summEvenNum + Array[i];
			j = j + 1;
		}
	}
	ArithMean = summEvenNum / j;
	printf("\nArithmetic mean of even elements of the array is: %1.2f", ArithMean);
	_getch();
	return 0;
}

int scanf_check_int()
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
		number = scanf_check_int();
	}
	return number;
}

float scanf_check_float()
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
		number2 = scanf_check_float();
	}
	return number2;
}
