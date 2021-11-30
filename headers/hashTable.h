#include "../hashFunctions/alternationSumOfCodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int equalStr(char str1[MAX_WORD_LENGTH], char str2[MAX_WORD_LENGTH]) {
	return (!(strcmp(str1, str2)));
}

//------- Defining Srtuctures ----------------------------------------------------------------------------------

typedef struct Node {
	char key[MAX_WORD_LENGTH];
	int value;
	struct Node *next;
} Node;


typedef struct {
	size_t size;
	Node **buckets;
} HashTable;

typedef struct {
	float average;
	int min;
	int max;
} ChainsLength;

typedef struct NodeForMax {
	char key[MAX_WORD_LENGTH];
	struct NodeForMax *next;
} NodeForMax;

typedef struct {
	NodeForMax *head;
} ListForMax;
	
//--------- MaxInputSection ------------------------------------------------------------------------------------------------------

ListForMax* listForMaxInit() {
	ListForMax *listPointer = (ListForMax*)malloc(sizeof(ListForMax));
	
	if (listPointer == NULL) {
		printf("Can't allocate enough memory for ListForMax, NULL will be returned\n");
	}
	listPointer -> head = NULL;
	return listPointer;
}

void addNodeForMax(ListForMax *list, char key[MAX_WORD_LENGTH]) {
	NodeForMax *newNode = (NodeForMax*)malloc(sizeof(NodeForMax));
	
	if (newNode == NULL) {
		printf("Can't allocate memory for new NodeForMax\n");
	} else {
		strcpy(newNode -> key, key);
		newNode -> next = list -> head;
		list -> head = newNode;
	}
}

void clearListForMax(ListForMax *list) {
	NodeForMax *curNode = list -> head;
	NodeForMax *nextNode;
	
	while (curNode != NULL) {
		nextNode = curNode -> next;
		free(curNode);
		curNode = nextNode;
	}
	list -> head = NULL;
}

void writeMaxNode(FILE *file, ListForMax *list, int value) {
	NodeForMax *curNode = list -> head;
	
	while (curNode != NULL) {
		fprintf(file, "%s: %d\n", curNode -> key, value);
		curNode = curNode -> next;
	}
}

void deleteListForMax(ListForMax *list) {
	clearListForMax(list);
	free(list);
}
	
//--------- Node Section -------------------------------------------------------------------------------------------

Node** getHashAdress(HashTable* table, char word[MAX_WORD_LENGTH]) {
	return (table -> buckets) + (hashFoo(word) % table -> size);
}

void nodeInit(Node **p,char key[MAX_WORD_LENGTH], int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	if (newNode == NULL) {
		printf("Can't allocate enough memory for Node to put your value in it\n");
	} else {
		strcpy(newNode -> key, key);
		newNode -> value = value;
		newNode -> next = NULL;
		*p = newNode;
	}
}

Node* getNode(HashTable* table, char key[MAX_WORD_LENGTH]) {
	Node *cur = *(getHashAdress(table, key));
	
	if (cur == 0) {
		return NULL;
	} else {
		while (cur != NULL) {
			if (equalStr(cur -> key, key)) {
				return cur;
			}
			cur = cur -> next;
		}
	}
	return NULL;
}

void nodeInsert(Node **p, char key[MAX_WORD_LENGTH], int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	strcpy(newNode -> key, key);
	newNode -> value = value;
	newNode -> next = *p;
	*p = newNode;
}

int popNode(HashTable *table, char key[MAX_WORD_LENGTH]) {
	Node **headPointer = getHashAdress(table, key);
	Node *cur = *headPointer;
	Node *prev;
	int value = 0;
	
	if (cur == 0) {
		printf("There is no value binded with %s in this HashTable, 0 will be returned\n", key);
	} else {
		while (cur != NULL) {
			if (equalStr(cur -> key, key)) {
				value = cur -> value;
				if (cur == *headPointer) {
					if (cur -> next == NULL) {
						*headPointer = 0;
					} else {
						*headPointer = cur -> next;
					}
				} else {
					prev -> next = cur -> next;
				}
				free(cur);
				return value;
			}
			prev = cur;
			cur = cur -> next;
		}
	}
	printf("There is no value binded with %s in this HashTable, 0 will be returned\n", key);
	return 0;
}

int lenOfChain(Node *curNode) {
	int count = 0;
	
	if (curNode != 0) {
		while (curNode != NULL) {
			count++;
			curNode = curNode -> next;
		}
	}
	return count;
}

void deleteNodes(Node **p) {
	if (*p != 0) {
		Node *cur = *p;
		Node *prev;
		while (cur != NULL) {
			prev = cur;
			cur = cur -> next;
			free(prev);
		}
	}
}

//---------- HashTable Section --------------------------------------------------------------------------------------------

HashTable* createHashTable(int bucketsCount) {
	HashTable *p = (HashTable*)malloc(sizeof(HashTable));
	
	if (p == NULL) {
		printf("Can't allocate memory for HashTable, NULL will be returned\n");
		return NULL;
	}
	p -> size = bucketsCount;
	p -> buckets = (Node**)calloc(bucketsCount, sizeof(Node*));
	if (p -> buckets == NULL) {
		printf("Too much buckets, can't allocate memory for them, NULL will be returned\n");
		return NULL;
	}
	return p;
}

