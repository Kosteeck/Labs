/*
Написать программу, которая вычисляет среднее арифметическое четных элементов массива.
Массив и его длина вводятся пользователем.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"

int main()
{
	int Array[100], checkLenght = 0, checkElements, lenght, summEvenNum = 0, j = 0, i, ArithMean;
	printf("Please, enter the lenght of the array: ");
	while (checkLenght == 0)
	{
		checkLenght = scanf("%d", &lenght);
		if (checkLenght == 0)
		{
			while (getchar() != '\n');
			printf("Please try again and enter a positive number:");
		}
	}
	for (i = 0; i < lenght; i = i + 1)
	{
		checkElements = 0;
		while (checkElements == 0)
		{
			printf("%d", i);
			printf(" element of array: ");
			checkElements = scanf("%d", &Array[i]);
			if (checkElements == 0)
			{
				while (getchar() != '\n');
				printf("Please try again and enter a positive number to set array.\n");
			}
			else 
			{
				if (i % 2 == 0)
				{
					summEvenNum = summEvenNum + Array[i];
					j = j + 1;
				}
			}
		}
	}
	ArithMean = summEvenNum / j;
	printf("Arithmetic mean of even elements of the array is: ");
	printf("%d", ArithMean);
	_getch();
	return 0;
}