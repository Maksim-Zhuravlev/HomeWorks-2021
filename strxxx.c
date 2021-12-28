#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void str_len (char *string);
void str_cmp (char *string1, char *string2);
void str_cpy (char *string1, char *string2);
void str_cat (char *string1, char *string2);

int main(){
    char string_1[MAX_LEN] = "How are you?";
    char string_2[MAX_LEN] = "How are you?";
    char string_3[MAX_LEN] = "What are you doing?";
    
    printf("Strings\n\n");

    str_len (string_1);
    str_len (string_2);
    str_len (string_3);
    printf("\n");

    str_cmp (string_1, string_2);
    str_cmp (string_2, string_3);
    str_cmp (string_3, string_1);
    printf("\n");

    printf("strcpy copies String_3 to String_1\n");
    str_cpy (string_1, string_3);
    printf("strcpy(String_1, String_3) = %s\n", string_1);
    printf("String_2: %s\n", string_2);
    printf("String_3: %s\n\n", string_3);

    printf("strcat concetenates String_2 onto the end of String_3\n");
    str_cat (string_3, string_2);
    printf("String_1: %s\n", string_1);
    printf("String_2: %s\n", string_2);
    printf("strcat(String_3, String_2) = %s\n", string_3);
    return 0;
}

void str_len (char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++);
    printf("strln( %s ) = %d\n", string, i);
}

void str_cmp (char *string1, char *string2){
    int i = 0;
    while(string1 == string2 && string1 != '\0'){
        i++;
    }
    
    if (string1[i] > string2[i] ){
        printf("strcmp(%s , %s) = 1\n",string1, string2 );
    } else if ( string1[i] < string2[i] ){
        printf("strcmp(%s , %s) = -1\n", string1, string2);
    } else {
        printf("strcmp(%s , %s) = 0\n", string1, string2);
    }
}

void str_cpy (char *string1, char *string2){
    int i;
    for (i = 0; string2[i] != '\0'; i++){
        string1[i] = string2[i];
    }

}

void str_cat (char *string1, char *string2){
    int i, j;

    for (i = 0; string1[i]; i++);
    string1[i++] = ' ';

    for (j = 0; string2[j] != '\0'; j++){
        string1[i] = string2[j];
        i++;
    }

}
    
