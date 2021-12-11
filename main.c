#include <stdio.h>
#define SIZE 100

int str_len(const char *str) {
    int s = 0;
    while (str[s] != '\0') {
        s++;
    }
    return s;
}

char str_cpy(char *str1, char *str2) {
    int i = 0;
    if (str_len(str1) > str_len(str2)) {
        while(str1[i] != '\0') {
            str1[i] = str2[i];
            i++;
        }
    }
    else {
        while(str2[i] != '\0') {
            str1[i] = str2[i];
            i++;
        }
    }
    return *str1;
}

char *str_cat(char *str1, char *str2) {
    printf("%s%s", str1, str2);
    return "";
}

char str_cmp(const char *str1, const char *str2) {
    for(int i = 0; ; i++) {
        if(str1[i] > str2[i]) {
            return 1;
        }
        else if(str1[i] < str2[i]) {
            return -1;
        }
        if(str1[i] == '\0') {
            return 0;
        }
    }
}


int main() {
    char str1[SIZE], str2[SIZE];
    printf("Enter your 1 string:");
    gets(str1);
    printf("Enter your 2 string:");
    gets(str2);
    printf("Length of the 1st: %d, of the 2nd: %d\n", str_len(str1), str_len(str2));
    printf("Strcat: ");
    printf("%s\n", str_cat(str1, str2));
    printf("Strcmp: %d\n", str_cmp(str1, str2));
    str_cpy(str1, str2);
    printf("Strcpy: 1st string - %s, 2nd string - %s\n", str1, str2);

    return 0;
}
