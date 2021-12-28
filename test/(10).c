#include<stdio.h>
#include<stdlib.h>
int F(int n)
{
	int w = 0;
	if (n > 2)
	{
		return	w = w + F(n - 1) + F(n - 2);
	}
	else
	{
		return w + n;
	}
}
int main()
{
	int e;
	scanf("%d", &e);
	printf("%d", F(e));
}


