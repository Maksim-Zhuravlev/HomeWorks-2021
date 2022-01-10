#include <stdio.h>
#include <stdlib.h>

char *productSign(const int *arr, const int size)
{
  int result = 1;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 0)
    {
      return "0";
    }
    else if (arr[i] < 0)
    {
      result *= -1;
    }
  }

  return result > 0 ? "+" : "-";
}

int main()
{
  int size;
  printf("Enter the size of the array: ");
  scanf("%i", &size);

  if (size <= 0)
  {
    printf("Invalid array size!\n");
    exit(1);
  }

  int array[size];

  printf("Enter array elements one by one:\n");
  for (int i = 0; i < size; i++)
  {
    scanf("%i", &array[i]);
  }

  char *sign = productSign(array, size);
  printf("The sign is: %s", sign);

  return 0;
}