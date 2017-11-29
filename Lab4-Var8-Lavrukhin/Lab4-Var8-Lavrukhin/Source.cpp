/*
�������� ���������� ����������
������������ ������ �4.
������� �8
�������:�������� ���������, ������� ����� ����� �� �����, ������� ��� �������,
����� ��������� � ������� ��������� � ������ ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 512

int checkFile(FILE *myFile);													// �������� �� ������������� �����
int amountOfFile(FILE *myFile);													// ������� �������� � �����
int fillMassiveFromFile(char *sentence, int size, int counter, FILE *myFile);	// ���������� ������� ������� �� �����
int deleteSpaces(char *sentence, int size);										// �������� �������� � ������ ��������� �� �������
int fillFileFromMassive(char *sentence, int size, FILE *finallFile);			// ���������� ����� ������� �� �������

int main(void)
{
	int counter = 0;
	char sentence[SIZE];
	FILE* myFile = fopen("enterText.txt", "r");
	FILE* finalFile = fopen("finalText.txt", "w");
	checkFile(myFile);
	int size = amountOfFile(myFile);
	fseek(myFile, 0, SEEK_SET);
	counter = fillMassiveFromFile(sentence, size, counter, myFile);
	deleteSpaces(sentence, size);
	size = size - counter;
	fillFileFromMassive(sentence, size, finalFile);
	fprintf(finalFile, "(������� %i �������� � ������ ���������)", counter);
}

int checkFile(FILE *myFile)
{
	if (myFile == NULL)
	{
		printf("Please, enter text in the file next time");
		_getch();
		exit(0);
	}
	return 0;
}

int amountOfFile(FILE *myFile)
{
	int size = 0;
	for (int i = 0; fgetc(myFile) != EOF; i++)
		size = size + 1;
	return size;
}

int deleteSpaces(char *sentence, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		j = i + 1;
		while (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\v')
		{
			sentence[i] = sentence[j];
			sentence[j] = ' ';
			j = j + 1;
		}
	}
	return 0;
}

int fillMassiveFromFile(char *sentence, int size, int counter, FILE *myFile)
{
	for (int i = 0; i < size; i++)
	{
		sentence[i] = fgetc(myFile);
		if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\v')
			counter = counter + 1;
	}
	return counter;
}

int fillFileFromMassive(char *sentence, int size, FILE *finalFile)
{
	for (int i = 0; i < size; i++)
		fprintf(finalFile, "%c", sentence[i]);
	return 0;
}