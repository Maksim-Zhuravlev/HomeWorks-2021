#include "binaryTree.h"
#include <ctype.h>

const char alphabet[186] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЫЭЮЯабвгдеёжзийклмнопрстуфхцчшщъьыэюяabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'";


int validChar(char symb) {
	int isValid = 0;
	symb = tolower(symb);
	
	for (int i = 0; i <= 185; i++) {
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

void stringHandler(BinaryTree *tree, char str[STR_LENGTH]) {
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
				wordHandler(tree, curWord);
				cleanString(curWord, curWordCharCounter);
				curWordCharCounter = 0;
			}
		}
		curStrCharCounter++;
		curChar = str[curStrCharCounter];
	}
	if (wordIsRecording == 1) {
		wordHandler(tree, curWord);
	}
}