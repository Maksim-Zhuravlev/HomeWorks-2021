#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100 // ������������ ����� ������

int main()
{
	char s[MAXLINE] = "I prefer pi";
	char t[MAXLINE]; // �������� � ���� ������ ������, �� ��� �������� � � ������ ��������
	int j = 0;
	for (int i = 0; i < strlen(s); i++) // ���������� ���� ��� ������������� ������ s (�� 0 �������� �� ����������)
	{
		if (s[i] != ' ') // ��������� ������ �� ��, �������� �� �� ��������
		{
			t[j] = tolower(s[i]); // �������� ������ � ������ ��������� ������� ������� t, ���� �� �� �������� �������� � ��������� ������� � ������ �������.
			++j; 
		}
	}
	t[j] = '\0'; // ����� ������
	for (int i = 0; i < strlen(t); i++)
	{
		printf("%c",t[i]); // ��������� ������� � ������ �������
	}
	int result = 1;
	for (int i = 0; i < strlen(t); i++)
	{
		if ( t[i] != t[strlen(t) - (i + 1)])  // strlen(t)-(i+1) - ������ ������� ���������� ������������ �������� t[i]
		{
			result = 0;
			break;
		}
	}
	printf("\n%i", result);



}