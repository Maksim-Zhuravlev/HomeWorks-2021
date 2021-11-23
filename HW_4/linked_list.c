#include <stdio.h>
#include <stdlib.h>

#include "payload.h"
#include "linked_list.h"


struct Node *getNode(struct Payload data) {
    struct Node *res = malloc(sizeof(struct Node));
    if (res == NULL) {
        perror("Not enough memory");
        exit(1);
    }
    res->data = data;
    res->next = NULL;
    return res;
}


void addNode(struct LinkedList *list, struct Payload data) {
    struct Node *node = getNode(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

struct Node *findNode(struct LinkedList *list, keyType key) {
    struct Node *curr = list->head;
    while (curr != NULL) {
        if (compareKeys(key, curr->data.key)) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

void printList(struct LinkedList *list) {
    struct Node *curr = list->head;
    while (curr != NULL) {
        printPayload(curr->data);
        curr = curr->next;
    }
}

void clearList(struct LinkedList *list) {
    struct Node *curr = list->head;
    while (curr != NULL) {
        struct Node *savedNext = curr->next;
        free(curr);
        curr = savedNext;
    }
    list->size = 0;
    list->head = NULL;
}

struct LinkedList createLinkedList() {
    struct LinkedList list = {.size = 0, .head = NULL};
    return list;
}
