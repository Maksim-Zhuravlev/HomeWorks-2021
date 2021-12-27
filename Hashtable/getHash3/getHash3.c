#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//===================== specific part =========================

#define MAX_WORD_LENGTH 100


typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
    keyType key;
    valueType value;
};


void printPayload(struct Payload data) {
    printf("key = %s, value = %d\n", data.key, data.value);
}


size_t getHash(keyType key) {
    int res = 0;
    for(; *key; key++) {
        res = (res * 1664525) + (unsigned char) (*key) + 1013904223;
    }
    return res;
}


int compareKeys(keyType key1, keyType key2) {
    return !strcmp(key1, key2);
}


void setPayloadKey(struct Payload *payload, keyType key) {
    strcpy(payload->key, key);
}


void setPayloadValue(struct Payload *payload, valueType value) {
    payload->value = value;
}

//===================== common part =========================\

struct Node {
    struct Payload data;
    struct Node* next;
};

struct LinkedList {
    size_t size;
    struct Node *head;
};


struct HashTable {
    size_t size;
    struct LinkedList *buckets;
};


struct Node* getNode(struct Payload data) {
    struct Node* res = malloc(sizeof(struct Node));
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
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}


struct Node* findNode(struct LinkedList* list, keyType key) {
    struct Node* curr = list->head;
    while(curr != NULL) {
        if (compareKeys(key, curr->data.key)) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

void printList(struct LinkedList* list) {
    struct Node* curr = list->head;
    while(curr != NULL) {
        printPayload(curr->data);
        curr = curr-> next;
    }
}


void clearList(struct LinkedList* list) {
    struct Node* curr = list->head;
    while(curr != NULL) {
        struct Node* savedNext = curr->next;
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

struct HashTable createHashTable(size_t size) {
    struct LinkedList *buckets = malloc(sizeof(struct LinkedList) * size);
    if (buckets == NULL) {
        perror("Cannot allocate memory for HashTable");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        buckets[i] = createLinkedList();
    }


    struct HashTable table = {.size = size, .buckets = buckets};
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


size_t getBucket(struct HashTable *table, keyType key) {
    return getHash(key) % table->size;
}


void setValue(struct HashTable *table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct LinkedList *list = &table->buckets[bucket];
    struct Node *node = findNode(list, key);
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
    struct LinkedList *list = &table->buckets[bucket];
    struct Node *node = findNode(list, key);
    return node ? node->data.value : defValue;
}


void printHashTable(struct HashTable *table) {
    int hasData = false;
    for (size_t i = 0; i < table->size; i++) {
        struct LinkedList *bucket = &table->buckets[i];
        if (bucket->size != 0) {
            printList(bucket);
            hasData = true;
        }
    }
    if (!hasData) {
        printf("The hash table is empty\n");
    }
}

void statistics(struct HashTable *table) {
    int nonzeroLists = 0;
    double length = 0, listLength;
    int minLength = 100000, maxLength = 1;
    for(size_t i = 0; i < table->size; i++) {
        struct LinkedList *bucket = &table->buckets[i];
        if (bucket->size != 0) {
            length += bucket->size;
            nonzeroLists++;
            if (bucket->size < minLength) {
                minLength = bucket->size;
            }
            if (bucket->size > maxLength) {
                maxLength = bucket->size;
            }
        }
    }
    listLength = length / (double)nonzeroLists;
    printf("The number of nonzero linked lists: %d\n"
           "The average length of nonzero linked list: %lf\n"
           "The minimum length of nonzero list: %d\n"
           "The maximum length of nonzero list: %d\n",
           nonzeroLists, listLength, minLength, maxLength);
}


void withoutBadSymbols(char *word, char *normalWord) {
    int a = 0;
    int i = 0;
    while(word[i] != '\0') {
        int flag = 0;
        if (word[i] == '.' || word[i] == '!' || word[i] == '?' || word[i] == ',' || word[i] == '(' || word[i] == ')') {
            flag += 1;
        }
        if (flag == 0) {
            normalWord[a] = word[i];
            a++;
        }
        i++;
    }
    normalWord[a] = '\0';
}


int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH + 1];
    char normalWord[MAX_WORD_LENGTH + 2];
    int i = 1;
    while(i <= 100000) {
        printf("Hash table size: %d\n", i);
        file = fopen("kolobok.txt", "r");
        if (file == NULL) {
            printf("The file didn't open.\n");
            exit(1);
        }
        struct HashTable table = createHashTable(i);
        clock_t start = clock();
        while (fscanf(file, "%s", word) != EOF) {
            withoutBadSymbols(word, normalWord);
            int x;
            x = getValue(&table, normalWord, 0);
            setValue(&table, normalWord, x + 1);
        }
        printHashTable(&table);
        statistics(&table);
        clearHashTable(&table);
        clock_t finish = clock();
        double time = ((double)(finish - start)) / CLOCKS_PER_SEC;
        printf("Time: %lf\n", time);
        i = i * 10;
    }
    return 0;
}





