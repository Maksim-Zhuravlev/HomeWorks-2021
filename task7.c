#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *phrase, const unsigned int length)
{
  const char *left = phrase;
  const char *right = phrase + length - 1;

  while (left < right)
  {
    if (!isalnum(*left))
    {
      left++;
    }
    else if (!isalnum(*right))
    {
      right--;
    }
    else if (toupper(*left) == toupper(*right))
    {
      left++;
      right--;
    }
    else
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  const char str[] = "I prefer Pi";
  const int result = isPalindrome(str, strlen(str));

  if (result == 0)
  {
    printf("The string \"%s\" is a palindrome!", str);
  }
  else
  {
    printf("The string \"%s\" is not a palindrome!", str);
  }

  return 0;
}