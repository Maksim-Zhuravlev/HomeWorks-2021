#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

int sign_of_x(int x) {  /* Вспомогательная функция для второго задания */
	if (x > 0) {
		return 1;
	} else {
		return -1;
	}
}

/*----------------- Первое задание ----------*/

int my_strlen(char str[MAX_LEN]) {
	int i = 0;
	
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

int my_strcmp(char str1[MAX_LEN], char str2[MAX_LEN]) {
	int result;
	
	if (str1 == str2) {
		result = 0;
	} else if (str1 > str2) {
		result = 1;
	} else {
		result = -1;
	}
	return result;
}

void my_strcpy(char dest[MAX_LEN], char src[MAX_LEN]) {
	int len_of_src = strlen(src);
	
	for (int i = 0; i <= len_of_src; i++) {
		dest[i] = src[i];
	}
}

void my_strcat(char dest[MAX_LEN], char addition[MAX_LEN]) {
	int len_of_dest = strlen(dest);
	int len_of_addition = strlen(addition);
	
	if ((len_of_dest + len_of_addition) < MAX_LEN) {
		int index_of_conc = len_of_dest;
		
		for (int i = 0; i < len_of_addition; i++) {
			dest[index_of_conc + i] = addition[i];
		}
	} else {
		printf("Too long strings\n");
	}
}

/*-------------- Второе задание -------------------*/

int division(int divisor, int divident) {
	int result = 0;
	int sign = sign_of_x(divisor) * sign_of_x(divident);
	
	if (divisor == 0) {
		printf("Error zero divisor");
		return 0;
	}
	if(divident == INT_MIN && divisor == -1) {
		printf("Overflow");
		return 0;
	}
	if (divident % divisor != 0) {
		return 0;
	}
	if (divident == divisor) {
		return 1;
	}
	if (divident == INT_MIN) {
		divisor *= sign;
		while (divident - divisor <= 0) {
			divident -= divisor;
			result ++;
		}
	} else {
		divident = abs(divident);
		divisor = abs(divisor);
		while (divident - divisor >= 0) {
			divident -= divisor;
			result ++;
		}
		result *= sign;
	}
	return result;
}

/*----------------------------------------*/

int main(void) {
	return 0;
}