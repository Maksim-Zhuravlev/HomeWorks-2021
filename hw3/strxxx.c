#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

unsigned int strLen(const char *str)
{
  unsigned int length = 0;

  while (str[length] != '\n')
  {
    length++;
  }

  return length;
}

// // Demonstration of strLen
// int main()
// {
//   char string[MAX_LEN];

//   printf("Enter string: ");
//   fgets(string, MAX_LEN, stdin);

//   printf("Result: %i\nString", strLen(string));

//   return 0;
// }

int strCmp(const char *str1, const char *str2)
{
  while (*str1 && (*str1 == *str2))
  {
    str1++, str2++;
  }
  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

// // Demonstration of strCmp
// int main()
// {
//   char string1[MAX_LEN];
//   char string2[MAX_LEN];

//   printf("Enter string: ");
//   fgets(string1, MAX_LEN, stdin);

//   printf("Enter string: ");
//   fgets(string2, MAX_LEN, stdin);

//   printf("Result: %i\nString 1: %s\nString 2: %s", strCmp(string1, string2), string1, string2);

//   return 0;
// }

char *strCpy(char *source, char *destination)
{
  char *result = destination;

  while (*source != '\0')
  {
    *destination = *source;
    source++;
    destination++;
  };

  *destination = '\0';

  return result;
}

// // Demonstration of strCpy
// int main()
// {
//   char string1[MAX_LEN];
//   char string2[MAX_LEN];

//   printf("Enter string: ");
//   fgets(string1, MAX_LEN, stdin);

//   printf("Enter string: ");
//   fgets(string2, MAX_LEN, stdin);

//   printf("Result: %s\nString 1: %s\nString 2: %s", strCpy(string1, string2), string1, string2);

//   return 0;
// }

char *strCat(char *source, char *destination)
{
  char *ptr = destination + strLen(destination);

  while (*source != '\0')
  {
    *ptr = *source;
    *ptr++;
    *source++;
  }

  *ptr = '\0';

  return destination;
}

// // Demonstration of strCat
// int main()
// {
//   char string1[MAX_LEN];
//   char string2[MAX_LEN];

//   printf("Enter string: ");
//   fgets(string1, MAX_LEN, stdin);

//   printf("Enter string: ");
//   fgets(string2, MAX_LEN, stdin);

//   printf("Result: %s\nString 1: %s\nString 2: %s", strCat(string1, string2), string1, string2);

//   return 0;
// }