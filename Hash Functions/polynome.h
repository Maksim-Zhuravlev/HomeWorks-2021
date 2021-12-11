#include <stdio.h>
#include <string.h>
//#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 30
#define STR_LENGTH 2000

int hashFoo(char *word) {
	const int k = 7;
	int hash = 0;
	int power = 0;
	char curChar = *word;
	
	while (curChar != '\0') {
		//curChar = (char)tolower((int)curChar);
		hash += (curChar) * (int)pow(k, power);
		curChar = *(word + power + 1);
		power++;
	}
	
	return hash;
}