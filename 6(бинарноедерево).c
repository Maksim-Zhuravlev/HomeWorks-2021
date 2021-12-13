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
	if (p != NULL)
		strcpy(p, s);
	return p;
}
struct tnode* addtree(struct tnode* p, char* w) {
	int cond;
	if (p == NULL) {
		p = (struct tnode*)malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode* p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
int Height(struct tnode* p) {
	int l, r, h = 0;
	if (p != NULL) {
		l = Height(p->left);
		r = Height(p->right);
		h = ((l > r) ? l : r) + 1;
	}
	return h;
}
int main() {
	int i = -1, w = 0;
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
			root = addtree(root, data);
		strcpy(data, "");
	}
	fclose(file);
	printf("%d \n", Height(root));
	treeprint(root);
}