#include <stdio.h>
#include <stdlib.h>


int my_strlen(char str[100]){
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}


int my_strcmp(char str1[100], char str2[100]){

    for (int i = 0; ((str1[i] != '\0') && (str2[i] != '\0')); i++)
    {
        if ( str1[i] > str2[i] )
        {
            return 1;
        }
        if ( str1[i] < str2[i] )
        {
            return -1;
        }
    }

    return 0;
}


char* my_strcpy(char str1[100], char str2[100]){
    int i = 0;

    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }

    str1[i] = '\0';

    return str1;
}


char* my_strcat(char str1[100], char str2[100]){
    int start = 0;

    while (str1[start] != '\0')
    {
        start++;
    }

    int i = 0;

    while ( str2[i] != '\0' )
    {
        str1[start + i] = str2[i];
        i++;
    }

    str2[start] = '\0';

    return str1;
}



int main()
{
    char str1[100];
    char str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%d \n", my_strlen(str1));
    printf("%d \n", my_strcmp(str1, str2));
    printf("%s \n", my_strcpy(str1, str2));
    printf("%s \n", my_strcat(str1, str2));


    return 0;
}
