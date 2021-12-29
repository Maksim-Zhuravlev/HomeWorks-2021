#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//===================== specific part =========================

#define MAX_WORD_LENGTH 100

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];

struct Payload {
	keyType key;
	valueType value;
};


void printPayload(struct Payload data) {
	printf("key = %s, value = %d\n", data.key, data.value);
}


int compareKeys(keyType key1, keyType key2) { 
	return strcmp(key1, key2);
}


void setPayloadKey(struct Payload* payload, keyType key) {
	strcpy(payload->key, key);
}


void setPayloadValue(struct Payload* payload, valueType value) {
	payload->value = value;
}


struct Node {
	struct Payload data;
	struct Node* right;
	struct Node* left;
};


void setValue(struct Node *node, valueType value) {
	node->data.value = value + 1;
}

//===================== common part =========================\


struct BinaryTree {
	struct Node *head;
};


struct Node* getNode(struct Payload data) { 
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL) {
		perror("Not enough memory");
		exit(1);
	}
	res->data = data;
	res->left = NULL;
	res->right = NULL;
	return res;
}


valueType getValue(struct Node* node, keyType key, valueType defValue) { 
	int result = compareKeys(key, node->data.key);
	if (result > 0) {
		if (node->right == NULL) {
			return defValue;
		}
		else {
			return getValue(node->right, key, defValue);
		}
	}
	else if (result < 0) {
		if (node->left == NULL) {
			return defValue;
		}
		else {
			return getValue(node->left, key, defValue);
		}
	}
	else {
		return node->data.value;
	}
}


void addFromNode(struct Node* node, struct Payload data) { 
	int result = compareKeys(data.key, node->data.key);
	if (result > 0) {
		if (node->right == NULL) {
			node->right = getNode(data);
		}
		else {
			addFromNode(node->right, data);
		}
	}
	if (result < 0) {
		if (node->left == NULL) {
			node->left = getNode(data);
		}
		else {
			addFromNode(node->left, data);
		}
	}
	if (result == 0) {
		int x = getValue(node, data.key, data.value); 
		setValue(node, x);
	}
}

void addFromHead(struct BinaryTree* tree, struct Payload data) {
	if (tree->head == NULL) {
		tree->head = getNode(data);
	}
	else {
		addFromNode(tree->head, data);
	}
}

struct BinaryTree* createBinaryTree() { 
	struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
	if (tree == NULL) {
		printf("Error");
		exit(1);
	}
	tree->head = NULL;
	return tree;
}

void printBinaryTree(struct Node* node) {
	if (node == NULL) {
		return;
	}
	printBinaryTree(node->left);
	printPayload(node->data);
	printBinaryTree(node->right);
} 

void deleteNodes(struct Node* node) {
	if (node == NULL) {
		return;
	}
	deleteNodes(node->left);
	deleteNodes(node->right);
	free(node);
} 


void treeHeight(struct Node* node, int* height, int currHeight) {

	if (currHeight >= *height) {
		*height = currHeight;
	}
	if (node == NULL) {
		return;
	}
	treeHeight(node->left, height, currHeight + 1);
	treeHeight(node->right, height, currHeight + 1);
}


void normalWords(char* word, char* normalWord) {
	keyType notNormal = ".,!?():;-/";
	int g = 0;
	int i = 0;

	while (word[i] != '\0') {
		int f = 0;
		int a = 0;
		while (notNormal[a] != '\0') {
			if (word[i] == notNormal[a]) {
				f += 1;
				break;
			}
			a++;
		}
		if (f == 0) {
			normalWord[g] = word[i];
			g++;
		}
		i++;
	}
	normalWord[g] = '\0';
}


int main() {
	FILE* file;
	char word[MAX_WORD_LENGTH + 1];
	char goodWord[MAX_WORD_LENGTH + 2];
	if ((file = fopen("idiot.txt", "r")) == NULL) {
		printf("Failed to open the file.\n");
		exit(1);
	}

	clock_t start = clock();

	struct BinaryTree* tree = createBinaryTree();
	while (fscanf(file, "%s", word) != EOF) {
		normalWords(word, goodWord);
		struct Payload data;
		setPayloadValue(&data, 1);
		setPayloadKey(&data, goodWord);
		addFromHead(tree, data);
	}
	printBinaryTree(tree->head);
	fclose(file);
	int* heightPointer;
	int height = 0;
	heightPointer = &height;
	treeHeight(tree->head, heightPointer, 0);
	printf("The tree height: %d\n", *heightPointer);
	deleteNodes(tree->head);
	free(tree);

	clock_t finish = clock();

	double timeElapsed = ((double)(finish - start)) / CLOCKS_PER_SEC;
	printf("Time: %f\n\n", timeElapsed);

	return 0;
}