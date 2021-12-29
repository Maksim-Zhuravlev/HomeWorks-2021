#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256


size_t strLen(const char* str)
{
    return (*str) ? strLen(++str) + 1 : 0;
}

int strCmp(const char* str_1, const char* str_2) {
    int len_str_1, len_str_2;
    len_str_1 = strLen(str_1);
    len_str_2 = strLen(str_2);

    if (len_str_1 > len_str_2) {
        return 1;
    }
    else if (len_str_1 < len_str_2) {
        return -1;
    }
    else {
        for (int i = 0; i < len_str_1; i++) {
            if (str_1[i] != str_2[i]) {
                if (str_1[i] > str_2[i]) {
                    return 1;
                }
                if (str_1[i] < str_2[i]) {
                    return -1;
                }
            }
        }
        return 0;
    }
}

void strCpy(char* str_1, char* str_2) {
    int i = 0;

    while (str_1[i] != '\0') {
        str_1[i] = str_2[i];
        i++;
    }
    str_1[i] = str_2[i];
}

char* strCat(char* dest, const char* src) {
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    do {
        dest[i] = src[j];
        i++;
        j++;
    } while (src[j] != '\0');

    return dest;
}


int main() {
	char str1[MAX_LEN];
    printf("Enter your first string:\n");
	scanf("%s", str1);
	char str2[MAX_LEN];
    printf("Enter your second string:\n");
	scanf("%s", str2);

    printf("Lenght of the string 1 = %u\n",strLen(str1));
    printf("The result of strCmp = %d\n", strCmp(str1, str2));
    strCpy(str1, str2);
    printf("The result of strCpy = %s\n", str1);
    printf("The result of strCat = %s\n", strCat(str1, str2));
	
	
	
	return 0;
}