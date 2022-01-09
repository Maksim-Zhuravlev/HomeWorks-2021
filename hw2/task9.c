#include <stdio.h>
#include <string.h>

int substringCount(const char *haystack, const char *needle)
{
  int count = 0;
  const char *tmp = haystack;

  while (tmp = strstr(tmp, needle))
  {
    count++;
    tmp++;
  }

  return count;
}

int main()
{
  const char haystack[] = "How about a couple of rounds of Gwent?";
  const char needle[] = "ou";

  printf("Result: %i", substringCount(haystack, needle));

  return 0;
}