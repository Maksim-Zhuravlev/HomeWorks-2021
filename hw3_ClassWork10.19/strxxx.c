#include<stdio.h>
#include<string.h>
#define MAX_LEN 256

int myStrlen(const char* str) {
	int len = 0;
	while (*str != 0) { //пока не встретим заканчивающий 0, увеличиваем значение длины и инкрементируем указатель
		++len;
		++str;
	}
	return len;
}

int myStrcmp(const char* str1, const char* str2) {
	while ((!(*str1 ^ *str2)) && (*str1) && (*str2)) { //пока текущие символы совпадают и не конец какой-то строки, инкрементируем указатели
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

char* myStrcpy(char* str1, const char* str2) {
	char* curr1 = str1;
	while (*str2) { // пока не конец строки 2 копируем текущий символ
		*curr1 = *str2;
		++curr1;
		++str2;
	}
	*curr1 = 0;
	return str1;
}

char* myStrcat(char* str1, const char* str2) {
	char* curr1 = str1;
	while (*curr1) ++curr1; //доходим до конца строки 1
	while (*str2) { // пока не конец строки 2 копируем текущий символ
		*curr1 = *str2;
		++curr1;
		++str2;
	}
	*curr1 = 0;
	return str1;
}

int main() {
	char s1[MAX_LEN] = "abgdbgxfbgx";
	char s2[MAX_LEN] = "Hello";
	printf("%s", myStrcat(s1, s2));
}