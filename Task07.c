#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100 // максимальная длина строки

int main()
{
	char s[MAXLINE] = "I prefer pi";
	char t[MAXLINE]; // копируем в этот массив строку, но без пробелов и в нижнем регистре
	int j = 0;
	for (int i = 0; i < strlen(s); i++) // организуем цикл для посимвольного чтения s (от 0 элемента до последнего)
	{
		if (s[i] != ' ') // проверяем символ на то, является ли он пробелом
		{
			t[j] = tolower(s[i]); // копируем символ в первый свободный элемент массива t, если он не является пробелом и переводим символы в нижний регистр.
			++j; 
		}
	}
	t[j] = '\0'; // конец строки
	for (int i = 0; i < strlen(t); i++)
	{
		printf("%c",t[i]); // переводим символы в нижний регистр
	}
	int result = 1;
	for (int i = 0; i < strlen(t); i++)
	{
		if ( t[i] != t[strlen(t) - (i + 1)])  // strlen(t)-(i+1) - индекс массива зеркальный относительно элемента t[i]
		{
			result = 0;
			break;
		}
	}
	printf("\n%i", result);



}