#include <stdio.h>

#define MAX_LEN 256

int strlen(char str[MAX_LEN]) {
	int count = 0;
	while (str[count] != 0) {
		count++;
	}
	return count;
}

int strcmp(char str1[MAX_LEN], char str2[MAX_LEN]) {
	int res = 0;
	int i = 0;
	while (str1[i] != 0 && str2[i] != 0) {
		res = str1[i] - str2[i];
		if (res != 0) {
			break;
		}
		i++;
	}
	if (res == 0) {
		if (strlen(str1) != strlen(str2)) {
			if (strlen(str1) > strlen(str2)) {
				res = -1;
			}
			else {
				res = 1;
			}
		}
	}
	return res;
}

int strcpy(char str1[MAX_LEN], char str2[MAX_LEN]) {
	int n = strlen(str2) + 1;
	for (int i = 0; i < n; i++) {
		str1[i] = str2[i];
	}
	return 0;
}

int strcat(char str1[MAX_LEN], char str2[MAX_LEN]) {
	int n = strlen(str1);
	int i = 0;
	while (str2[i] != 0) {
		str1[n + i] = str2[i];
		i++;
	}
	return 0;
}

int main() {
	return 0;
}