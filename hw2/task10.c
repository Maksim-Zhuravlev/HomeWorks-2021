#include <stdio.h>

int fib(const int n)
{
  if (n <= 1)
  {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main()
{
  const int num;

  printf("Enter number: ");
  scanf("%i", &num);

  printf("Result: %i", fib(num));

  return 0;
}