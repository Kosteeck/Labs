/*
Лаврухин Константин Максимович
Лабораторная работа №5.
Вариант №8
Задание : Написать программу, которая записывает с клавиатуры в файл структуру
	согласно выданному варианту задания.В качестве разделителя полей структуры
	использовать символ табуляции.В программе реализовать :
а) дополнение существующего массива структур новыми структурами;
б) поиск структуры с заданным значением выбранного элемента;
в) вывод на экран содержимого массива структур;
г) упорядочение массива структур по заданному полю(элементу), например
государство по численности.
Варинат задания : «Фильм»: название, режиссер(фамилия, имя, отчество), страна, год выпуска,
стоимость(расходы на выпуск), кассовые сборы(доход).
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH_NAME_FILM 256
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
void SearchFilmElement();
void SearchFilmByElement(int choose);
void FillStructForSearch(struct Film *Movie, struct Producer *FIO, struct Value *MONEY, FILE *filmsFile);
int  CheckForCoincidence(struct Film Movie, struct Producer *FIO, struct Value *MONEY, int inquiry, char *search);
void checkFile(FILE *filmsFile);	

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
	int inquiry = 0;
	do
	{
		printf("\nЧто вы хотите сделать?\n");
		Choice();
		inquiry = Checkup(5);
		ChoiceFunction(inquiry);
	} while (inquiry != 5);
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
		break;
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
	} while (check == true);
	fclose(filmsFile);
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
	fprintf(filmsFile, " %s", Movie.name);
	fprintf(filmsFile, "%s", FIO.producerName);
	fprintf(filmsFile, "%s", FIO.producerSurname);
	fprintf(filmsFile, "%s", FIO.producerLastName);
	fprintf(filmsFile, "%s", Movie.country);
	fprintf(filmsFile, "%d\n", Movie.dateOfRelease);
	fprintf(filmsFile, "%d\n", MONEY.cost);
	fprintf(filmsFile, "%d\0\n", MONEY.income);
}

void SortingFilms()
{

}

void OutputFilms()
{ 
	Film Movie;
	Producer FIO;
	Value MONEY;

	FILE* filmsFile = fopen("Films.txt", "r");
	checkFile(filmsFile);
	int n = 1;
	do
	{
		printf("\nФильм №%d", n);

		fgets(Movie.name, MAX_LENGTH_NAME_FILM, filmsFile);
		printf("\nНазвание фильма: %s", Movie.name);

		fgets(FIO.producerName, MAX_LENGTH_NAME_PRODUCER, filmsFile);
		printf("Имя продюссера: %s", FIO.producerName);

		fgets(FIO.producerSurname, MAX_LENGTH_NAME_PRODUCER, filmsFile);
		printf("Фамилия продюссера: %s", FIO.producerSurname);

		fgets(FIO.producerLastName, MAX_LENGTH_NAME_PRODUCER, filmsFile);
		printf("Отчество продюссера: %s", FIO.producerLastName);

		fgets(Movie.country, MAX_LENGTH_NAME_COUNTRY, filmsFile);
		printf("Страна, где был сделан фильм: %s", Movie.country);

		fscanf(filmsFile, "%d", &Movie.dateOfRelease);
		printf("Год выпуска фильма: %d", Movie.dateOfRelease);

		fscanf(filmsFile, "%d", &MONEY.cost);
		printf("\nЗатраты на фильм: %d", MONEY.cost);

		fscanf(filmsFile, "%d", &MONEY.income);
		printf("\nДоходы фильма: %d\n\n", MONEY.income);

		n = n + 1; 
	} while (fgetc(filmsFile) != EOF);
}

void checkFile(FILE *filmsFile)
{
	if (filmsFile == NULL)
	{
		printf("Файл пустой, запустите программу снова, если хотите его заполнить.");
		_getch();
		exit(0);
	}
}

void SearchFilm()
{
	SearchFilmElement();
	int chooseElement = Checkup(6);
	SearchFilmByElement(chooseElement);
}

void SearchFilmElement()
{
	printf("\nПо какому элементу вы хотите найти фильм? ");
	printf("\n1) Название фильма ");
	printf("\n2) Фамилия продюссера");
	printf("\n3) Страна, где был сделан фильм ");
	printf("\n4) Год выпуска фильма");
	printf("\n5) Затраты фильма");
	printf("\n6) Доходы фильма");
	printf("\nОтвет: ");
}

void SearchFilmByElement(int choose)
{
	Film Movie;
	Producer FIO;
	Value MONEY;
	FILE* filmsFile = fopen("Films.txt", "r");
	int n = 1;
	bool check;
	printf("Введите значение: ");
	char search[MAX_LENGTH_NAME_FILM];
	fgets(search, MAX_LENGTH_NAME_FILM, stdin);
	do
	{
		FillStructForSearch(&Movie, &FIO, &MONEY, filmsFile);
		check = CheckForCoincidence(Movie, &FIO, &MONEY, choose, search);
		if (check == true)
		{
			printf("\nФильм №%d", n);
			printf("\nНазвание фильма: %s", Movie.name);
			printf("Имя продюссера: %s", FIO.producerName);
			printf("Фамилия продюссера: %s", FIO.producerSurname);
			printf("Отчество продюссера: %s", FIO.producerLastName);
			printf("Страна, где был сделан фильм: %s", Movie.country);
			printf("Год выпуска фильма: %d", Movie.dateOfRelease);
			printf("\nЗатраты на фильм: %d", MONEY.cost);
			printf("\nДоходы фильма: %d\n\n", MONEY.income);
			n = n + 1;
		}
	} while (fgetc(filmsFile) != EOF);
}

void FillStructForSearch(struct Film *Movie, struct Producer *FIO, struct Value *MONEY, FILE *filmsFile)
{
	fgets(Movie->name, MAX_LENGTH_NAME_FILM, filmsFile);
	fgets(FIO->producerName, MAX_LENGTH_NAME_PRODUCER, filmsFile);
	fgets(FIO->producerSurname, MAX_LENGTH_NAME_PRODUCER, filmsFile);
	fgets(FIO->producerLastName, MAX_LENGTH_NAME_PRODUCER, filmsFile);
	fgets(Movie->country, MAX_LENGTH_NAME_COUNTRY, filmsFile);
	fscanf(filmsFile, "%d", &Movie->dateOfRelease);
	fscanf(filmsFile, "%d", &MONEY->cost);
	fscanf(filmsFile, "%d", &MONEY->income);
}

int CheckForCoincidence(struct Film Movie, struct Producer *FIO, struct Value *MONEY, int inquiry, char *search)
{
	bool check = false;
	int checkint;
	switch (inquiry)
	{
	case 1:
		if (strcmp(Movie.name, search) == 0)
		{
			check = true;
		}
	case 2:
		if (strcmp(FIO->producerSurname, search) == 0)
		{
			check = true;
		}
	case 3:
		if (strcmp(Movie.country, search) == 0)
		{
			check = true;
		}
	case 4:
		checkint = atoi(search);
		if (Movie.dateOfRelease == checkint)
		{
			check = true;
		}
	case 5:
		checkint = atoi(search);
		if (MONEY->cost == checkint)
		{
			check = true;
		}
	case 6:
		checkint = atoi(search);
		if (MONEY->income == checkint)
		{
			check = true;
		}
	}
	return check;
}