#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

  dividend = abs(dividend);
  divisor = abs(divisor);

  int quotient = 0;
  while (dividend >= divisor) {
    dividend -= divisor;
    quotient++;
  }

  return quotient * sign;
}

int main() {
  int dividend, divisor;

  printf("Enter dividend: ");
  scanf("%i", &dividend);

  printf("Enter divisor: ");
  scanf("%i", &divisor);

  printf("Result: %i", divide(dividend, divisor));

  return 0;
}