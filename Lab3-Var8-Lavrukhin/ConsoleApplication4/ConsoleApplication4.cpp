/*
�������� ���������� ����������
������������ ������ �3.
������� �8
�������:�������� ���������, ������� �� �������� � ���������� ������ ������ ��� �������, 
����� ��������� � ������� ���������� ��������� �������� �� �����.
*/
#include "stdio.h"
#include "string.h"
#include "conio.h"
#define SIZE 256
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{	
	int i, size, Counter = 0, j = 0;
	char Sentence[SIZE];
	printf("Enter text: \n");
	fgets(Sentence, 256, stdin);
	size = strlen(Sentence);	
	while (size <= 2) // ���� �����������
	{
		printf("Too small text. Enter again: \n");
		fgets(Sentence, 256, stdin);
		size = strlen(Sentence);
	}
	for (i = 0; i < size; i++) //������� ���� �������� � ������ ���������
	{
		if (Sentence[i] == ' ' || Sentence[i] == '\t' || Sentence[i] == '\v')
		{
			Counter = Counter + 1;
		}
	} 
	for (i = 0; i < size; i++) //��������� ������ �������, ���� ��� ������ ��� ���� ���������, �� �������������� ��� 
	{						   //�� ���������� �� ��� ���, ���� ��� �� ����� ������. ������������ ������ �������� ��������.
		j = i + 1;
		while (Sentence[i] == ' ' || Sentence[i] == '\t' || Sentence[i] == '\v')
		{	
			Sentence[i] = Sentence[j];
			Sentence[j] = ' ';
			j = j + 1;
		}
	}
	printf("\nYour Sentence without tabulations and spaces: \n%s", Sentence);
	printf("\nTabulations and spaces deleted: %d", Counter);
	_getch();
}