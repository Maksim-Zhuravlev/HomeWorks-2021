#include <stdio.h>
#include <stdlib.h>

void prime (int N)
{
    int i, primer;
    primer =1;
    for (i=2;i<=N/2; i++)
        if (N%i==0)
        {
          primer = 0;
          break ;
        }
        if (primer ==1)
        {
            printf ("%d is a primerr number.", N);
        }
        else
            printf ("%d is not primer.", N);
}
int main ()
{
    int N;
    printf ("enter a number does not equal 1 please:");
    scanf ("%d", &N);
    prime (N);
    return 0;

}
