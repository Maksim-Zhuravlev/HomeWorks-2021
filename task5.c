#include<stdio.h>
#include<stdlib.h>


int pow (int x, int n) {

	int res = 1;
	if (!n)
        return 1;
	while (n) {

    if (n % 2 == 0) {

        n /= 2;
        x *= x;
		}
    else {

        n--;
        res*= x;
		}
	}
	return res;
}
int main()
{
	int n , x;

	printf ("enter a number: ");
	scanf("%d", &x);
	printf ("\nenter a second number: ");
	scanf("%d", &n);
	printf("%d", pow (x, n) );
}

