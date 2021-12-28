#include <iostream>
#include <math.h>
int mypow(int a, int n);
int recpow(int a, int n);
double logpow(double a, int n);
void main()
{
	
}
int mypow(int a, int n)
{
	int result = 1;
	for (int i = 0; i <= (n - 1); ++i)
	{
		result = result * a;
	}
	return result;
}
int recpow(int a, int n)
{
	if (n != 0)
	{
		return a * recpow(a, n - 1);
	}
	else
	{
		return 1;
	}
}
double logpow(double a, int n)
{
	double result = 1;
	result = exp(n * log(a));
	return result;
}
