#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int q, e, t = 10, j;
	scanf("%d", &q);
	if (q > 1) printf("1 ");
	for (int i = 2; i <= q; i++)
	{
		e = i; t = 10;
		for (j = 2; j < e; j++)
		{
			if (e % j == 0)
			{
				t = 0;
				break;
			}
		}
		if (t == 10) printf("%d ", j);
	}
}