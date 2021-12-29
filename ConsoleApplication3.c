
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include <time.h>


//===================== specific part=========================

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

size_t getHash(keyType key) {
	//size_t res = sum(key);
	size_t res = 0;
	return res;
}

_Bool compareKeys(keyType key1, keyType key2) {
	return !strcmp(key1, key2);
}

void setPayloadKey(struct Payload* payload, keyType key) {
	strcpy(payload->key, key);
}

void setPayloadValue(struct Payload* payload, valueType value) {
	payload->value = value;
}

//===================== common part =========================\

struct Node {
	struct Payload data;
	struct Node* next;
};

struct LinkedList {
	size_t size;
	struct Node* head;
};

struct HashTable {
	size_t size;
	struct LinkedList* buckets;
};

struct Node* getNode(struct Payload data) {
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL) {
		perror("Not enough memory");
		exit(1);
	}
	res->data = data; // (*res).data
	res->next = NULL;
	return res;
}

void addNode(struct LinkedList* list, struct Payload data) {
	struct Node* node = getNode(data);

	if (list->head == NULL) {
		list->head = node;
	}
	else {
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

struct Node* findNode(struct LinkedList* list, keyType key) {
	struct Node* curr = list->head;
	while (curr != NULL) {
		if (compareKeys(key, curr->data.key)) {
			break;
		}
		curr = curr->next;
	}
	return curr;
}

void printList(struct LinkedList* list) {
	struct Node* curr = list->head;
	while (curr != NULL) {
		printPayload(curr->data);
		curr = curr->next;
	}
}

void clearList(struct LinkedList* list) {
	struct Node* curr = list->head;
	while (curr != NULL) {
		struct Node* savedNext = curr->next;
		free(curr);
		curr = savedNext;
	}
	list->size = 0;
	list->head = NULL;
}

struct LinkedList createLinkedList() {
	struct LinkedList list = { .size = 0, .head = NULL };
	return list;
}

struct HashTable createHashTable(size_t size) {
	struct LinkedList* buckets = malloc(sizeof(struct LinkedList) * size);
	if (buckets == NULL) {
		perror("Cannot allocate memory for HashTable");
		exit(1);
	}

	for (size_t i = 0; i < size; i++) {
		buckets[i] = createLinkedList();
	}

	struct HashTable table = { .size = size, .buckets = buckets };
	return table;
}

void clearHashTable(struct HashTable* table) {
	for (size_t i = 0; i < table->size; i++) {
		clearList(&table->buckets[i]);
	}
	free(table->buckets);
	table->buckets = NULL;
	table->size = 0;
}

size_t getBucket(struct HashTable* table, keyType key) {
	return getHash(key) % table->size;
}

void setValue(struct HashTable* table, keyType key, valueType value) {
	size_t bucket = getBucket(table, key);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	if (node) {
		node->data.value = value;
	}
	else {
		struct Payload payload = { NULL,NULL };
		setPayloadKey(&payload, key);
		setPayloadValue(&payload, value);
		addNode(list, payload);
	}
}

valueType getValue(struct HashTable* table, keyType key, valueType defValue) {
	size_t bucket = getBucket(table, key);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	return node ? node->data.value : defValue;
}

void printHashTable(struct HashTable* table) {
	_Bool hasData = false;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size != 0) {
			printList(bucket);
			hasData = true;
		}
	}
	if (!hasData) {
		printf("The hash table is empty\n");
	}
}

// хеш-функция возвращает сумму кодов символов.
size_t sum(keyType key)
{
	int l = strlen(key);
	size_t hashf = 0;
	for (int i = 0; i < l; i++)
	{
		hashf = hashf + key[i];
	}
	return hashf;
}

//нахождение длины максимальной цепочки
int len_max(struct HashTable* table) {
	int t = 0, max = 0;
	for (size_t z = 0; z < table->size; z++)
	{
		t = 0;
		struct Node* c = table->buckets[z].head;
		while (c != NULL)
		{
			t++;
			c = c->next;
		}
		max = max > t ? max : t;
	}
	return max;
}
//количество ненулевых цепочек
int len_NULL(struct HashTable* table) {
	int t = 0, colvo = 0;
	for (size_t z = 0; z < table->size; z++)
	{
		t = 0;
		struct Node* c = table->buckets[z].head;
		while (c != NULL)
		{
			t++;
			c = c->next;
		}
		if (t > 0) colvo++;
	}
	return colvo;
}
//средняя длина цепочки
int len_cr(struct HashTable* table) {
	int t = 0, colvo = 0, sum = 0;
	for (size_t z = 0; z < table->size; z++)
	{
		t = 0;
		struct Node* c = table->buckets[z].head;
		while (c != NULL)
		{
			t++;
			c = c->next;
		}
		colvo++;
		sum = sum + t;
	}
	return sum / colvo;
}
//минимальная длина непустой цепочки, 
int len_min(struct HashTable* table) {
	int t = 0, min = 900000;
	for (size_t z = 0; z < table->size; z++)
	{
		t = 0;
		struct Node* c = table->buckets[z].head;
		while (c != NULL)
		{
			t++;
			c = c->next;
		}
		if (t != 0) {
			min = min < t ? min : t;
		}

	}
	return min;
}
int main() {
	int i = -1;
	char data[50];
	struct HashTable table = createHashTable(100000);
	FILE* file = NULL;
	setlocale(LC_ALL, "Rus");
	file = fopen("Voynaimir.txt", "rt");
	if (file == NULL) {
		perror("Failed to open file Voynaimir.");
		exit(1);
	}
	const clock_t start = clock();
	while (!feof(file)) {
		i++;
		fscanf(file, "%s", data);
		setValue(&table, data, i);
		strcpy(data, "");
	}
	const clock_t finish = clock();
	printf("%d\n", len_max(&table));
	printf("%d\n", len_min(&table));
	printf("%d\n", len_cr(&table));
	printf("%d\n", len_NULL(&table));
	double time = (double)(finish - start);
	fclose(file);
	printf("%1f \n", time);
	printHashTable(&table);
	clearHashTable(&table);
}
