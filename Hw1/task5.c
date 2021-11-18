#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	int n;
 	int ans=1;
	printf("Enter number:");
	scanf("%d", &a);
	printf("Enter the degree:");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		ans *= a;
	}
	printf("Answer: %d",ans);
	return 0;
}