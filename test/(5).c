/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int a, n;
	scanf("%d", &a);
	scanf("%d", &n);
	printf("%d", pow(a, n));
}*/
#include<stdio.h>
#include<stdlib.h>
int d(int x, int n)
{
	int count = 1;
	if (!n) return 1;
	while (n) 
	{
		if (n % 2 == 0) 
		{
			n /= 2;
			x *= x;
		}
		else 
		{
			n--;
			count *= x;
		}
	}
	return count;
}
int main()
{
	int n, x;
	scanf("%d", &x);
	scanf("%d", &n);
	printf("%d", d(x, n));
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int F(int a, int n, int t)
{
	if (n >= 1)
	{
		t = t * a;
		n--;
		F(a, n, t);
	}
	else
	{
		return t;
	}
}
int main()
{
	int a, n, t = 1;
	scanf("%d", &a);
	scanf("%d", &n);
	printf("%d", F(a, n, t));
}*/