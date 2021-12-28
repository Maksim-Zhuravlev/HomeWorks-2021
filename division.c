#include <stdio.h>

#define MAX_LEN 256

int strlen(const char *Str) {
    if(Str == NULL)
    {
        return -1;
    }
    int i = 0;
    while (Str[i] != '\0')
    {
        i++;
    }
    return i;
}

int strcmp(const char *str1, const char *str2) {
    if (str1 == NULL && str2 != NULL) {
        return -1;
    } else if (str2 == NULL && str1 != NULL) {
        return 1;
    } else if (str1 == NULL && str2 == NULL){
        return 0;
    }

    int i = 0;
    while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
    {
        i++;
    }
    if (*(str1 + i) > *(str2 + i))
    {
        return 1;
    }
    else if (*(str1 + i) < *(str2 + i))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

char *strcpy(char * str1, const char * str2 ) {
    if(str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    char *p = str1;
    while((* str1++ = * str2++) != '\0');
    return p;
}

char *strcat(char *dest, const char *src) {
    char *rdest = dest;

    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return rdest;
}

int main() {
    char str1[MAX_LEN]; str1[0] = '\0';
    char str2[MAX_LEN]; str1[0] = '\0';
    scanf("%s", str1);
    scanf("%s", str2);
    int a = strcmp(str1, str2);
    char g[10]={"abc"}, b[10]={"def"};
    strcat(g,b);
    printf("%s",g);
    getchar();

    return 0;
}