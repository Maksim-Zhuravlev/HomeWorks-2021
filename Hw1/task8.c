#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	
	
	printf("Enter n:\n");
	scanf("%d", &n);
	int num[n];
	char key[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = i + 1;
		key[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			printf("1\n");
		}
		else
		{
			if (key[i] == 1)
			{
				for(int k = i + num[i]; k < n; k += num[i])
				{
					key[k] = 0;
				}
			printf("%d\n", num[i]);
			}
		}
	}
	return 0;
} 