void setValue(HashTable *table, char key[MAX_WORD_LENGTH], int value) {
	Node *neededNode = getNode(table, key);
	Node **hashAdress = getHashAdress(table, key);
	
	if ((*hashAdress) == 0) {
		nodeInit(hashAdress, key, value);
	} else if (neededNode == NULL) {
		nodeInsert(hashAdress, key, value);
	} else {
		neededNode -> value = value;
	}
}

void printAll(HashTable *table) {
	Node **curBucket = table -> buckets;
	Node **lastBucket = table -> buckets + table -> size - 1;
	
	while (curBucket <= lastBucket) {
		if ((*curBucket) != 0) {
			Node *curNode = *curBucket;
			while(curNode != NULL) {
				printf("%s: %d\n", curNode -> key, curNode -> value);
				curNode = curNode -> next;
			}
		}
		curBucket++;
	}
}

int getValue(HashTable *table, char key[MAX_WORD_LENGTH]) {
	Node *neededNode = getNode(table, key);
	
	if (neededNode == NULL) {
		printf("There is no value binded with %s in this HashTable, 0 will be returned\n", key);
		return 0;
	} else {
		return neededNode -> value;
	}
}

int popValue(HashTable *table, char key[MAX_WORD_LENGTH]) {
	return popNode(table, key);
}

void deleteHashTable(HashTable **tablePointer) {
	HashTable *table = *tablePointer;
	Node **curBucket = table -> buckets;
	Node **lastBucket = curBucket + table -> size - 1;
	
	while (curBucket <= lastBucket) {
		deleteNodes(curBucket);
		curBucket++;
	}
	free(table -> buckets);
	free(table);
	*tablePointer = NULL;
}

//---------------- Analysis Section ------------------------------------------------------------------------------------------

int nonZeroChains(HashTable *table) {
	int count = 0;
	Node **curBucket = table -> buckets;
	Node **lastBucket = table -> buckets + table -> size - 1;
	
	while (curBucket <= lastBucket) {
		if (*curBucket != 0) {
			count++;
		}
		curBucket++;
	}
	return count;
}

ChainsLength* chainLengthAnalysis(HashTable *table) {
	int sumOfLength = 0;
	int curChainLength = 0;
	int min = INT_MAX;
	int max = 0;
	Node **curBucket = table -> buckets;
	Node **lastBucket = table -> buckets + table -> size - 1;
	ChainsLength *result = (ChainsLength*)malloc(sizeof(ChainsLength));
	
	if (result == NULL) {
		printf("Can't allocate memory for result\n");
		return NULL;
	}
	while (curBucket <= lastBucket) {
		curChainLength = lenOfChain(*curBucket);
		if (curChainLength != 0) {
			sumOfLength += curChainLength;
			if (curChainLength > max) {
				max = curChainLength;
			}
			if (curChainLength < min) {
				min = curChainLength;
			}
		}
		curBucket++;
	}
	result -> min = min;
	result -> max = max;
	result -> average = (float)sumOfLength / nonZeroChains(table);
	return result;
}

void countWord(HashTable *table, char key[MAX_WORD_LENGTH]) {
	Node *neededNode = getNode(table, key);
	
	if (neededNode == NULL) {
		setValue(table, key, 1);
	} else {
		neededNode -> value = neededNode -> value + 1;
	}
}

//--------------------------- File writing section -------------------------------------------------------------------------------------------------------------------

void writeAnalysis(FILE *fileForAnalysis, HashTable *table) {
	int countNonZeroChains = nonZeroChains(table);
	ChainsLength *chainAnalysis = chainLengthAnalysis(table);

	fprintf(fileForAnalysis, "-------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fileForAnalysis, "%d buckets HashTable Results\n\n", table -> size);
	fprintf(fileForAnalysis, "------Chains Analysis------\n");
	fprintf(fileForAnalysis, "Non zero chains count: %d\nMin length of non zero chain: %d\nMax length of non zero chain: %d\nAverage length of non zero chain: %.2f\n", countNonZeroChains, chainAnalysis -> min, chainAnalysis -> max, chainAnalysis -> average);
}
	
	
void writeInFile (FILE *fileForWrite, HashTable *table, FILE *fileForAnalysis) {
	ListForMax *list = listForMaxInit();
	Node **curBucket = table -> buckets;
	Node **lastBucket = table -> buckets + table -> size - 1;
	int maxValue = 0;
	int countNonZeroChains;
	ChainsLength *chainAnalysis;
	
	while (curBucket <= lastBucket) {
		if ((*curBucket) != 0) {
			Node *curNode = *curBucket;
			while(curNode != NULL) {
				fprintf(fileForWrite, "%s: %d\n", curNode -> key, curNode -> value);
				if ((curNode -> value) > maxValue) {
					maxValue = curNode -> value;
					clearListForMax(list);
					addNodeForMax(list, curNode -> key);
				} else if ((curNode -> value) == maxValue) {
					addNodeForMax(list, curNode -> key);
				}
				curNode = curNode -> next;
			}
		}
		curBucket++;
	}
	fprintf(fileForAnalysis, "------Max word counted------\n");
	writeMaxNode(fileForAnalysis, list, maxValue);
	fprintf(fileForAnalysis, "\n\n");
	writeAnalysis(fileForAnalysis, table);
	deleteListForMax(list);
}