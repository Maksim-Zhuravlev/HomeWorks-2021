#include <ctype.h>
#include "hashTable.h"


const char alphabet[94] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÜÚÛİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷ùøüúûışÿabcdefghijklmnopqrstuvwxyz-'";


int validChar(char symb) {
	int isValid = 0;
	symb = tolower(symb);
	
	for (int i = 0; i <= 93; i++) {
		if (symb == alphabet[i]) {
			isValid = 1;
			break;
		}
	}
	return isValid;
}

void cleanString(char *str, int length) {
	char *end = str + length;
	
	while (str < end) {
		*str = '\0';
		str++;
	}
}

void stringHandler(HashTable *table, char str[STR_LENGTH]) {
	char curWord[MAX_WORD_LENGTH];
	int curStrCharCounter = 0;
	int curWordCharCounter = 0;
	int wordIsRecording = 0;
	char curChar = str[curStrCharCounter];
	
	while (curChar != '\0') {
		if (validChar(curChar)) {
			curWord[curWordCharCounter] = curChar;
			wordIsRecording = 1;
			curWordCharCounter++;
		} else {
			if (wordIsRecording) {
				wordIsRecording = 0;
				curWord[curWordCharCounter] = '\0';
				countWord(table, curWord);
				cleanString(curWord, curWordCharCounter);
				curWordCharCounter = 0;
			}
		}
		curStrCharCounter++;
		curChar = str[curStrCharCounter];
	}
	if (wordIsRecording == 1) {
		countWord(table, curWord);
	}
}