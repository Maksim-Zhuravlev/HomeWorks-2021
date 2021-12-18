#define STR_LENGTH 1500
#define MAX_WORD_LENGTH 30


int hashFoo(char word[MAX_WORD_LENGTH]) {
	int s = 0;
	int i = 0;
	
	while (word[i] != '\0') {
		s += (int)word[i];
		i++;
	}
	
	return s;
}