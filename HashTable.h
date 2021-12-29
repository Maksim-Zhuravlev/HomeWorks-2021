#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <iostream>
#include <cstdlib>


//===================== specific part =========================\\

#define MAX_WORD_LENGTH 1000

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
    keyType key;
    valueType value;
};

void printPayload(struct Payload data) {
    printf("key = %s, value = %d\n", data.key, data.value);
} 

size_t getHashSum(char* str)
{
    int l = strlen(str);
    int res = 0;
    for (int i = 0; i < l; i++)
    {
        res += str[i];
    }
    return res;
}

size_t getHashMult(char* str)
{
    int l = strlen(str);
    int res = 0;
    int mult = 31;

    for (int i = 0; i < l; i++)
    {
        res = res + str[i] * mult;
        mult = mult * 31;
    }
    return res;
}

size_t getHash(keyType key) {

    return 1;
}

bool compareKeys(keyType key1, keyType key2) {
    return !strcmp(key1, key2);
} 

void setPayloadKey(struct Payload* payload, keyType key) {
    strcpy_s(payload->key, key);
} 

void setPayloadValue(struct Payload* payload, valueType value) {
    payload->value = value;
} 

//===================== common part =========================\\

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
    struct Node* res = (Node*)malloc(sizeof(struct Node));
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
    struct LinkedList list = { 0, NULL };
    return list;
}

struct HashTable createHashTable(size_t size) {

    struct LinkedList* buckets = (LinkedList*)malloc(sizeof(struct LinkedList) * size);
    if (buckets == NULL) {
        perror("Cannot allocate memory for HashTable");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        buckets[i] = createLinkedList();
    }

    struct HashTable table = { size, buckets };
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
    return getHashMult(key) % table->size;
}

void setValue(struct HashTable* table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct LinkedList* list = &table->buckets[bucket];
    struct Node* node = findNode(list, key);
    if (node) {
        node->data.value = value;
    }
    else {
        struct Payload payload = {};
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
    bool hasData = false;
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
