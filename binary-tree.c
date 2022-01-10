#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//===================== specific part =========================

#define MAX_WORD_LENGTH 50


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

void setPayloadKey(struct Payload *payload, keyType key) {
	strcpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value) {
	payload->value = value;
}


struct Node {
	struct Payload data;
	struct Node *right;
	struct Node *left;
};

void setValue(struct Node *node, valueType value) {
	node->data.value = value + 1;
}
//===================== common part =========================\


struct BinaryTree
{
	struct Node *head;
};


struct Node* getNode(struct Payload data) {
	struct Node *res = malloc(sizeof(struct Node));
	if (res == NULL) {
		perror("Not enough memory");
		exit(1);
	}
	res->data = data; //(*res).data
	res->left = NULL;
	res->right = NULL;
	return res;
}

valueType getValue(struct Node *node, keyType key, valueType defValue) {
	int result = compareKeys(key, node->data.key);
	if (result > 0) {
		if (node->right == NULL) {
			return defValue;
		} else {
			return getValue(node->right, key, defValue);
		}
	}
	else if (result < 0) {
		if (node->left == NULL) {
			return defValue;
		} else {
			return getValue(node->left, key, defValue);
		}
	}
	else {
		return node->data.value;
	}
}


void addFromNode(struct Node *node, struct Payload data)
{
	int result = compareKeys(data.key, node->data.key);
	if (result > 0)
	{
		if (node->right == NULL)
		{
			node->right = getNode(data);
		}
		else
		{
			addFromNode(node->right, data);
		}
	}
	if (result < 0)
	{
		if (node->left == NULL)
		{
			node->left = getNode(data);
		}
		else
		{
			addFromNode(node->left, data);
		}
	}
	if (result == 0)
	{
		int x = getValue(node, data.key, data.value); //data.value = 0; - äåôîëòíîå çíà÷åíèå
		setValue(node, x);
	}

}

void addFromHead(struct BinaryTree *tree, struct Payload data) {
	if (tree->head == NULL) {
		tree->head = getNode(data);
	}
	else {
		addFromNode(tree->head, data);
	}
}

struct BinaryTree *createBinaryTree() {
	struct BinaryTree *tree = malloc(sizeof(struct BinaryTree));
	if (tree == NULL) {
		printf("Error");
		exit(1);
	}
	tree->head = NULL;
	return tree;
}

void printTree(struct Node *node) {
	if (node == NULL) {
		return;
	}
	printTree(node->left);
	printPayload(node->data);
	printTree(node->right);
}

void deleteNodes(struct Node *node) {
	if (node == NULL) {
		return;
	}
	deleteNodes(node->left);
	deleteNodes(node->right);
	free(node);
}



void HeightOfTree(struct Node *node, int *height, int curr_height) {

	if (curr_height >= *height) {
		*height = curr_height;
	}
	if (node == NULL)
	{
		return;
	}
	HeightOfTree(node->left, height, curr_height + 1);
	HeightOfTree(node->right, height, curr_height + 1);
}


void withoutBadSymbols(char *word, char *normalWord) {
    int a = 0;
    int i = 0;
    while(word[i] != '\0') {
        int flag = 0;
        if (word[i] == '.' || word[i] == '!' || word[i] == '?' || word[i] == ',' || word[i] == '(' || word[i] == ')') {
            flag += 1;
        }
        if (flag == 0) {
            normalWord[a] = word[i];
            a++;
        }
        i++;
    }
    normalWord[a] = '\0';
}



int main() {
	FILE *fp;
	char word[MAX_WORD_LENGTH + 1];
	char goodWord[MAX_WORD_LENGTH + 2];
	if ((fp = fopen("geroi_nashego_vremeni.txt", "r")) == NULL)
	{
		printf("Did not open the file. Exiting.");
		exit(1);
	}
	clock_t start = clock();
	struct BinaryTree *tree = createBinaryTree();
	while (fscanf(fp, "%s", word) != EOF) {
        withoutBadSymbols(word, goodWord);
		struct Payload data;
		setPayloadValue(&data, 1);
		setPayloadKey(&data, goodWord);
		addFromHead(tree, data);
	}
	clock_t finish = clock();
	double timeElapsed = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printTree(tree->head);
	fclose(fp);

	int *height_pointer;
	int height = 0;
	height_pointer = &height;
	HeightOfTree(tree->head, height_pointer, 0);
	printf("Height = %d\n", *height_pointer);
	deleteNodes(tree->head);
	free(tree);
	printf("Work-time: %f sec.\n", timeElapsed);
	return 0;
}