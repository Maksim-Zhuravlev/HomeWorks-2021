#include <stdio.h>
#include <stdlib.h>

void other()
{
  printf("Success: Buffer overflow attack!\n");
  exit(1);
}

void input()
{
  int arr[2];
  int num = 0;

  printf("Enter the 1st number: ");
  scanf("%i", &num);
  arr[0] = num;

  printf("Enter the 2nd number: ");
  scanf("%i", &num);
  arr[1] = num;

  printf("Enter the 3rd number: ");
  scanf("%i", &num);
  arr[2] = num;

  printf("Enter the 4th number: ");
  scanf("%i", &num);
  arr[3] = num;

  printf("Enter the 5th number (Enter the address of other() here): ");
  scanf("%i", &num);

  if (num != 0)
  {
    arr[4] = num;
  }
}

int main()
{
  printf("Memory address of other(): %lu\n", (long)other);
  input();
  printf("The program is totally safe lol\n");

  return 0;
}