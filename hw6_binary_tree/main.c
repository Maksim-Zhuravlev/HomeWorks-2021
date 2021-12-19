#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include"binary_tree.h"

size_t get_word(FILE* in, char* word) {
	char* locale = setlocale(LC_ALL, "");
	char c = getc(in);
	while (!(((c >= 'à') && (c <= 'ÿ')) || ((c >= 'À') && (c <= 'ß')) || (c == '¸') || (c == '¨'))) {
		if (feof(in)) {
			word[0] = 0;
			return EOF;
		}
		c = getc(in);
	}
	size_t pos = 0;
	while ((((c >= 'à') && (c <= 'ÿ')) || ((c >= 'À') && (c <= 'ß')) || (c == '¸') || (c == '¨'))) {
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

struct segment { // segment of queue
	size_t hight;
	struct binary_tree_node* node;
	struct segment* next;
};

void statistic(struct binary_tree* tree) {
	size_t nodes_num = 0, hight = 0;
	struct payload the_most_freq_word = { .value = 0 };
	if (!tree->root) {
		printf("nodes num = %d, hight = %d\n", 0, 0);
		printf("the most frequent word not exist\n");
		return;
	}

	struct segment* head = malloc(sizeof(struct segment));
	if (!head) {
		perror("main statistic: Not enough memmory for head");
		exit(1);
	}
	*head = (struct segment){ .hight = 1, .node = tree->root, .next = NULL };
	struct segment* tail = head;

	while (head) {
		struct binary_tree_node* node = head->node;
		size_t head_hight = head->hight;
		if (node->right) {
			tail->next = malloc(sizeof(struct segment));
			if (!tail->next) {
				perror("main statistic: Not enough memmory for tail");
				exit(1);
			}
			*(tail->next) = (struct segment){ .hight = head_hight + 1, .node = node->right, .next = NULL };
			tail = tail->next;
		}
		if (node->left) {
			tail->next = malloc(sizeof(struct segment));
			if (!tail->next) {
				perror("main statistic: Not enough memmory for tail");
				exit(1);
			}
			*(tail->next) = (struct segment){ .hight = head_hight + 1, .node = node->left, .next = NULL };
			tail = tail->next;
		}
		++nodes_num;
		hight = head->hight;

		if (node->data.value > the_most_freq_word.value) {
			the_most_freq_word = node->data;
		}

		struct segment* saved = head->next;
		free(head);
		head = saved;
	}

	printf("nodes num = %d, hight = %d\n", nodes_num, hight);
	printf("the most frequent word: %s, %d occurrences\n", the_most_freq_word.key, the_most_freq_word.value);
}

int main() {
	char* locale = setlocale(LC_ALL, "");

	FILE* in = NULL;
	in = fopen("text.txt", "rt");
	if (in == NULL) {
		perror("main: failed to open file text.txt");
		exit(1);
	}

	struct binary_tree tree = create_binary_tree();

	char word[max_word_length + 1];
	while (!feof(in)) {
		get_word(in, word);
		set_value(&tree, word, get_value(&tree, word, 0) + 1);
	}
	statistic(&tree);

	clear_binary_tree(&tree);

	fclose(in);

	return 0;
}