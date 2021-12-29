#ifndef HARSH_TABLE_H_INCLUDED
#define HARSH_TABLE_H_INCLUDED



#endif // HARSH_TABLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "list.h"


size_t getHashConst(keyType key) {
	size_t res = 0;
	return res;
}


int getHashSum(char* str)
{
	int l = strlen(str);
	int res = 0;

	for (int i = 0; i < l; i++)
	{
		res += str[i];
	}

	return res;
}

int getHashMul(char* str)
{
	int l = strlen(str);
	int res = 0;
	int mul = 31;

	for (int i = 0; i < l; i++)
	{
		res =  res+str[i]*mul;
		mul=mul*31;
	}

	return res;
}

int getHash(char* str){
    return getHashMul(str);
}


struct HashTable {
	size_t size;
	struct LinkedList* buckets;
};

struct HashTable createHashTable(size_t size) {
	struct LinkedList* buckets = malloc(sizeof(struct LinkedList) * size);
	if (buckets == NULL)
    {
		perror("Cannot allocate memory for HashTable");
		exit(1);
	}

	for (size_t i = 0; i < size; i++)
    {
		buckets[i] = createLinkedList();
	}

	struct HashTable table = { .size = size, .buckets = buckets };
	return table;
}

void clearHashTable(struct HashTable* table){
	for (size_t i = 0; i < table->size; i++)
    {
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


valueType getValue(struct HashTable* table, keyType key, valueType defValue) {
	size_t bucket = getBucket(table, key);
	struct LinkedList* list = &table->buckets[bucket];
	struct Node* node = findNode(list, key);
	return node ? node->data.value : defValue;
}


void printHashTable(struct HashTable* table) {
	_Bool hasData = 0;
	for (size_t i = 0; i < table->size; i++)
    {
		struct LinkedList* bucket = &table->buckets[i];
		if (bucket->listSize != 0)
        {
			printList(bucket);
			hasData = 1;
		}
	}

	if (!hasData)
    {
		printf("The hash table is empty\n");
	}
}


int get_num(struct HashTable* table){
    int res = 0;
	for (size_t i = 0; i < table->size; i++)
	{
		struct Node* c = table->buckets[i].head;
		if (c != NULL)
		{
            res++;
		}
	}

	return res;
}


int get_max_len(struct HashTable* table) {
	int len = 0, res = 0;
	for (size_t i = 0; i < table->size; i++)
	{
		len = 0;
		struct Node* c = table->buckets[i].head;
		while (c != NULL)
		{
			len++;
			c = c->next;
		}

		if (len > res)
            res = len;

	}

	return res;
}


int get_med_len(struct HashTable* table){
    int sum = 0, num = 0;
	for (size_t i = 0; i < table->size; i++)
	{
	    int len = 0;
		struct Node* c = table->buckets[i].head;

		if (c != NULL)
            num++;

		while (c != NULL)
		{
			len++;
			c = c->next;
		}

		sum = sum+len;
	}

	return sum/num;
}


int get_min_len(struct HashTable* table){
    int len = 0, res = 1000000;
	for (size_t i = 0; i < table->size; i++)
	{
		len = 0;
		struct Node* c = table->buckets[i].head;

		if (c != NULL)
        {
            while (c != NULL)
            {
                len++;
                c = c->next;
            }

            if (len < res)
                res = len;
        }
	}

	return res;
}

void printf_statistic(struct HashTable* table){
    printf("num of buckets = %d, min bucket size = %d, med bucket size = %d, max bucket size = %d \n",
        get_num(table), get_min_len(table), get_med_len(table), get_max_len(table) );

}


void addWord(struct HashTable* table, char* str){
    setValue(table, str, getHash(str));
}





