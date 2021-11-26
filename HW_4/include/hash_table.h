#ifndef UNTITLED_HASH_TABLE_H
#define UNTITLED_HASH_TABLE_H

#include "payload.h"


struct HashTable {
    size_t size;
    struct Linked_List *buckets;
    size_t (*hash_function)(const keyType);
};



size_t getHash(struct HashTable *hash_table, keyType key);

struct HashTable createHashTable(size_t size, size_t (*function_ptr)(const keyType));

void clearHashTable(struct HashTable *table);

size_t getBucket(struct HashTable *table, keyType key);

void setValue(struct HashTable *table, keyType key, valueType value);

valueType getValue(struct HashTable *table, keyType key, valueType defValue);

void printHashTable(struct HashTable *table);


#endif //UNTITLED_HASH_TABLE_H
