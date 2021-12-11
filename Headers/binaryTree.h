#include "../Hash Functions/polynome.h"


typedef struct CollisionNode {
	int value;
	char key[MAX_WORD_LENGTH];
	struct CollisionNode* next;
} CollisionNode;

typedef struct Node {
	CollisionNode *collision;
	int value;
	int hashKey;
	char key[MAX_WORD_LENGTH];
	struct Node *left;
	struct Node *right;
} Node;

typedef struct {
	Node *root;
} BinaryTree;


void mallocNodeChecker(Node *node) {
	if (node == NULL) {
		perror("Can't allocate memory for Node\n");
		exit(1);
	}
}

void setDefaultNodeProperties(Node *node, char key[MAX_WORD_LENGTH], int value) {
	int hashKey = hashFoo(key);
	
	node -> left = NULL;
	node -> right = NULL;
	node -> collision = NULL;
	node -> hashKey = hashKey;
	strcpy(node -> key, key);
	node -> value = value;
}

CollisionNode* initCollisionNode(char key[MAX_WORD_LENGTH]) {
	CollisionNode *collision = (CollisionNode*)malloc(sizeof(CollisionNode));
	
	if (collision == NULL) {
		perror("Can't allocate memory for Collision Node\n");
		exit(1);
	}
	collision -> value = 1;
	collision -> next = NULL;
	strcpy(collision -> key, key);
	
	return collision;
}

Node* initNode(char key[MAX_WORD_LENGTH], int value) {
	Node *node = (Node*)malloc(sizeof(Node));
	
	mallocNodeChecker(node);
	setDefaultNodeProperties(node, key, value);
	
	return node;
}

void checkForInit(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	if (tree -> root == NULL) {
		tree -> root = initNode(key, 0);
	}
}

Node* binarySearch(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	checkForInit(tree, key);
	Node *curNode = tree -> root;
	int hashKey = hashFoo(key);
	int curNodeHashKey = curNode -> hashKey;
	Node *newNode;
	
	while (1) {
		if (hashKey < curNodeHashKey) {
			if (curNode -> left == NULL) {
				newNode = initNode(key, 0);
				curNode -> left = newNode;
				
				return newNode;
			}
			curNode = curNode -> left;
		} else if (hashKey > curNodeHashKey) {
			if (curNode -> right == NULL) {
				newNode = initNode(key, 0);
				curNode -> right = newNode;
			
				return newNode;
			}
			curNode = curNode -> right;
		} else {
		
			return curNode;
		}
		curNodeHashKey = curNode -> hashKey;
	}
}
		
void increment(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	Node *neededNode = binarySearch(tree, key);
	CollisionNode *curCollision = neededNode -> collision;

	if (!strcmp(neededNode -> key, key)) {
		neededNode -> value++;
	} else {
		while (curCollision -> next != NULL) {
			if (!strcmp(curCollision -> key, key)) {
				curCollision -> value++;
				break;
			}
			if (curCollision -> next == NULL) {
				curCollision -> next = initCollisionNode(key);
				break;
			}
		}
	}
};

BinaryTree* initBinaryTree() {
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	
	if (tree == NULL) {
		perror("Can't allocate memory for Binary Tree\n");
		exit(1);
	}
	tree -> root = NULL;
	
	return tree;
}

void wordHandler(BinaryTree *tree, char key[MAX_WORD_LENGTH]) {
	increment(tree, key);
	printf("%s\n", key);
}

void printCollisions(Node *node, FILE *file) {
	CollisionNode *curCollision = node -> collision;
	
	while (curCollision != NULL) {
		fprintf(file, "%s: %d\n",curCollision -> key, curCollision -> value );
		curCollision = curCollision -> next;
	}
}

void printNodes(Node *node, FILE *file) {
	if (node != NULL) {
		printNodes(node -> left, file);
		printNodes(node -> right, file);
		printCollisions(node, file);
		fprintf(file, "%s: %d\n", node -> key, node -> value);
	}
}

void printTree(BinaryTree* tree, FILE *file) {
	printNodes(tree -> root, file);
}

void printNodesInConsole(Node *node) {
	if (node != NULL) {
		printNodesInConsole(node -> left);
		printNodesInConsole(node -> right);
		printf("%s: %d\n", node -> key, node -> value);
	}
}

void printInConsole(BinaryTree* tree) {
	printf("\n--------------------------------------------------\n");
	printNodesInConsole(tree -> root);
	printf("\n--------------------------------------------------\n");
}


//-----------------------------------------------------------------------------------------------------

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
	