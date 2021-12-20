//Arian bagheri nezhad
//21.Б16.мм
//HomeWork 3.1_strxxx

/*This program shows my implementation of the functions 
for working with strings from the standard library:
- strlen,
- strcmp,
- strcpy,
- strcat.
Use strings of fixed length. For example, MAX_LEN 256.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void my_strlen (char *string);
void my_strcmp (char *string_one, char *string_two);
void my_strcpy (char *string_one, char *string_two);
void my_strcat (char *string_one, char *string_two);

int main ()
{
    char string_1[MAX_LEN] = "Hello world!";
    char string_2[MAX_LEN] = "Hello world!";
    char string_3[MAX_LEN] = "Good morning!";

    printf("\nThis program shows my implementation of ");
    printf("the functions for working with strings from ");
    printf("the standard library:\n- strlen,\n- strcmp,\n");
    printf("- strcpy,\n- strcat.\n");
    printf("Use strings of fixed length. For example, MAX_LEN ");
    printf("256.\n\n");

    printf("We have three strings:");
    printf("\nString_1: %s\n", string_1);
    printf("String_2: %s\n", string_2);
    printf("String_3: %s\n\n", string_3);

    //Strlen
    printf("Strlen\n");
    printf("Prints the size of each string:\n");
    my_strlen (string_1);
    my_strlen (string_2);
    my_strlen (string_3);
    printf("\n");

    //Strcmp
    printf("Strcmp\n");
    printf("Compares two strings with each other:\n");
    my_strcmp (string_1, string_2);
    my_strcmp (string_3, string_1);
    my_strcmp (string_2, string_3);
    printf("\n");

    //Strcpy
    printf("Strcpy\n");
    printf("Copies string_3 to string_1:\n");
    my_strcpy(string_1, string_3);
    printf("String_1: %s\n", string_1);
    printf("String_2: %s\n", string_2);
    printf("String_3: %s\n\n", string_3);

    //Strcat
    printf("Strcat\n");
    printf("Attaches the string_2 to the ");
    printf("end of the string_3:\n");
    my_strcat (string_3, string_2);
    printf("String_1: %s\n", string_1);
    printf("String_2: %s\n", string_2);
    printf("String_3: %s\n\n\n", string_3);

    printf("The end of the program!\n\n");
    return 0;
}

void my_strlen (char *string)
{
    int i;

    for (i = 0; string[i] != '\0'; i++);

    printf("Length of string_1: %d\n", i);
    
}

void my_strcmp (char *string_one, char *string_two)
{
    int result, i = 0;

    while (string_one[i] == string_two[i] && string_one[i] != '\0')
    {
        i++;
    }

    if (string_one[i] == '\0')
    {
        printf("'%s' the same '%s'\n", string_one, string_two);
    }
    else if (string_one[i] > string_two[i])
    {
        printf("'%s' more than '%s'\n", string_one, string_two);
    }
    else if (string_one[i] < string_two[i])
    {
        printf("'%s' less than '%s'\n", string_one, string_two);
    }

}

void my_strcpy (char *string_one, char *string_two)
{
    int i;

    for (i = 0; string_two[i] != '\0'; i++)
    {
        string_one[i] = string_two[i];
    }

    printf("string_3 copied in string_1.\n");

}

void my_strcat (char *string_one, char *string_two)
{
    int i, j;

    for (i = 0; string_one[i]; i++);
    string_one[i++] = ' ';

    for (j = 0; string_two[j] != '\0'; j++)
    {
        string_one[i] = string_two[j];
        i++;
    }

}