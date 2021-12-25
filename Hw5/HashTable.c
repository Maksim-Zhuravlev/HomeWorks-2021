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


typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
	keyType key;
	valueType value;
};


void printPayload(struct Payload data, FILE* result) {
	fprintf(result, "Слово = %s, Количество = %d\n", data.key, data.value);
}

size_t getHashConst(keyType key) {
	size_t res = 4;
	return res;
}

size_t getHashSum(keyType key) {
	size_t res = 0;
	size_t pos = 0;

	while (key[pos]) {
		res += key[pos];
		pos++;
	}
	return res;
}

size_t getHashThird(keyType key) {

	size_t res = 0;
	size_t pos = 0;

	while (key[pos]) {
		res += (size_t)key[pos] * (size_t)pow(3, pos);
		pos++;
	}

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

char* wordWithoutSigns(keyType word) {
	static char newWord[MAX_WORD_LENGTH];
	int n = 0;
	for (size_t k = 0; k <= strlen(newWord); k++) {
		if (word[k] != '(' && word[k] != ')' && word[k] != '.' && word[k] != ',' && word[k] != ';' && word[k] != ':'
			&& word[k] != '\'' && word[k] != '\"' && word[k] != '!' && word[k] != '?' && word[k] != '-'
			&& word[k] != '[' && word[k] != '{' && word[k] != '}' && word[k] != '<' && word[k] != '>') {
			newWord[n] = word[k];
			n++;
		}
	}
	return newWord;
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
	res->data = data;
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

void printList(struct LinkedList* list, FILE* result) {
	struct Node* curr = list->head;
	while (curr != NULL) {
		printPayload(curr->data, result);
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


size_t getBucket(struct HashTable* table, keyType key, size_t(*HashFunc)(keyType)) {
	return HashFunc(key) % table->size;
}


void setValue(struct HashTable* table, keyType key, valueType value, size_t(*HashFunc)(keyType)) {
	size_t bucket = getBucket(table, key, HashFunc);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	if (node) {
		node->data.value = value;
	}
	else {
		struct Payload payload;
		setPayloadKey(&payload, key);
		setPayloadValue(&payload, value);
		addNode(list, payload);
	}
}

void countWord(struct HashTable* table, char* key, size_t(*HashFunc)(keyType)) {
	size_t bucket = getBucket(table, key, HashFunc);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	if (node) {
		node->data.value += 1;
	}
	else {
		struct Payload payload;
		setPayloadKey(&payload, key);
		setPayloadValue(&payload, 1);
		addNode(list, payload);
	}
}

valueType getValue(struct HashTable* table, keyType key, valueType defValue, size_t(*HashFunc)(keyType)) {
	size_t bucket = getBucket(table, key, HashFunc);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	return node ? node->data.value : defValue;
}

void printHashTable(struct HashTable* table, FILE* result) {
	_Bool hasData = false;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size != 0) {
			printList(bucket, result);
			hasData = true;
		}
	}
	if (!hasData) {
		printf("The hash table is empty\n");
	}
}

void HashTableStatistic(struct HashTable* table, FILE* statisticFile) {

	size_t maxLen = 0;
	size_t minLen = 0;
	size_t NonZeroLists = 0;
	size_t len = 0;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size != 0) {
			NonZeroLists++;
			len += bucket->size;
			if (bucket->size > maxLen) {
				maxLen = bucket->size;
			}
			if (bucket->size < minLen || minLen == 0) {
				minLen = bucket->size;
			}
		}
	}

	fprintf(statisticFile, "Количество ненулевых цепочек: %d\n", NonZeroLists);
	fprintf(statisticFile, "Максимальная длина ненулевой цепочки: %d\n", maxLen);
	fprintf(statisticFile, "Минимальная длина ненулевых цепочек: %d\n", minLen);
	fprintf(statisticFile, "Средняя длина ненулевых цепочек: %d\n\n", len / NonZeroLists);
}

void WriteStatistic(FILE* textFile, FILE* statisticFile, size_t(*HashFunc)(keyType), size_t n) {

	fprintf(statisticFile, "Статистика для %d корзин:\n\n", n);

	keyType word;
	struct HashTable table = createHashTable(n);

	while (fscanf(textFile, "%s", &word) == 1) {
		countWord(&table, wordWithoutSigns(word), HashFunc);
	}

	HashTableStatistic(&table, statisticFile);
	fseek(textFile, 0, SEEK_SET);
	clearHashTable(&table);
}

void WriteResult(FILE* textFile, FILE* resultFile, size_t(*HashFunc)(keyType), size_t n) {

	keyType word;
	struct HashTable table = createHashTable(n);

	while (fscanf(textFile, "%s", &word) == 1) {
		countWord(&table, wordWithoutSigns(word), HashFunc);
	}
	printHashTable(&table, resultFile);
	fseek(textFile, 0, SEEK_SET);
	clearHashTable(&table);
}


int main() {

	setlocale(LC_ALL, "Rus");

	FILE* statisticFile;
	FILE* text;
	FILE* result;

	result = fopen("result.txt", "w");
	if (result == NULL) {
		printf("The file could not be opened.");
		exit(1);
	}

	statisticFile = fopen("statisticFile.txt", "w");
	if (statisticFile == NULL) {
		printf("The file could not be opened.");
		exit(1);
	}

	text = fopen("mertvye-dushi.txt", "r");
	if (text == NULL) {
		printf("The file could not be opened.");
		exit(1);
	}

	size_t(*HashFuncs[3])(keyType) = { getHashConst, getHashSum, getHashThird };

	fprintf(statisticFile, "Статистика для %d хэш-функции:\n", 1);
	WriteStatistic(text, statisticFile, HashFuncs[0], 10);

	for (size_t i = 1; i <= 2; i++) {
		fprintf(statisticFile, "\n\nСтатистика для %d хэш-функции:\n", i + 1);
		for (size_t n = 10; n <= 100000; n *= 10) {
			WriteStatistic(text, statisticFile, HashFuncs[i], n);
		}
	}

	WriteResult(text, result, HashFuncs[2], 10000);

	fclose(statisticFile);
	fclose(text);
	fclose(result);

	return 0;
}