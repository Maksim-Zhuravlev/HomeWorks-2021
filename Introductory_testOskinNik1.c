#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Печатает простые числа до заданного числа
//---------------------------------------------------------------------------
int isPrimeNumber(int x)
{
	int  i = 2;

	if (x == 0 || x == 1)
	{
		return 0;
	}
	else
	{
		while (x % i != 0)
		{
			i++;
		}
	}

	return i < x ? 0 : 1;
}
//---------------------------------------------------------------------------

//Определение палиндрома
//---------------------------------------------------------------------------
int my_palindrome(char* x)
{
	int l;

	l = strlen(x) - 1;
	for (int i = 0; i < l; ++i, --l)
	{
		if (x[i] != x[l])
		{
			return 0;
		}
	}

	return 1;
}
//---------------------------------------------------------------------------

//Вхождение подстроки в строку
//---------------------------------------------------------------------------
int String_and_Substring(char* str, char* substr)
{
	int i = 0, j = 0, p = 0;
	
	if (strlen(str) < strlen(substr))
	{
		return 0;
	}

	while(i < strlen(str))
	{
		if (str[i] != substr[j])
		{
			if (j == strlen(substr))
			{
				p++;
			} 

			i++;
			j = 0;
		}
		else 
		{
			i++;
			j++;
		}

	}

	if (i == j)
	{
		p++;
	}

	return p;
}
//---------------------------------------------------------------------------

//Числа Фибоначчи
//---------------------------------------------------------------------------
long Fib(int n)
{
	long Fn_1 = 1, Fn_2 = 1, Fn = 0;

	if (n == 1 || n == 2)
	{
		return 1;
	}

	for (int i = 0; i <= n - 3; i++)
	{
		Fn = Fn_1 + Fn_2;
		Fn_2 = Fn_1;
		Fn_1 = Fn;
	}

	return Fn;
}

//Рекурсивно
long Fib_rec(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n < 1)
	{
		return 0;
	}

	return Fib_rec(n - 1) + Fib_rec(n - 2);
}
//---------------------------------------------------------------------------

//Определение знака в перемножении массива
//---------------------------------------------------------------------------
int sign(int* x, int n)
{
	int mult = 1;

	for (int i = 0; i < n; i++)
	{
		mult = mult * (int)(x[i] != 0) * (int)(x[i] > 0 ? 1 : -1);
	}

	return mult;
}
//---------------------------------------------------------------------------

//Возведение a в стпень n
//---------------------------------------------------------------------------
//Любой способ
float degree(float a, int n)
{
	float deg = 1;

	if (n >= 0)
	{
		for (int i = 0; i <= n - 1; i++)
		{
			deg = deg * a;
		}
	}
	else
	{
		for (int i = 0; i <= abs(n) - 1; i++)
		{
			deg = deg / a;
		}
	}

	return deg;
}

//Эффективно
float degree_eff(float a, int n)
{
	float deg = 1;
	float a_f = a;

	if (n < 0)
	{
		a_f = 1 / a;
	}

	for (int i = 0; i < abs(n) / 2; i++)
	{
		deg = deg * a_f;
	}

	deg = deg * deg;

	if (abs(n) % 2)
	{
		deg = deg * a_f;
	}

	return deg;
}

//Рекурсивно
float degree_rec(float a, int n)
{
	float a_f;

	if (n >= 0)
	{
		a_f = a;
	}
	else
	{
		a_f = 1/a;
	}

	if      (n == 0)	  return 1;
	else if (abs(n) == 1) return a_f;
	else				  return a_f * degree_rec(a_f, abs(n) - 1);
}
//---------------------------------------------------------------------------

void main()
{

}