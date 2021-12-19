#include "../HashFunction/polynome.h"


//------------------------------ Defining structures ---------------------------------------------


typedef struct Node {
	int hashKey;
	int value;
	char key[MAX_WORD_LENGTH];
	struct Node *left;
	struct Node *right;
} Node;

typedef struct BinaryTree {
	Node *root;
} BinaryTree;


//----------------------------- Service functions ----------------------------------


Node* initNode(char key[MAX_WORD_LENGTH], int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	int hashKey = hashFoo(key);
	
	if (newNode == NULL) {
		perror("Can't allocate memory for new Node\n");
		exit(1);
	}
	newNode -> hashKey = hashKey;
	newNode -> value = value;
	newNode -> left = NULL;
	newNode -> right = NULL;
	strcpy(newNode -> key, key);
	
	return newNode;
}

Node* getNode(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	Node *curNode = tree -> root;
	int hashKey = hashFoo(key);
	
	if (curNode != NULL) {
		while (1) {
			if (hashKey < curNode -> hashKey) {
				if (curNode -> left != NULL) {
					curNode = curNode -> left;
				} else {
					curNode -> left = initNode(key, 0);
					
					return curNode -> left;
				}
			} else if (hashKey > curNode -> hashKey) {
				if (curNode -> right != NULL) {
					curNode = curNode -> right;
				} else {
					curNode -> right = initNode(key, 0);
					
					return curNode -> right;
				}
			} else {
				return curNode;
			}
		}
	} else {
		tree -> root = initNode(key, 0);
		
		return tree -> root;
	}
}

void printNodes(Node *curNode, FILE *file) {
	if (curNode -> left != NULL) {
		printNodes(curNode -> left, file);
	}
	fprintf(file, "%s: %d\n", curNode -> key, curNode -> value);
	if (curNode -> right != NULL) {
		printNodes(curNode -> right, file);
	}
}

void printRelation(Node *curNode) {
	if (curNode != NULL) {
		printf("\n%s: %d; Hash = %d; ", curNode -> key, curNode -> value, curNode -> hashKey);
		if (curNode -> left != NULL) {
			printf("   left is %s ", curNode -> left -> key);
		}
		if (curNode -> right != NULL) {
			printf("   right is %s ", curNode -> right -> key);
		}
		printRelation(curNode -> left);
		printRelation(curNode -> right);
	}
}

void deleteSubTree(Node *curNode) {
	if (curNode != NULL) {
		deleteSubTree(curNode -> left);
		deleteSubTree(curNode -> right);
		free(curNode);
	}
}

void treeDeletedChecker(BinaryTree *tree) {
	if (tree != NULL) {
		perror("Something wrong with deleting Binary Tree\n");
	}
}


//---------------------- BinaryTree functions ---------------------------------------------------------


void wordHandler(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	Node *neededNode = getNode(tree, key);
	
	neededNode -> value++;
}

void printTree(BinaryTree *tree, FILE *file) {
	printNodes(tree -> root, file);
}

BinaryTree *initBinaryTree() {
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	
	if (tree == NULL) {
		perror("Can't allocate memory for new Binary Tree\n");
		exit(1);
	}
	tree -> root = NULL;
	
	return tree;
}

void deleteTree(BinaryTree **treePointer) {
	BinaryTree *tree = *treePointer;
	
	deleteSubTree(tree -> root);
	free(*treePointer);
	*treePointer = NULL;
}


//------------------------ Analysis functions -----------------------------------------------------------------------------


void subTreeHeight(Node *node, int *maxPointer, int curHeight, int *maxValuePointer, char maxKey[MAX_WORD_LENGTH]) {
	if (node != NULL) {
		if (node -> value > *maxValuePointer) {
			*maxValuePointer = node -> value;
			strcpy(maxKey, node -> key);
		}
		

		curHeight++;
		if (curHeight > *maxPointer) {
			*maxPointer = curHeight;
		}
		subTreeHeight(node -> left, maxPointer, curHeight, maxValuePointer, maxKey);
		subTreeHeight(node -> right, maxPointer, curHeight, maxValuePointer, maxKey);
	}
}

void treeHeightAndMax(BinaryTree *tree, int *maxHeight, int *maxValuePointer, char maxKey[MAX_WORD_LENGTH]) {
	int curHeight = -1;
	
	subTreeHeight(tree -> root, maxHeight, curHeight, maxValuePointer, maxKey);
}

void printTreeAnalysis(BinaryTree *tree, FILE *file) {
	int maxValue = 0;
	int maxHeight = 0;
	char maxKey[MAX_WORD_LENGTH];
	
	treeHeightAndMax(tree, &maxHeight, &maxValue, maxKey);
	fprintf(file, "----------------------------------\nThe most common word is %s: %d times\nTree's height is %d\n----------------------------------\n\n", maxKey, maxValue, maxHeight);
}