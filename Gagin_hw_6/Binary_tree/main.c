//Attention:
//If you see the error: "Did not open the file. Exiting.", you should:
//Create build-debug folder and add file "text.txt" into her.
//Or you can specify the full path to the folder on 376 line of this program.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//===================== specific part=========================

#define MAX_WORD_LENGTH 100

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];

typedef struct Payload
{
	keyType key;
	valueType value;
} Payload;

void printPayload(struct Payload data)
{
	printf("key = %s, value = %d\n", data.key, data.value);
}

_Bool compareKeys(keyType key1, keyType key2)
{
	return !strcmp(key1, key2);
}

void setPayloadKey(struct Payload *payload, keyType key)
{
	strcpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value)
{
	payload->value = value;
}

//===================== common part =========================

typedef struct Node
{
	Payload data;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct BinaryTree
{
	Node *head;
} BinaryTree;

//-----

BinaryTree *createBinaryTree()
{
	BinaryTree *tree = malloc(sizeof (BinaryTree));
	if (NULL == tree)
	{
		perror("Not enough memory to create binary tree. Exiting.\n");
		exit(1);
	}
	tree->head = NULL;
	return tree;
}

Node *getNode(Payload data)
{
	Node *node = malloc(sizeof(Node));
	if (NULL == node)
	{
		perror("Not enough memory to create node of binary tree. Exiting.\n");
		exit(1);
	}
	setPayloadKey(&node->data,data.key);
	setPayloadValue(&node->data, data.value);
	node->left = NULL;
	node->right = NULL;
	return node;
}

int compareKeysToMove(keyType key1, keyType key2)
{
	return strcmp(key1, key2);
}
void addNode(Node *node, Payload data)
{
	int move = compareKeysToMove(data.key,node->data.key);
	if (move > 0)
	{
		if (NULL == node->right)
		{
			node->right = getNode(data);
		}
		else
		{
			addNode(node->right, data);
		}
	}
	else if (move < 0)
	{
		if (NULL == node->left)
		{
			node->left = getNode(data);
		}
		else
		{
			addNode(node->left, data);
		}
	}
	else
	{
		node->data.value += 1;
	}
}

void startAddNode(BinaryTree *tree, Payload data)
{
	if (NULL == tree->head)
	{
		tree->head = getNode(data);
		return;
	}
	addNode(tree->head, data);
}

void delAllNodes(Node *node)
{
	if (NULL == node)
	{
		return;
	}
	delAllNodes(node->left);
	delAllNodes(node->right);
	free(node);
}

void delTree(BinaryTree *tree)
{
	delAllNodes(tree->head);
}

Node *returnNode(Node *node, keyType key)
{
	if (NULL == node)
	{
		return NULL;
	}
	int move = !compareKeys(key,node->data.key);
	if (move > 0)
	{
		return returnNode(node->right, key);
	}
	else if (move < 0)
	{
		return returnNode(node->left, key);
	}
	return node;
}

valueType startReturnNode(BinaryTree *tree, keyType key)
{
	Node *node = returnNode(tree->head, key);
	if (NULL == node)
	{
		printf("No key = \"%s\" in tree.\n", key);
		return -1;
	}
	else
	{
		printf("Searchable key = \"%s\" in tree. Value = %d\n",node->data.key, node->data.value);
		return 1;
	}
}
int max(int first, int second)
{
	if (first > second)
	{
		return first;
	}
	return second;
}

void heightOfTree(int height, int *res, Node *node)
{
	*res = max(*res, height);
	if (NULL == node)
	{
		return;
	}
	int new_height = height + 1;
	heightOfTree((new_height), res, node->left);
	heightOfTree((new_height), res, node->right);
}

void theMostCommonWord(Payload *data, Node *node)
{
	if (NULL == node)
	{
		return;
	}
	if (data->value < node->data.value)
	{
		setPayloadKey(data, node->data.key);
		setPayloadValue(data, node->data.value);
	}
	theMostCommonWord(data, node->left);
	theMostCommonWord(data, node->right);
}

void printNode(Node *node)
{
	if (NULL == node)
	{
		return;
	}
	printNode(node->left);
	printPayload(node->data);
	printNode(node->right);
}

void printBinaryTree(BinaryTree *tree)
{
	printNode(tree->head);
}

//-----

enum end_of_word
{
	bad_sign_three = 3, // three last symbols are bad
	bad_sign_two = 2, // two last symbols are bad
	bad_sign_one = 1, // one last symbol is bad
	everything_is_fine = 0
};

enum begin_of_word
{
	everything_is_good = 0,
	bad_start = 1 // first symbol is bad
};

void destroyer_of_bad_signs(char *word, char *good_word)
{
	static char bad_signs[11] = ",.;!?\"\':()-";
	int end = everything_is_fine;
	int start = everything_is_good;
	for (size_t i = 0; i < strlen(bad_signs); i++)
	{
		if (word[strlen(word) - 1] == bad_signs[i])
		{
			end = bad_sign_one; // ,.;!?"':()- at end
		}
		//-----
		if (word[0] == bad_signs[i])
		{
			start = bad_start; // ,.;!?"':()- at start
		}
	}
	//-----
	if (end == bad_sign_one)
	{
		for (size_t i = 0; i < strlen(bad_signs); i++)
		{
			if (word[strlen(word) - 2] == bad_signs[i])
			{
				end = bad_sign_two;
			}
		}
	}
	//-----
	if (end == bad_sign_two)
	{
		for (size_t i = 0; i < strlen(bad_signs); i++)
		{
			if (word[strlen(word) - 3] == bad_signs[i])
			{
				end = bad_sign_three;
			}
		}
	}
	//---------------------------------------------------------------------
	if (end == everything_is_fine && start == everything_is_good) // 1)
	{
		size_t i;
		for (i = 0; i < strlen(word); i++)
		{
			good_word[i] = word[i];
		}
		good_word[i] = '\0';
	}
	//-----
	if (end == everything_is_fine && start == bad_start) // 2)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 1; i++)
		{
			good_word[i] = word[i + 1];
		}
		good_word[i] = '\0';
	}
	//---------------------------------------------------------------------
	if (end == bad_sign_one && start == everything_is_good) // 3)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 1; i++)
		{
			good_word[i] = word[i];
		}
		good_word[i] = '\0';
	}
	//-----
	if (end == bad_sign_one && start == bad_start) // 4)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 2; i++)
		{
			good_word[i] = word[i + 1];
		}
		good_word[i] = '\0';
	}
	//---------------------------------------------------------------------
	if (end == bad_sign_two && start == everything_is_good) // 5)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 2; i++)
		{
			good_word[i] = word[i];
		}
		good_word[i] = '\0';
	}
	//-----
	if (end == bad_sign_two && start == bad_start) // (6)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 3; i++)
		{
			good_word[i] = word[i + 1];
		}
		good_word[i] = '\0';
	}
	//---------------------------------------------------------------------
	if (end == bad_sign_three && start == everything_is_good) // (7)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 3; i++)
		{
			good_word[i] = word[i];
		}
		good_word[i] = '\0';
	}
	//-----
	if (end == bad_sign_three && start == bad_start) // (8)
	{
		size_t i;
		for (i = 0; i < strlen(word) - 4; i++)
		{
			good_word[i] = word[i + 1];
		}
		good_word[i] = '\0';
	}
	//---------------------------------------------------------------------
}

