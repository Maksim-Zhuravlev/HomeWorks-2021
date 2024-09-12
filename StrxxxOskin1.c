#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int my_strcpy(char* dest, const char* src)
{

	for (int i = 0; i <= strlen(src); i++)
	{
		dest[i] = src[i];
	}
	 
	return 0;
}




int my_strcat(char* dest, const char* app)
{
	int a = strlen(dest);
	for (int i = 0; i <= strlen(app); i++)
	{
		dest[i + a] = app[i];
	}

	return 0;
}



 

int my_strcmp(char* str1, char* str2)
{
  for (int i = 0; ; i++)
		{
			if (str1[i] != str2[i])
			{
				return str1[i] < str2[i] ? -1 : 1;
			}

			if (str1[i] == '\0')
			{
				return 0;
			}
		}
	
}






int my_strlen(char* str)
{
	int a = 0;

	for (int i = 0; str[i]; i++)                // в цикле for условие типа char str[i] приводится к типу bool, 
	{											//которая для любого символа, кроме конца строки будет возвращать истинное значение
		a++;
	
	}
	return a;
}





int main()
{
	return 0;
}