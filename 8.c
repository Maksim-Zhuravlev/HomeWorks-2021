#include <stdio.h>
 
int main () {
   int i;
   int j;
   int a;
   printf("Enter a number:");
   scanf("%d",&a);
   for(i = 2; i < a; i++) {
      for(j = 2; j <= (i / j); j++) 
      if(!(i % j)) break;
      if(j > (i / j)) printf("%d is prime\n", i);
   }
 
   return 0;
}
