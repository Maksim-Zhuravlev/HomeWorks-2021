//HomeWork_3_1_strxxx
//Arian Bagheri Nezhad
//21. Б 16 мм

#include <stdio.h>
#include <string.h>

#define MAX 256

int main ()
{
    //strlen

    char char1[MAX];
    int len;

    printf("\nPlease enter a string. This program by strlen");
    printf(" calculates the length of the string and ");
    printf("prints it for you.\n");

    printf("Please enter a string:\n");

    gets(char1);

    len = strlen(char1);

    printf("The length of the string is: %d\n\n", len);

    //strcmp

    char char2[MAX];
    char char3[MAX];

    printf("Please enter two strings. This program by strcmp ");
    printf("compares the two strings and checks whether ");
    printf("the two strings are the same and prints the result for you.\n");

    printf("Please enter string1:\n");

    gets(char2);

    printf("\nPlease enter string2:\n");

    gets(char3);

    if (strcmp(char2, char3))
    {
        printf("\nString1 ana string2 are NOT same.\n");
    }
    else 
    {
        printf("\nString1 ana string2 are same.\n\n");
    }

    //strcpy

    char char4[MAX];
    char char5[MAX];

    printf("Please enter two strings. This program by strcpy will copy ");
    printf("the string you entered into another string, and \n");
    printf("as a result the contents of the other string will ");
    printf("be lost and both strings will be the same.\n");

    printf("Please enter string1(for example, your first name):\n");

    gets(char4);

    printf("\nPlease enter string2(for example, your last name):\n");

    gets(char5);

    printf("\nNow see the contents of string1 and string2:\n");
    printf("string1: %s\n", char4);
    printf("string2: %s\n", char5);
    printf("Now we copy string 2 to string 1 by strcpy. As a ");
    printf("result, the contents of the string2 (where your\n");
    printf("last name is) are copied to the string1 (where your first name is) ");
    printf("and the contents of the first string are deleted and both strings \n");
    printf("will have the same contents (string2).\n");
    printf("result:\n");

    strcpy(char4, char5);

    printf("string1: %s\n", char4);
    printf("string2: %s\n\n", char5);

    //strcat

    char char6[MAX / 2];
    char char7[MAX / 2];

    printf("Please enter two strings (preferably your first name for the first string ");
    printf("and your last name for the second string). This program by strcat will put\n");
    printf("the second string at the end of the first string and put your first and last ");
    printf("name in one string and print it.\n");
    printf("Please enter string1(preferably your first name):\n");
    printf("(Please enter a space after entering the string, then enter)\n");

    gets(char6);

    printf("Please enter string2(preferably your last name):\n");

    gets(char7);

    strcat(char6, char7);

    printf("result:\nstring1: %s\n\n", char6);

    printf("\nThe end of program.\n\n");

    return 0;
}