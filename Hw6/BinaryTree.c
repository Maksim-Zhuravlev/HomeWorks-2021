#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <locale.h>

//===================== specific part=========================

#define MAX_WORD_LENGTH 30


size_t getHash(char key[MAX_WORD_LENGTH]) {

	size_t res = 0;
	size_t pos = 0;

	while (key[pos]) {
		res += (size_t)key[pos] * (size_t)pow(3, pos);
		pos++;
	}

	return res;
}

_Bool compareKeys(char key1[MAX_WORD_LENGTH], char key2[MAX_WORD_LENGTH]) {
	return !strcmp(key1, key2);
}

char* wordWithoutSigns(char word[MAX_WORD_LENGTH]) {
	static char newWord[MAX_WORD_LENGTH];
	int n = 0;
	for (size_t k = 0; k <= strlen(newWord); k++) {
		if (word[k] != '(' && word[k] != ')' && word[k] != '.' && word[k] != ',' && word[k] != ';' && word[k] != ':'
			&& word[k] != '\'' && word[k] != '\"' && word[k] != '!' && word[k] != '?' && word[k] != '-'
			&& word[k] != '[' && word[k] != ']' && word[k] != '{' && word[k] != '}' && word[k] != '<' && word[k] != '>') {
			newWord[n] = word[k];
			n++;
		}
	}
	return newWord;
}


//===================== common part =========================\


struct Node {
	size_t hash;
	size_t stage;
	int value;
	char key[MAX_WORD_LENGTH];
	struct Node* rightNode;
	struct Node* leftNode;

};

struct BinaryTree {
	struct Node* root;
	size_t height;
};


struct Node* getNode(char key[MAX_WORD_LENGTH], int value) {
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL) {
		perror("Not enough memory");
		exit(1);
	}
	res->hash = getHash(key);
	res->value = value;
	strcpy(res->key, key);
	res->stage = 1;
	res->rightNode = NULL;
	res->leftNode = NULL;

	return res;
}

void addNode(struct BinaryTree* tree, char key[MAX_WORD_LENGTH], int value) {
	struct Node* node = getNode(key, value);
	if (tree->root == NULL) {
		tree->root = node;
	}
	else {
		struct Node* curr = tree->root;
		while (1) {
			if (node->hash < curr->hash) {
				if (curr->leftNode != NULL) {
					curr = curr->leftNode;
					node->stage++;
				}
				else {
					node->stage++;
					curr->leftNode = node;
					break;
				}

			}
			else {
				if (curr->rightNode != NULL) {
					curr = curr->rightNode;
					node->stage++;
				}
				else {
					node->stage++;
					curr->rightNode = node;
					break;
				}
			}
		}
	}
	if (node->stage > tree->height) {
		tree->height = node->stage;
	}
}


struct Node* findNode(struct BinaryTree* tree, char key[MAX_WORD_LENGTH]) {
	struct Node* curr = tree->root;
	size_t hash = getHash(key);
	while (curr != NULL) {
		if (hash < curr->hash) {
			curr = curr->leftNode;
		}
		else {
			if (compareKeys(key, curr->key)) {
				break;
			}
			curr = curr->rightNode;
		}
	}
	return curr;
}

void printTree(struct Node* node, FILE* result) {

	fprintf(result, "Слово: %s, Количество: %d\n", node->key, node->value);

	if (node->leftNode != NULL) {
		printTree(node->leftNode, result);
	}
	if (node->rightNode != NULL) {
		printTree(node->rightNode, result);
	}
}

void clearNodes(struct Node* curr) {

	if (curr->leftNode != NULL) {
		clearNodes(curr->leftNode);
	}
	if (curr->rightNode != NULL) {
		clearNodes(curr->rightNode);
	}
	free(curr);

}

void clearTree(struct BinaryTree** ptree) {
	struct BinaryTree* tree = *ptree;

	clearNodes(tree->root);
	free(*ptree);
	*ptree = NULL;

}

struct BinaryTree* createBinaryTree() {
	struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
	tree->root = NULL;
	tree->height = 0;
	return tree;
}

int getValue(struct BinaryTree* tree, char key[MAX_WORD_LENGTH], int defValue) {
	struct Node* node = findNode(tree, key);
	return node ? node->value : defValue;
}

void setValue(struct BinaryTree* tree, char key[MAX_WORD_LENGTH], int value) {
	struct Node* node = findNode(tree, key);
	if (node) {
		node->value = value;
	}
	else {
		addNode(tree, key, value);
	}
}

void WriteResult(FILE* textFile, FILE* resultFile) {

	char word[MAX_WORD_LENGTH];
	char newWord[MAX_WORD_LENGTH];

	struct BinaryTree* tree = createBinaryTree();

	while (fscanf(textFile, "%s", &word) == 1) {
		strcpy(newWord, wordWithoutSigns(word));
		setValue(tree, newWord, getValue(tree, newWord, 0) + 1);
	}

	fprintf(resultFile, "Высота дерева: %d\n\n", tree->height);
	printTree(tree->root, resultFile);
	fseek(textFile, 0, SEEK_SET);

	clearTree(&tree);
}


int main() {

	setlocale(LC_ALL, "Rus");

	FILE* text;
	FILE* result;

	result = fopen("result.txt", "w");
	if (result == NULL) {
		printf("The file could not be opened.");
		exit(1);
	}

	text = fopen("mertvye-dushi.txt", "r");
	if (text == NULL) {
		printf("The file could not be opened.");
		exit(1);
	}

	WriteResult(text, result);

	fclose(text);
	fclose(result);

	return 0;
}