#include <stdio.h>
#include <stdlib.h>

void other()
{
	printf("Function \"other\" was called.\n");
	exit(1);
}

void input()
{
	int data[1];
	int x = 0;
	int i = 0;
	//Fourth number should be an address of function "other"
	while (1)
	{
		printf("Enter %d number:", (i + 1));
		scanf("%d", &x);
		if (0 == x)
		{
			break;
		}
		data[i++] = x;
	}
}

int main()
{
	printf("Function \"other\": %d\n", (int)other);
	input();
	printf("Function \"other\" was not called.\n");
	return 0;
}