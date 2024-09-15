#include<stdio.h>
#include<string.h>
#define MAX_LEN 256

int myStrlen(const char* str) {
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len += 1;
	}
	return len;
}

int myStrcmp(const char* str1, const char* str2) {
	if (myStrlen(str1) > myStrlen(str2)) {
		return 1;
	}
	if (myStrlen(str1) < myStrlen(str2)) {
		return -1;
	}
	for (int i = 0; i < myStrlen(str1); i++) {
		if ((int)str1[i] < (int)str2[i]) {
			return -1;
		}
		if ((int)str1[i] > (int)str2[i]) {
			return 1;
		}
	}
	return 0;
}

void myStrcpy(const char* str1, char* str2) {
	int i;
	for (i = 0; str1[i] != '\0'; i++)
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';
}

void myStrcat(char* str1, const char* str2) {
	int i, len = myStrlen(str1);
	for (i = 0; str2[i] != '\0'; i++) {
		str1[i + len] = str2[i];
	}
	str1[i + len] = '\0';
}

int main() {
	char s1[MAX_LEN] = "Hello";
	char s2[MAX_LEN] = "Everybody";
	char s3[MAX_LEN] = "Hello";
	char s4[MAX_LEN] = "Everybody";
	printf("The strings are: %s, %s \n", s1, s2);
	printf("Lengths are %d and %d \n", myStrlen(s1), myStrlen(s2));
	printf("myStrcmp's working result: %d \n", myStrcmp(s1, s2));
	myStrcpy(s1, s2);
	printf("Strings after myStrcpy's work: %s and %s \n", s1, s2);
	myStrcat(s3, s4);
	printf("Strings after myStrcat's work: %s and %s \n", s3, s4);
}