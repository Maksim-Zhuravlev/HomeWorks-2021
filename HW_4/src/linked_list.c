#include <stdio.h>
#include <stdlib.h>

#include "../include/payload.h"
#include "../include/linked_list.h"


struct List_Node *getNode(struct Payload data) {
    struct List_Node *res = malloc(sizeof(struct List_Node));
    if (res == NULL) {
        perror("Not enough memory");
        exit(1);
    }
    res->data = data;
    res->next = NULL;
    return res;
}


void addNode(struct Linked_List *list, struct Payload data) {
    struct List_Node *node = getNode(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

struct List_Node *findNode(struct Linked_List *list, keyType key) {
    struct List_Node *curr = list->head;
    while (curr != NULL) {
        if (compareKeys(key, curr->data.key)) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

void printList(struct Linked_List *list) {
    struct List_Node *curr = list->head;
    while (curr != NULL) {
        printPayload(curr->data);
        curr = curr->next;
    }
}

void clearList(struct Linked_List *list) {
    struct List_Node *curr = list->head;
    while (curr != NULL) {
        struct List_Node *savedNext = curr->next;
        free(curr);
        curr = savedNext;
    }
    list->size = 0;
    list->head = NULL;
}

struct Linked_List createLinkedList() {
    struct Linked_List list = {.size = 0, .head = NULL};
    return list;
}