//-----

int main()
{
	FILE *fp;
	char word[MAX_WORD_LENGTH + 1];
	char good_word[MAX_WORD_LENGTH + 2];
	if ((fp = fopen("name.txt", "r")) == NULL)
	{
		printf("Did not open the file. Exiting.");
		exit(1);
	}
	clock_t start = clock();
	BinaryTree *tree = createBinaryTree();
	//-----
	while (fscanf(fp, "%s", word) != EOF)
	{
		destroyer_of_bad_signs(word, good_word);
		Payload data = {.value = 1};
		setPayloadKey(&data, good_word);
		startAddNode(tree, data);

	}
	clock_t finish = clock();
	fclose(fp);
	//-----
	printBinaryTree(tree);
	double timeElapsed = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printf("Work-time: %f sec.\n", timeElapsed);
	//word-search
	startReturnNode(tree, "Куприн");
	startReturnNode(tree, "НеКуприн");
	//height of tree
	int height = 0;
	int res = 0;
	heightOfTree(height, &res, tree->head);
	printf("Height of tree: %d\n", res);
	//the most common word
	Payload common_word = {.value = 1, .key = ""};
	theMostCommonWord(&common_word, tree->head);
	printf("The most common word: \"%s\" (%d)\n", common_word.key, common_word.value);
	//-----
	delTree(tree);
	free(tree);
	return 0;
}




