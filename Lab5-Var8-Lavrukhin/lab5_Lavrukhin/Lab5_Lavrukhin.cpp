/*
Лаврухин Константин Максимович
Лабораторная работа №5.
Вариант №8
Задание: Написать программу, которая записывает с клавиатуры в файл структуру 
согласно выданному варианту задания. В качестве разделителя полей структуры 
использовать символ табуляции. В программе реализовать: 
а) дополнение существующего массива структур новыми структурами; 
б) поиск структуры с заданным значением выбранного элемента; 
в) вывод на экран содержимого массива структур; 
г) упорядочение массива структур по заданному полю (элементу), например 
государство по численности.
Варинат задания: «Фильм»: название, режиссер (фамилия, имя, отчество), страна, год выпуска, 
стоимость (расходы на выпуск), кассовые сборы (доход).
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH_NAME_FILM 100
#define MAX_LENGTH_NAME_PRODUCER 50
#define MAX_LENGTH_NAME_COUNTRY 58

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void Choice();
int  Checkup(int max);
void EnterFilm();
void SearchFilm();
void OutputFilms();
void SortingFilms();
void ChoiceFunction(int inquiry);
void FillFilm(struct Film *Movie, struct Producer *FIO, struct Value *MONEY);
void FillFile(FILE *filmsFile, struct Film Movie, struct Producer FIO, struct Value MONEY);

struct Film  
{
	char	name[MAX_LENGTH_NAME_FILM];
	char	country[MAX_LENGTH_NAME_COUNTRY];
	int		dateOfRelease = 0;
};

struct Producer
{
	char	producerName[MAX_LENGTH_NAME_PRODUCER];
	char	producerSurname[MAX_LENGTH_NAME_PRODUCER];
	char	producerLastName[MAX_LENGTH_NAME_PRODUCER];
	int		i = 0;
};

struct Value
{
	int	cost = 0;
	int	income = 0;
};

int main()
{
	system("chcp 1251");
	system("cls");
	printf("Что вы хотите сделать?\n");
	Choice();
	int inquiry = Checkup(5);
	ChoiceFunction(inquiry);
	getchar();
	return 0;
}

void Choice() 
{
	printf("1)Внести новый фильм в файл\n");
	printf("2)Поиск фильма в файле\n");
	printf("3)Вывод всех фильмов на экран\n");
	printf("4)Сортировка фильмов в файле\n");
	printf("5)Завершение работы программы\n");
	printf("Ответ: ");
}

int Checkup(int max)
{
	int number = 0;
	while (!scanf("%d", &number) || number < 1 || number > max)
	{
		while (getchar() != '\n');
		printf("Ошибка ввода. Пожалуйста, повторите снова: ");	
	}
	if (getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Ошибка ввода. Пожалуйста, повторите снова: ");
		number = Checkup(max);
	}
	return number;
}

void ChoiceFunction(int inquiry)
{
	switch (inquiry)
	{
	case 1:
		EnterFilm();
		break;
	case 2:
		SearchFilm();
		break;
	case 3:
		OutputFilms();
		break;
	case 4:
		SortingFilms();
		break;
	case 5:
		exit(0);
	}
}

void EnterFilm()
{
	Film Movie;
	Producer FIO;
	Value MONEY;
	
	FILE* filmsFile = fopen("Films.txt", "a");
	if (filmsFile == NULL)
	{
		filmsFile = fopen("Films.txt", "w");
	}
	bool check = true;
	int choice;
	do
	{
		FillFilm(&Movie, &FIO, &MONEY);
		FillFile(filmsFile, Movie, FIO, MONEY);
		printf("\nЗаписать еще один фильм? (1 - да, 2 - нет): ");
		choice = Checkup(2); 
		printf("\n");
		if (choice == 1)
		{
			check = true;
		}
		else
		{
			check = false;
		}
	} 
	while (check == true);
}

void FillFilm(struct Film *Movie, struct Producer *FIO, struct Value *MONEY)
{
	printf("\nПожалуйста, введите название фильма: ");									
	fgets(Movie->name, MAX_LENGTH_NAME_FILM, stdin);

	printf("\nПожалуйста, введите имя продюссера: ");
	fgets(FIO->producerName, MAX_LENGTH_NAME_PRODUCER, stdin);

	printf("\nПожалуйста, введите фамилию продюссера: ");
	fgets(FIO->producerSurname, MAX_LENGTH_NAME_PRODUCER, stdin);

	printf("\nПожалуйста, введите отчество продюссера: ");
	fgets(FIO->producerLastName, MAX_LENGTH_NAME_PRODUCER, stdin);

	printf("\nПожалуйста, введите страну, где был сделан фильм: ");
	fgets(Movie->country, MAX_LENGTH_NAME_COUNTRY, stdin);

	printf("\nПожалуйста, введите год выпуска фильма: ");
	Movie->dateOfRelease = Checkup(2020);

	printf("\nПожалуйста, введите затраты на фильм: ");
	MONEY->cost = Checkup(100000000);

	printf("\nПожалуйста, введите доходы фильма: ");
	MONEY->income = Checkup(100000000);
}

void FillFile(FILE *filmsFile, struct Film Movie, struct Producer FIO, struct Value MONEY) 
{
	fprintf(filmsFile, "%s", Movie.name);
	fprintf(filmsFile, "\t%s", FIO.producerName);
	fprintf(filmsFile, "\t%s", FIO.producerSurname);
	fprintf(filmsFile, "\t%s", FIO.producerLastName);
	fprintf(filmsFile, "\t%s", Movie.country);
	fprintf(filmsFile, "\t%d\n", Movie.dateOfRelease);
	fprintf(filmsFile, "\t%d\n", MONEY.cost);
	fprintf(filmsFile, "\t%d\n\0", MONEY.income);
}

void SearchFilm()
{

}

void OutputFilms() 
{

}

void SortingFilms()
{

}