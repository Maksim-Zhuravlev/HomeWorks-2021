#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1 [100], string2 [100];
    puts ("please enter a string :");
    gets (string1);
    strcpy (string2 , string1);
    puts (string2);
    strrev (string2);
    int n = strcmp (string1, string2);
    if (n==0){
        printf ("we can read this sentence from the right or the left.");
    }
    else {
        printf ("we can not read it.");
    }

    return 0;
}
