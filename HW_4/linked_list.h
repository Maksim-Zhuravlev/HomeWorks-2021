#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H

#include "payload.h"


struct Node {
    struct Payload data;
    struct Node *next;
};

struct LinkedList {
    size_t size;
    struct Node *head;
};


struct Node *getNode(struct Payload data);

void addNode(struct LinkedList *list, struct Payload data);

struct Node *findNode(struct LinkedList *list, keyType key);

void printList(struct LinkedList *list);

void clearList(struct LinkedList *list);

struct LinkedList createLinkedList();


#endif //UNTITLED_LINKED_LIST_H
