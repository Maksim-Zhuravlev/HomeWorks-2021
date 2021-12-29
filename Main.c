#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_INT_VALUE 2147483647

//===================== specific part =========================

#define MAX_WORD_LENGTH 50

/////
typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];

/////
struct Payload {
	keyType key;
	valueType value;
};
/*
 int main()
 {	struct payload q;
 // q.key = "string";
 // q.value = 1;
*/
/////
void printPayload(struct Payload data) {
	printf("key = %s, value = %d\n", data.key, data.value);
}
/* find_key: получим указатель на узел односвязного списка, где хранится нужная пара ключ значение:
 * А printPayload печатает эту пару
 */
 /////
size_t getHash(keyType key) {
	size_t result = 0;

	/*
	for (size_t i = 0; i < (size_t)strlen(key); i++) {
		result += (int)key[i];
	} 
	*/

	//result = strlen(key);
	return result;
}


int compareKeys(keyType key1, keyType key2) { //comparekeys != 0 => ключи равны (слова)
	return !strcmp(key1, key2);
}


void setPayloadKey(struct Payload* payload, keyType key) {
	strcpy(payload->key, key);
}


void setPayloadValue(struct Payload* payload, valueType value) {
	payload->value = value;
}

//===================== common part =========================\\

struct Node {
	struct Payload data;
	struct Node* next;
};

/////
struct LinkedList {
	size_t size;
	struct Node* head;
};

/////
struct HashTable {
	size_t size;
	struct LinkedList* buckets;
};

/////
struct Node* getNode(struct Payload data) {
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL) {
		perror("Not enough memory");
		exit(1);
	}
	res->data = data; //(*res).data
	res->next = NULL;
	return res;
}
/////
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

/////
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

/////
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

/////
struct LinkedList createLinkedList() {
	struct LinkedList list = { .size = 0, .head = NULL };
	return list;
}
/////
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

/////
void clearHashTable(struct HashTable* table) {
	for (size_t i = 0; i < table->size; i++) {
		clearList(&table->buckets[i]);
	}
	free(table->buckets);
	table->buckets = NULL;
	table->size = 0;
}
// struct Payload data;
//data.key = "string";
//data.value = 5;
//struct Payload *data_pointer;
//*(data_pointer)
//data.key = "string";
//data.value = 5;
//


/////
size_t getBucket(struct HashTable* table, keyType key) {
	return getHash(key) % table->size;
}

/////
void setValue(struct HashTable* table, keyType key, valueType value) {
	size_t bucket = getBucket(table, key);
	struct LinkedList* list = &(table->buckets[bucket]);
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
/////
valueType getValue(struct HashTable* table, keyType key, valueType defValue) {
	size_t bucket = getBucket(table, key);
	struct LinkedList* list = &(table->buckets[bucket]);
	struct Node* node = findNode(list, key);
	return node ? node->data.value : defValue;
}

/////
void printHashTable(struct HashTable* table) {
	//int hasData = false;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size != 0) {
			printList(bucket);
			//hasData = true;
		}
	}
	//if (!hasData) {
	//	printf("The hash table is empty\n");
}
// функция 1: количество ненулевых цепочек
int nonZeroCount(struct HashTable *table) {
	int counter = 0;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size != 0) {
			counter += 1;
		}
	}
	return counter;
}


//функция 2: средняя длина цепочки,
double averageLength(struct HashTable* table) {
	size_t lengths = 0;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		lengths += bucket->size;
	}
	double result = (double)lengths / ((double)(table->size));
	return result;
}

//функция 3: минимальная длина непустой цепочки
size_t minLength(struct HashTable* table) {
	size_t minimum = MAX_INT_VALUE;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size < minimum && bucket->size != 0) {
			minimum = bucket->size;
		}
	}
	return minimum;
}

//функция 4: максимальная длина непустой цепочки
size_t maxLength(struct HashTable* table) {
	size_t maximum = 0;
	for (size_t i = 0; i < table->size; i++) {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->size > maximum) {
			maximum = bucket->size;
		}
	}
	return maximum;
}

void normal_words(char* word, char* normal_word) {
	keyType not_normal = ".,!():;?/";
	int g = 0;
	int i = 0;

	while (word[i] != '\0') {
		int flag = 0;
		int a = 0;
		while (not_normal[a] != '\0') {
			if (word[i] == not_normal[a]) {
				flag += 1;
			}
			a++;
		}
		if (flag == 0)
		{
			normal_word[g] = word[i];
			g++;
		}
		i++;
	}
	normal_word[g] = '\0';
}


//func(char *key, int value)
//func(char *key)

int main() {
	FILE* file;
	char word[MAX_WORD_LENGTH + 1];
	char normal_word[MAX_WORD_LENGTH + 2];
	for (size_t i = 1; i <= 100000; i *= 10) {
		
		file = fopen("text.txt", "r");
		if (file == NULL) {
			printf("The file didn't open.\n");
			exit(1);
		}
		clock_t start = clock();

		struct HashTable table = createHashTable(i);
		char word[MAX_WORD_LENGTH];
		while (fscanf(file, "%s", word) != EOF) {
			normal_words(word, normal_word);
			int x = getValue(&table, word, 0);
			setValue(&table, word, x + 1);
		}

		clock_t finish = clock();

		printHashTable(&table);

		printf("\nSize of the table = %d\n", i);
		printf("\nThe number of non-zero lists = %d\n", nonZeroCount(&table));
		printf("\nThe average length of the list = %lf\n",averageLength(&table));
		printf("\nThe minimum length of the non-zero list = %zu\n", minLength(&table));
		printf("\nThe maximum length of the non-zero list = %zu\n", maxLength(&table));

		clearHashTable(&table);

		double time = ((double)(finish - start)) / CLOCKS_PER_SEC;
		printf("\nWorking hours of the program = %f\n\n\n", time);

		fclose(file);

	}
	
	return 0;
}