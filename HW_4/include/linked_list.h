#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H

#include "payload.h"


struct List_Node {
    struct Payload data;
    struct List_Node *next;
};

struct Linked_List {
    size_t size;
    struct List_Node *head;
};


struct List_Node *getNode(struct Payload data);

void addNode(struct Linked_List *list, struct Payload data);

struct List_Node *findNode(struct Linked_List *list, keyType key);

void printList(struct Linked_List *list);

void clearList(struct Linked_List *list);

struct Linked_List createLinkedList();


#endif //UNTITLED_LINKED_LIST_H
