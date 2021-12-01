#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*5 Напишите программу, возводящую число a в целочисленную степень n*/
int exponentiation(int num, int n) {
    int res = n;
    for (int i = 0; i < num - 1; i = i + 1) {
        res = res * n;
    }
    return res;
}


/*6. Напишите программу, определяющую знак (+/-/0) произведения всех элементов массива целых чисел.*/
void sig(int *x, int n) {
    int i, k;
    k = 1;
    for (i = 0; i < n; i++) {
        k = k * x[i];
    }
    if (k == 0) {
        printf("%d \n", k);
    } else if (k > 0) {
        printf("+ \n");
    } else {
        printf("- \n");
    }
}

/*8. Напишите программу, печатающую все простые числа, не превосходящие заданногочисла.*/
int examination2(int g1) {
    int g = 0;
    for (int i = 2; i < (g1 + 1) / 2; ++i) {
        if (g1 % i == 0) {
            g = 1;
            break;
        }
    }
    return g;
}

void simple(int n) {
    for (int i = 1; i < (n + 1); ++i) {
        if (examination2(i) == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

}

/*7. Напишите программу, определяющую является строка палиндромом: словом или текстом, одинаково читающимся в обоих направлениях.*/
void polydrome(char *str) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            str[j] = tolower((str[i]));
            j++;
        }

    }
    for (int i = (j); i < strlen(str); i++) {
        str[i] = '\0';
    }
    int len = strlen(str);
    int el;
    char str2[len];
    int h = 0;
    for (el = (len - 1); el >= 0; el--) {
        str2[h] = str[el];
        h++;
    }
    str2[len] = 0;
    if (strcmp(str, str2) == 0) {
        printf("%s", "str is palindrome \n");
    } else { printf("%s", "str is not palindrome \n"); }
}

/*9. Заданы две строки: S и S1. Найдите количество вхождений S1 в S как подстроки.*/
int substring(char *str, char *str2) {
    int len = strlen(str);
    int len2 = strlen(str2);
    int c = 0;
    int flag = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == str2[0]) {
            for (int j = 1; j < len2; ++j) {
                if (str[i + j] != str2[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                flag = 3;
            } else { flag = 0; }
        }
        if (flag == 3) {
            c++;
            flag = 0;
        }

    }
    return c;
}


/*10. Числа Фибоначчи определяются следующим образом:*/
int fib(int g) {
    int num1 = 1;
    int num2 = 2;
    int b;
    for (int i = 3; i <= (g - 1); i++) {
        b = num1;
        num1 = num2;
        num2 = b + num1;
    }
    return num1;

}

int main() {
    int a, n, res;
    a = n = 0;
    printf("Input two numbers for the function exponentiation: ");
    scanf("%i %i", &a, &n);
    res = exponentiation(n, a);
    printf("Result: %i \n", exponentiation(n, a));

    printf("Sign of all elements in an array: ");
    int mas[10] = {2, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sig(mas, 10);

    printf("Palindrome string or not: ");
    char str[] = "I prefer Pis";
    polydrome(str);

    printf("Prime numbers: ");
    simple(10);

    printf("Number of occurrences of a string: ");
    char str1[] = "rip";
    char str2[] = "riripripripr";
    res = substring(str2, str1);
    printf("Result: %i \n", res);

    printf("Fibonacci number: ");
    printf("%d", fib(30));
    return 0;
}
