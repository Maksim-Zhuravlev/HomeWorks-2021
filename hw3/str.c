#include <stdio.h>
#include  <string.h>
#include <malloc.h>

int  my_strlen(char *str) {
    int s = 0;
    while (str[s] != '\0') {
        s++;
    }
    return s;
}

int  my_strcmp(char *str, char *str2) {
    int len = my_strlen(str);
    int len2 = my_strlen(str2);
    int flag = 0;
    if (my_strlen(str) > my_strlen(str2)) {
        return 1;
    } else if (my_strlen(str) < my_strlen(str2)) {
        return -1;
    } else {
        for (int i = 0; i < len; ++i) {
            if (str[i] != str2[i]) {
                if (str[i] > str2[i]) {
                    flag = 1;
                } else { flag = -1; }
            }
        }
    }
    return flag;
}

char *my_strcpy(char *str, char *str1) {
    int j = 0;
    for (int i = 0; i < (my_strlen(str1)) && str1[i] != '\0'; i++) {
        str[i] = str1[i];
        j++;
    }
    for (int i = (j); i < my_strlen(str); i++) {
        str[i] = '\0';
    }
    return str;
}

char * my_strcat(char *str, char *str1) {
    int g = (my_strlen(str) + my_strlen(str1) + 1);
    char *result = malloc(g);
    int kol = 0;
    for (int i = 0; i < g; ++i) {
        if (i < my_strlen(str)) {
            result[i] = str[i];
        } else {
            result[i] = str1[kol];
            kol++;
        }

    }
    return result;
}

int main() {
    int res;
    char str[] = "";
    res =  my_strlen(str);
    printf("Result: %i \n", res);

    char str1[] = "1234";
    char str2[] = "1234";
    res =  my_strcmp(str1, str2);
    printf("Result: %i \n", res);

    char str3[] = "good dog";
    char str4[] = "good cat";
    printf("Result: %s \n",  my_strcpy(str3, str4));

    char str7[] = "gooddog";
    char str8[] = " googcat ";
    printf("Result: %s \n",  my_strcat(str7, str8));
    return 0;
}
