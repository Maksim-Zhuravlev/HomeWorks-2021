#include <stdio.h>
#include < stdlib.h > 
int main()
{
	int p = 1;
	int a[10] = { 2,6,3,-15,444,-312,55,-7,0,-4 };
	for (int i = 1; i<10; ++i)
	{
		if (a[i] != 0)
		{
			p = p * (a[i] / abs(a[i]));
		}
		else
		{
			p = 0;
		}
	}
	printf("%i\n", p);
	
}