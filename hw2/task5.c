#include <stdio.h>

// // Using recursion
// int Power(int x, int y)
// {
//   if (y == 0)
//   {
//     return 1;
//   }

//   return x * power(x, y - 1);
// }

// Using exponentiation by squaring
int power(int base, int exp)
{
  int result = 1;

  while (exp)
  {
    if (exp & 1)
    {
      result *= base;
    }

    exp >>= 1;

    base *= base;
  }

  return result;
}

int main()
{
  int base, exp;

  printf("Enter base: ");
  scanf("%i", &base);

  printf("Enter exp: ");
  scanf("%i", &exp);

  printf("Result: %i", power(base, exp));

  return 0;
}