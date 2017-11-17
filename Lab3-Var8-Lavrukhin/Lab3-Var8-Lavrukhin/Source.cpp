/*
Лаврухин Константин Максимович
Лабораторная работа №3.
Вариант №8
Задание:Написать программу, которая во вводимом с клавиатуры тексте удалит все пробелы,
знаки табуляции и выведет количество удаленных символов на экран.
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 256
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int i, size, counter = 0, j = 0;
	char sentence[SIZE];
	printf("Enter text: \n");
	fgets(sentence, 256, stdin);
	size = strlen(sentence);
	while (size <= 2) // Ввод Предложения
	{
		printf("Too small text. Enter again: \n");
		fgets(sentence, 256, stdin);
		size = strlen(sentence);
	}
	for (i = 0; i < size; i++) //Подсчет всех пробелов и знаков табуляции
	{
		if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\v')
		{
			counter = counter + 1;
		}
	}
	for (i = 0; i < size; i++) //Проверяет каждый элемент, если это пробел или знак табуляции, то перезаписывает его 
	{	//со следующими до тех пор, пока это не будет символ. Перенесенный символ заменяем пробелом.
		j = i + 1;
		while (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\v')
		{
			sentence[i] = sentence[j];
			sentence[j] = ' ';
			j = j + 1;
		}
	}
	printf("\nYour Sentence without tabulations and spaces: \n%s", sentence);
	printf("\nTabulations and spaces deleted: %d", counter);
	_getch();
}