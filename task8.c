#include <stdio.h>

int isPrime(const int n)
{
  if (n == 0 | n == 1)
  {
    return 1;
  }

  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  const int num;

  printf("Enter number: ");
  scanf("%i", &num);

  const int result = isPrime(num);

  if (result)
  {
    printf("The number %i is not prime!", num);
  }
  else
  {
    printf("The number %i is prime!", num);
  }

  return 0;
}