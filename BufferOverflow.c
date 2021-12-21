#include <stdio.h>
#include <stdbool.h>

void other()
{
	printf("Hey! Function 'other' completed successfully!\n");
}

void input()
{
	int x[2];
	int i = 1;
	bool stop = false;

	while(!stop)
	{
		if (i == 4)
		{
			x[i] = (int)other;
			x[i + 1] = 0;
			stop = true;
		}
		else
		{
			x[i] = 0;
			i++;
		}
	}
}
void main()
{
	printf("Adress = %d\n\n", other);
	input();
	printf("isn't other\n");
}


