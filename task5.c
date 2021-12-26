#include <stdio.h>
#include <stdlib.h>

void power (int x,int y)
{
    int P;
    P= pow (x,y);
    printf  (" %d power %d equal: %d", x,y,P);
}
int main()
{
    int x,y;
       printf ("enter a number :");
       scanf (" %d", &x);
       printf ("enter another number :");
       scanf ("%d", &y);
       power (x,y);
       return 0;

}
