#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include "hash_table.h"

void statistic(struct hash_table* table) {
	size_t max_len = 0, min_len = _CRT_SIZE_MAX, not_empty_num = 0, lens_sum = 0;
	for (size_t i = 0; i < table->size; ++i) {
		if ((table->buckets[i]).size) {
			if (max_len < (table->buckets[i]).size) {
				max_len = (table->buckets[i]).size;
			}
			if (min_len > (table->buckets[i]).size) {
				min_len = (table->buckets[i]).size;
			}
			++not_empty_num;
			lens_sum += (table->buckets[i]).size;
		}
	}
	printf("number of not empty chains = %d\n", not_empty_num);
	printf("average chain length = %d\n", (lens_sum / (table->size)));
	printf("min length = %d\n", min_len);
	printf("max length = %d\n", max_len);
	printf("%d\t%d\t%d\t%d\n", not_empty_num, (lens_sum / (table->size)), min_len, max_len);
	printf("------\n");
}

size_t get_word(FILE* in, char* word) {
	char* locale = setlocale(LC_ALL, "");
	char c = getc(in);
	while (!(((c >= '�') && (c <= '�'))||((c >= '�')&&(c<='�')) || (c == '�') || (c == '�'))) {
		if (feof(in)) {
			word[0] = 0;
			return EOF;
		}
		c = getc(in);
	}
	size_t pos = 0;
	while ((((c >= '�') && (c <= '�')) || ((c >= '�') && (c <= '�')) || (c == '�') || (c == '�'))) {
		if (feof(in)) {
			word[pos] = 0;
			return EOF;
		}
		word[pos] = c;
		++pos;
		c = getc(in);
		if (pos >= max_word_length) { //too long word
			perror("get_word: too long word");
			word[max_word_length] = 0;
			printf(word);
			exit(1);
		}
	}
	word[pos] = 0;
	return c;
}

int main() {
	char* locale = setlocale(LC_ALL, "");

	for (size_t i = 1; i <= 1e5; i *= 10) {
		FILE* in = NULL;
		in = fopen("text.txt", "rt");
		if (in == NULL) {
			perror("main: failed to open file text.txt");
			exit(1);
		}
		
		struct hash_table table = create_hash_table(i);
		char word[max_word_length + 1];
		while (!feof(in)) {
			get_word(in, word);
			set_value(&table, word, get_value(&table, word, 0));
		}
		statistic(&table);
		clear_hash_table(&table);
		
		fclose(in);
	}
}