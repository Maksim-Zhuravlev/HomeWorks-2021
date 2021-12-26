#include <stdio.h>
#include <stdlib.h>

void sign (int x, int y)
{
    int z;
    z= x*y;
    if (z<0){
        printf ("your number is negative.");
    }
    else if (z>0)
    {
        printf ("your is positive");
    }
    else
        printf ("your number equal 0");
}
int main ()
{
    int x, y , z;
    printf ("enter a number please:");
    scanf ("%d",&x);
    printf("enter another number :");
    scanf ("%d", &y);
    sign (x,y);
    return 0;
}
