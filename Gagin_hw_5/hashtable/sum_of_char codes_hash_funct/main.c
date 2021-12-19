//Attention:
//If you see the error: "Did not open the file. Exiting.", you should:
//Create build-debug folder and add file "text.txt" into her.
//Or you can specify the full path to the folder on 392 line of this program.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//===================== specific part=========================

#define MAX_WORD_LENGTH 100

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];

struct Payload
{
	keyType key;
	valueType value;
};

void printPayload(struct Payload data)
{
	printf("key = %s, value = %d\n", data.key, data.value);
}

size_t getHash(keyType key)
{
	size_t res = 0;
	while (*key++)
		{
		res += *key - 'A';
		}
	return res;
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

struct Node
{
	struct Payload data;
	struct Node* next;
};

struct LinkedList
{
	size_t size;
	struct Node *head;
};

struct HashTable
{
	size_t size;
	struct LinkedList *buckets;
};

struct Node* getNode(struct Payload data)
{
	struct Node* result = malloc(sizeof(struct Node));
	if (NULL == result)
	{
		perror("Not enough memory. Exiting.");
		exit(1);
	}
	result->data = data;
	result->next = NULL;
	return result;
}

void addNode(struct LinkedList* list, struct Payload data)
{
	struct Node* node = getNode(data);
	if (NULL == list->head)
	{
		list->head = node;
	}
	else
	{
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

struct Node* findNode(struct LinkedList* list, keyType key)
{
	struct Node* curr = list->head;
	while(NULL != curr)
	{
		if (compareKeys(key, curr->data.key))
		{
			break;
		}
		curr = curr->next;
	}
	return curr;
}

void printList(struct LinkedList* list)
{
	struct Node* curr = list->head;
	while(NULL != curr)
	{
		printPayload(curr->data);
		curr = curr-> next;
	}
}

void clearList(struct LinkedList* list)
{
	struct Node* curr = list->head;
	while(NULL != curr)
	{
		struct Node* savedNext = curr->next;
		free(curr);
		curr = savedNext;
	}
	list->size = 0;
	list->head = NULL;
}

struct LinkedList createLinkedList()
{
	struct LinkedList list = {.size = 0, .head = NULL};
	return list;
}

struct HashTable createHashTable(size_t size)
{
	struct LinkedList *buckets = malloc(sizeof(struct LinkedList) * size);
	if (NULL == buckets)
	{
		perror("Not enough memory to create hash-table. Exiting.");
		exit(1);
	}

	for (size_t i = 0; i < size; i++)
	{
		buckets[i] = createLinkedList();
	}
	struct HashTable table = {.size = size, .buckets = buckets};
	return table;
}

void clearHashTable(struct HashTable* table)
{
	for (size_t i = 0; i < table->size; i++)
	{
		clearList(&table->buckets[i]);
	}
	free(table->buckets);
	table->buckets = NULL;
	table->size = 0;
}

size_t getBucket(struct HashTable *table, keyType key)
{
	return getHash(key) % table->size;
}

void setValue(struct HashTable *table, keyType key, valueType value)
{
	size_t bucket = getBucket(table, key);
	struct LinkedList *list = &table->buckets[bucket];
	struct Node *node = findNode(list, key);
	if (node)
	{
		node->data.value = value;
	}
	else
	{
		struct Payload payload = {};
		setPayloadKey(&payload, key);
		setPayloadValue(&payload, value);
		addNode(list, payload);
	}
}

valueType getValue(struct HashTable *table, keyType key, valueType defValue)
{
	size_t bucket = getBucket(table, key);
	struct LinkedList *list = &table->buckets[bucket];
	struct Node *node = findNode(list, key);
	return node ? node->data.value : defValue;
}

void printHashTable(struct HashTable *table)
{
	_Bool hasData = false;
	for (size_t i = 0; i < table->size; i++)
	{
		struct LinkedList *bucket = &table->buckets[i];
		if (bucket->size != 0)
		{
			printList(bucket);
			hasData = true;
		}
	}
	if (!hasData)
	{
		printf("The hash table is empty\n");
	}
}

//----------------------------------------------------------------------------------------------------

int lenOfLinkedList(struct LinkedList list)
{
	if (NULL == (list).head)
	{
		return 0;
	}
	else
	{
		int counter = 1;
		struct Node *node = (list).head;
		while (NULL != node->next)
		{
			node = node->next;
			counter += 1;
		}
		return counter;
	}
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

void doWorkWithHashTable(int isPrintResult, size_t size)
{
	clock_t start = clock();
	//-----
	struct HashTable table = createHashTable(size);
	FILE *fp;
	char word[MAX_WORD_LENGTH + 1];
	char good_word[MAX_WORD_LENGTH + 2];
	if ((fp = fopen("name.txt", "r")) == NULL)
	{
		printf("Did not open the file. Exiting.");
		exit(1);
	}

	while (fscanf(fp, "%s", word) != EOF)
	{
		int x;
		destroyer_of_bad_signs(word, good_word);
		x = getValue(&table, good_word, 0);
		setValue(&table, good_word, x + 1);
	}
	fclose(fp);
	//-----
	if (isPrintResult == 1)
	{
		printHashTable(&table);
		printf("/////\n");
	}
	//-----
	int linked_list_len;
	int not_zero_linked_lists = 0;
	double average_linked_lists_len = 0;
	int counter_for_average = 0;
	int min_not_zero_linked_list_len = 1000000;
	int max_not_zero_linked_list_len = 0;

	for (size_t k = 0; k < size; k++)
	{
		linked_list_len = lenOfLinkedList(*(table.buckets + k));
		if (0 != linked_list_len)
		{
			average_linked_lists_len += linked_list_len;
			counter_for_average += 1;
			not_zero_linked_lists += 1;
			min_not_zero_linked_list_len = MIN(min_not_zero_linked_list_len, linked_list_len);
			max_not_zero_linked_list_len = MAX(max_not_zero_linked_list_len, linked_list_len);
		}
	}
	if (counter_for_average != 0)
	{
		average_linked_lists_len /= counter_for_average;
	}

	//-----
	clearHashTable(&table);
	//-----
	clock_t finish = clock();
	double timeElapsed = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printf("Size of hash-table: %zu, Work-time: %f sec.\n", size, timeElapsed);
	printf("Number of non-zero linked lists: %d\n", not_zero_linked_lists);
	printf("Average linked list length: %f\n", average_linked_lists_len);
	printf("Minimum length of a non-empty linked list: %d\n", min_not_zero_linked_list_len);
	printf("Maximum length of a non-empty linked list: %d\n", max_not_zero_linked_list_len);
	printf("/////\n");
}

int main()
{
	for (size_t size = 1; size <= 100000; size *= 10)
	{
		int isPrintResult = 0;
		if (size == 1)
		{
			isPrintResult = 1;
		}
		doWorkWithHashTable(isPrintResult,size);
	}
	printf("Our hash-function: Sum of char codes.\n");
	return 0;
}
