#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

//===================== specific part =========================
#define INFINITY 100000000
#define MAX_WORD_LENGTH 50
#define STR_SIZE 21


typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];
//

struct Payload {
    keyType key;
    valueType value;
};

void printPayload(struct Payload data) {
    printf("key = %s, value = %d\n", data.key, data.value);


}
size_t getHash(char* key) {
    size_t index = 0;
    size_t hashIndex = 0;
    while (key[index]) {
        hashIndex += key[index++];
    }
    return hashIndex;
}
/*
size_t getHash(keyType key) {
    size_t hashval;
    for (hashval = 0; *key != '\0'; ++key) {
        hashval = *key + 31 * hashval;
    }
    return hashval;
}
*/
/*
size_t getHash(keyType key) {
    return 30;
}
*/

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
    struct Node *next;
};

struct LinkedList {
    size_t size;
    struct Node *head;
};


struct HashTable {
    size_t size;
    struct LinkedList *buckets;
};


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

//
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

//
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


void clearHashTable(struct HashTable *table) {
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

//statistics
size_t elementCount(struct HashTable *table) {
    size_t res = 0;
    for (size_t i = 0; i < table->size; i++) {

        res += table->buckets[i].size;
    }
    return res;
}

size_t minChainLength(struct HashTable *table) {
    size_t min = INFINITY;
    size_t i = 0;
    for (i = 0; i < table->size; i++) {
        if (min > table->buckets[i].size && table->buckets[i].size > 0) {
            min = table->buckets[i].size;
        }
    }
    return min;
}

size_t maxChainLength(struct HashTable *table) {
    size_t max = 0;
    size_t i = 0;
    for (i = 0; i < table->size; i++) {
        if (max < table->buckets[i].size) {
            max = table->buckets[i].size;
        }
    }
    return max;
}

size_t averageChainLength(struct HashTable *table) {
    size_t cnt = 0;
    size_t i = 0;
    for (i = 0; i < table->size; i++) {
        if (table->buckets[i].size > 0) {
            cnt++;
        }
    }
    return elementCount(table) / cnt;
}

int main() {
    for (size_t i = 1; i < 100000; i *= 10) {
        FILE *file = fopen("David_Copperfield.txt", "r");
        if (file == NULL) {
            printf("ERROR");
            return 1;
        }
        char *word = (char *) malloc(STR_SIZE * sizeof(char));
        if (word == NULL) {
            printf("ERROR");
            return 1;
        }
        clock_t begin, end;
        double timeSpend;
        begin = clock();
        struct HashTable table = createHashTable(i);
        while (fscanf(file, "%s", word) != EOF) {
            int x;
            x = getValue(&table, word, 0);
            setValue(&table, word, x + 1);
        }
        end = clock();
        timeSpend = (double) (end - begin) / CLOCKS_PER_SEC;
        //printHashTable(&table);

        size_t mnChainLen = minChainLength(&table),
                mxChainLen = maxChainLength(&table),
                avChainLen = averageChainLength(&table),
                elCount = elementCount(&table);
        printf("Statistics: \n Min Chain Length: %d \n Max Chain Length: %d \n Average Chain Length: %d \n Elements Count: %d \n Time to Fill Table: %f \n",
               mnChainLen, mxChainLen, avChainLen, elCount, timeSpend);
        clearHashTable(&table);
        free(word);
        fclose(file);

    }
    return 0;

}