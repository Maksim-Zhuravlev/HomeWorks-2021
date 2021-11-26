#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/payload.h"
#include "../include/linked_list.h"
#include "../include/hash_table.h"
#include "../include/hash_functions.h"



size_t getHash(struct HashTable *hash_table, keyType key){
    return hash_table->hash_function(key);
}

struct HashTable createHashTable(size_t size, size_t (*function_ptr)(const keyType)) {
    struct Linked_List *buckets = malloc(sizeof(struct Linked_List) * size);
    if (buckets == NULL) {
        perror("Cannot allocate memory for HashTable");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        buckets[i] = createLinkedList();
    }

    struct HashTable table = {.size = size, .buckets = buckets, .hash_function = function_ptr};
    return table;
}

void clearHashTable(struct HashTable *table) {
    for (size_t i = 0; i < table->size; i++) {
        clearList(&table->buckets[i]);
    }
    free(table->buckets);
    table->buckets = NULL;
    table->size = 0;
}

size_t getBucket(struct HashTable *table, keyType key) {
    return getHash(table, key) % table->size;
}

void setValue(struct HashTable *table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct Linked_List *list = &table->buckets[bucket];
    struct List_Node *node = findNode(list, key);
    if (node) {
        node->data.value = value;
    } else {
        struct Payload payload = {};
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        addNode(list, payload);
    }
}

valueType getValue(struct HashTable *table, keyType key, valueType defValue) {
    size_t bucket = getBucket(table, key);
    struct Linked_List *list = &table->buckets[bucket];
    struct List_Node *node = findNode(list, key);
    return node ? node->data.value : defValue;
}

void printHashTable(struct HashTable *table) {
    _Bool hasData = false;
    for (size_t i = 0; i < table->size; i++) {
        struct Linked_List *bucket = &table->buckets[i];
        if (bucket->size != 0) {
            printList(bucket);
            hasData = true;
        }
    }
    if (!hasData) {
        printf("The hash table is empty\n");
    }
}
