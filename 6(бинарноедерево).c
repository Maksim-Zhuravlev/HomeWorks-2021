#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#define MAXWORD 100

struct tnode {
	char* word;
	int count;
	struct tnode* left;
	struct tnode* right;
};
char* strdup(char* s)
{
	char* p;
	p = (char*)malloc(strlen(s) + 1);
	if (p == NULL) {
		printf("error");
	}
	else
	{
		strcpy(p, s);
		return p;
	}
}
struct tnode* add_tree(struct tnode* p, char* w) {
	int cond;
	if (p == NULL) {
		p = (struct tnode*)malloc(sizeof(struct tnode));
		if (!p) {
			printf("error");
		}
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = add_tree(p->left, w);
	else
		p->right = add_tree(p->right, w);
	return p;
}

void tree_print(struct tnode* p) {
	int e = 0;
	if (p != NULL) {
		tree_print(p->left);
		printf("%d %s\n", p->count, p->word);
		tree_print(p->right);
	}
}
void free_tree(struct tnode* p) {
	if (p->left)   free_tree(p->left);
	if (p->right)  free_tree(p->right);
	free(p);
}
int height(struct tnode* p) {
	int l, r, h = 0;
	if (p != NULL) {
		l = height(p->left);
		r = height(p->right);
		h = ((l > r) ? l : r) + 1;
	}
	return h;
}
int loong(struct tnode* p) {
	int e = 0;
	if (p != NULL)
	{
		e = p->count;
		if (p->right != NULL) {
			if (loong(p->right) >= e)
			{
				e = loong(p->right);
			}
		}
	}
	if (p->left != NULL) {
		if (loong(p->left) >= e)
		{
			e = loong(p->left);
		}
	}
	return e;
}

void word(struct tnode* p, int t) {
	if (p != NULL)
	{
		word(p->left, t);
		if (p->left != NULL) {
			if (p->count == t) {
				printf("%s \n", p->word);
				t++;

			}
		}
		word(p->right, t);
		if (p->right != NULL) {
			if (p->count == t) {
				printf("%s \n", p->word);
				t++;
			}
		}
	}
}


int main() {
	int i = -1, w = 0, t;
	struct tnode* root;
	char data[30];
	root = NULL;
	FILE* file = NULL;
	setlocale(LC_ALL, "Rus");
	file = fopen("войнаимир.txt", "rt");
	if (file == NULL) {
		perror("Failed to open file WarandPeace.");
		exit(1);
	}
	while (!feof(file)) {
		i++;
		fscanf(file, "%s", data);
		if (isalpha(data[0]))
			root = add_tree(root, data);
		strcpy(data, "");
	}
	fclose(file);
	printf("%d \n", height(root));
	t = loong(root);
	word(root, t);
	printf("%d \n", t);
	tree_print(root);
	free_tree(root);
}