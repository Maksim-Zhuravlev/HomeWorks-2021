#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#endif // LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_WORD_LENGTH 20

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH];


struct Payload{
	keyType key;
	valueType value;
};

void printPayload(struct Payload data){
	printf("key = %s, value = %d\n", data.key, data.value);
}


struct Node{
	struct Payload data;
	struct Node* next;
};

struct LinkedList{
	size_t listSize;
	struct Node* head;
};

void setPayloadKey(struct Payload* payload, keyType key){
	strcpy(payload->key, key);
}

void setPayloadValue(struct Payload* payload, valueType value) {
	payload->value = value;
}

struct Node* getNode(struct Payload data){
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL)
    {
		perror("Not enough memory");
		exit(1);
	}

	res->data = data;
	res->next = NULL;
	return res;
}

void addNode(struct LinkedList* list, struct Payload data){
	struct Node* node = getNode(data);
	if (list->head == NULL)
    {
		list->head = node;
	}
	else
	{
		node->next = list->head;
		list->head = node;
	}

	list->listSize++;
}

_Bool compareKeys(keyType key1, keyType key2){
	return !strcmp(key1, key2);
}

struct Node* findNode(struct LinkedList* list, keyType key){
	struct Node* curr = list->head;
	while (curr != NULL) {
		if (compareKeys(key, curr->data.key))
        {
			break;
		}
		curr = curr->next;
	}
	return curr;
}

void printList(struct LinkedList* list){
	struct Node* curr = list->head;
	while (curr != NULL)
    {
		printPayload(curr->data);
		curr = curr->next;
	}
}


void clearList(struct LinkedList* list){
	struct Node* curr = list->head;
	while (curr != NULL)
    {
		struct Node* savedNext = curr->next;
		free(curr);
		curr = savedNext;
	}

	list->listSize = 0;
	list->head = NULL;
}


struct LinkedList createLinkedList(){
	struct LinkedList list;
    list.listSize = 0;
    list.head = NULL;

	return list;
}

