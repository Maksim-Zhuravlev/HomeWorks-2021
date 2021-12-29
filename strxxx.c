#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 200


int my_strlen (char string [MAX_LEN]) {
	int i = 0;

	while (string [i] != '\0') {
		i++;
	}
	return i;
}

int my_strcmp(char string1 [MAX_LEN], char string2 [MAX_LEN]) {
	int comparaison ;

	if ( string1 == string2 ) {
		comparaison = 0;
	} else if ( string1 < string2 ) {
		comparaison = -1;
	} else {
		comparaison = 1;
	}
	return comparaison;
}

void my_strcpy(char stringA [MAX_LEN], char stringB [MAX_LEN]) {
	int x = strlen(stringA);

	for (int i = 0; i <= x ; i++) {
		stringB [i] = stringA [i];
	}
}
