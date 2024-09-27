#include <stdio.h>
#include <stdlib.h>

int division (int divisor , int divided){
   int result = 0;
	int sign = sign_of_x(divisor) * sign_of_x(divided);
  if (divided == 0) {
      return 0;
}
 if (divisor == 0){
        printf( "try another number =/=0");
    return 0;
}
if (divided % divisor == 0 ){
    return 1;
}
if (divided % divisor != 0) {
		return 0;
}
else if ( divided <0 && divisor <0){
        sign =1;
}
else if (divided>0 && divisor <0){
    sign =-1;
}
    return 0;
}
