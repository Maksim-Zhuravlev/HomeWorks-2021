#include <stdio.h>
#include <math.h>
int div(int divisor, int divident); 
int main()
{
	printf("%d", div(100, -10));
}
int div(int divisor, int divident)
{
	if (divident == 0) 
	{
		return 0;
	}
	double b = divident; // приведение типов для вызова pow, так как pow использует в качестве аргументов тип double
	int result = 0;
	result = divisor * pow(b, -1);
}
