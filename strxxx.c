#include <stdio.h>
#define SIZE 100

int myStrlen(const char *str1) {
    int s = 0;
    while (str1[s] != '\0') {
        s++;
    }
    return s;
}

char myStrcpy(char *str3, char *str4) {
    int i = 0;
    if (myStrlen(str3) > myStrlen(str4)) {
        while(str3[i] != '\0') {
            str3[i] = str4[i];
            i++;
        }
    }
    else {
        while(str3[i] != '\0') {
            str3[i] = str4[i];
            i++;
        }
    }
    return *str3;
}

char *myStrcat(char *str1, char *str2) {
    printf("%s%s\n", str1, str2);
    return "";
}

int myStrcmp(const char *str5, const char *str6) {
    for(int i = 0; ; i++) {
        if(str5[i] > str6[i]) {
            return 1;
        }
        else if(str5[i] < str6[i]) {
            return -1;
        }
        if(str5[i] == '\0') {
            return 0;
        }
    }
}


int main() {
    char str1[] = "My home";
    char str2[] = "town";
    myStrlen(str1);
    printf("Size of string: %d\n", myStrlen(str1));
    myStrcat(str1, str2);
    char str3[] = "Me";
    char str4[] = "Not me";
    myStrcpy(str3, str4);
    printf("My strcpy: %s\n", str3);
    char str5[] = "My hometown";
    char str6[] = "My home";
    myStrcmp(str5, str6);
    printf("My strcmp: %d", myStrcmp(str5, str6));
    return 0;
}
