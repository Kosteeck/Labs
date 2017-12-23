/*
Индивидуальная работа
Вариант 6
Задание состоит в разработке программы, которая считывает настроечные
параметры и формирует отчет по имеющимся данным в файлах. Отчет
записывается в текстовый файл. Число записей в каждом из описанных выше
файлов произвольно. Вариант задания:
В отчетный файл: Перечислить ФИО клиентов,
пользовавшихся указанной услугой в
дневное время
Параметры: Наименование услуги
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGHT_SERVICE 90
#define MAX_LENGHT_STRUCT_SERVICE_ARRAY 100
#define MAX_LENGHT_STRING_IN_FILE 200
#define MAX_LENGHT_PHONE_NUMBER 100
#define MAX_LENGHT_FIO 256
#define MAX_LENGHT_STRING_ARRAY 500
#define MAX_LENGHT_HOUR 2
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct services
{
	char nameOfService[MAX_LENGHT_SERVICE];
	char serviceCode[MAX_LENGHT_STRUCT_SERVICE_ARRAY];
};
struct renderServices
{
	char phoneNumber[MAX_LENGHT_PHONE_NUMBER];
	char serviceCode[MAX_LENGHT_STRUCT_SERVICE_ARRAY];
	char hourUseTheService[MAX_LENGHT_HOUR];
};

struct clients
{
	char FIO[MAX_LENGHT_FIO];
	char phoneNumber[MAX_LENGHT_PHONE_NUMBER];
};

void checkFile(FILE *RenderServices, FILE *Client, FILE *Services);
int checkServiceInFile(char *service, FILE *services);
void phoneNumberSearch(FILE *RenderServices, int code, char* phoneNumber);
void searchClients(FILE* Client, FILE* Report, char *phoneNumbers);

int main()
{
	system("chcp 1251");
	system("cls");
	FILE* Report = fopen("Report.txt", "w");
	FILE* Client = fopen(".clientInfo.txt", "r");
	FILE* Services = fopen(".servicesInfo.txt", "r");
	FILE* RenderServices = fopen(".renderServicesInfo.txt", "r");
	checkFile(RenderServices, Client, Services);
	printf("Введите услугу: ");
	char service[MAX_LENGHT_SERVICE];
	char phoneNumber[MAX_LENGHT_PHONE_NUMBER];
	fgets(service, MAX_LENGHT_SERVICE, stdin);
	service[strlen(service) - 1] = '\0';
	int codeOfService = checkServiceInFile(service, Services);
	phoneNumberSearch(RenderServices, codeOfService, phoneNumber);
	searchClients(Client, Report, phoneNumber);
	return 0;
}

void checkFile(FILE *RenderServices, FILE *Client, FILE *Services)
{
	if (RenderServices == NULL)
	{
		printf("Пожалуйста, введите текст в файл .renderServicesInfo.txt в след. раз");
		_getch();
		exit(0);
	}
	else if (Client == NULL)
	{
		printf("Пожалуйста, введите текст в файл .clientInfo.txt в след. раз");
		_getch();
		exit(0);
	}
	else if (Services == NULL)
	{
		printf("Пожалуйста, введите текст в файл .servicesInfo.txt в след. раз");
		_getch();
		exit(0);
	}
}

int checkServiceInFile(char *service, FILE *Services) //Оптимизировать, вынести в отдельные функции циклы, спросить насчет переноса строки в файле.
{
	struct services arrayOfService;
	int code, j = 0, k = 0;
	char massiveOfServices[MAX_LENGHT_STRUCT_SERVICE_ARRAY];
	while (strcmp(arrayOfService.nameOfService, service) != 0 && !feof(Services))
	{
		j = 0;
		k = 0;
		fgets(massiveOfServices, MAX_LENGHT_STRUCT_SERVICE_ARRAY, Services);
		while (massiveOfServices[j] != ',')
		{
			arrayOfService.nameOfService[j] = massiveOfServices[j];
			j++;
		}
		arrayOfService.nameOfService[j] = '\0';
		j++;
		if (strcmp(arrayOfService.nameOfService, service) == 0)
		{
			while (massiveOfServices[j] != ',')
			{
				arrayOfService.serviceCode[k] = massiveOfServices[j];
				j++; k++;
			}
		}
	} 
		code = atoi(arrayOfService.serviceCode);
	return code;
}

void phoneNumberSearch(FILE *RenderServices, int code, char* phoneNumber)
{
	struct renderServices renderService;
	char arrayOfrenderService[MAX_LENGHT_STRING_ARRAY];
	phoneNumber[0] = '\0';
	int iteration = 0;
	while (!feof(RenderServices))
	{
		int j = 0, k = 0, i = 0;
		fgets(arrayOfrenderService, MAX_LENGHT_STRING_ARRAY, RenderServices);
		while (arrayOfrenderService[j] != ',')
		{
			renderService.phoneNumber[j] = arrayOfrenderService[j];
			j++;
		}
		j++;
		while (arrayOfrenderService[j] != ',')
		{
			renderService.serviceCode[k] = arrayOfrenderService[j];
			j++; k++;
		}
		int reservCode = atoi(renderService.serviceCode);
		if (reservCode == code)
		{
			j = j + 13;
			while (arrayOfrenderService[j] != ':')
			{
				renderService.hourUseTheService[i] = arrayOfrenderService[j];
				j++; i++;
			}
			int reservHour = atoi(renderService.hourUseTheService);
			if (reservHour <= 16 && reservHour >= 12)
			{
				strcat(phoneNumber, renderService.phoneNumber);
				iteration++;
				phoneNumber[iteration * 10] = '\0';
			}
			while (arrayOfrenderService[j] != '\n')
			{
				j++;
			}
		}
	}
}

void searchClients(FILE* Client, FILE* Report,char *phoneNumbers)
{
	struct clients clientsInfo;
	while (!feof(Client))
	{
		int j = 0, k, m = 0;
		char arrayOfClients[MAX_LENGHT_STRING_ARRAY];
		char phoneNumberForCheck[MAX_LENGHT_PHONE_NUMBER];
		fgets(arrayOfClients, MAX_LENGHT_STRING_ARRAY, Client);
		while (arrayOfClients[j] != ',')
		{
			clientsInfo.FIO[j] = arrayOfClients[j];
			j++;
		}
		clientsInfo.FIO[j] = '\0';
		j = j + 2;
		while (arrayOfClients[j] != ',')
		{
			clientsInfo.phoneNumber[m] = arrayOfClients[j];
			j++; m++;
		}
		clientsInfo.phoneNumber[m] = '\0';
		k = 0;
		while (phoneNumbers[k] != '\0')
		{
			int t = 0;
			int counter = 0;
			while (counter != 10)
			{
				phoneNumberForCheck[t] = phoneNumbers[k];
				t++; k++; counter++;
			}
			int checkNumbersForCoincidence = 0;
			while ((phoneNumberForCheck[checkNumbersForCoincidence] == clientsInfo.phoneNumber[checkNumbersForCoincidence]) && (checkNumbersForCoincidence < 9))
			{
				checkNumbersForCoincidence++;
			}
			if (checkNumbersForCoincidence == 9)
			{
				fprintf(Report,"%s, ", clientsInfo.FIO);
			}
		}
		while (arrayOfClients[j] != '\n')
		{
			j++;
		}
	}
}