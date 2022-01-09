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

/*
size_t getHash(keyType key) {
    size_t res = 0;
    return res;
}
*/

size_t getHash(keyType key) {
    unsigned long long len = strlen(key);
    int res = 0;
    for(int i = 0; i < len; i++) {
        res += key[i];
    }
    return res;
}

/*
size_t getHash(keyType key) {
    int res = 2139062143;
    unsigned long long len = strlen(key);
    for(int i = 0; i < len; i++) {
        res = 37 * res + key[i];
    }
    return res;
}
*/

int compareKeys(keyType key1, keyType key2) {
    return !strcmp(key1, key2);
}


void setPayloadKey(struct Payload *payload, keyType key) {
    strcpy(payload -> key, key);
}


void setPayloadValue(struct Payload *payload, valueType value) {
    payload -> value = value;
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
    res -> data = data;
    res -> next = NULL;
    return res;
}


void addNode(struct LinkedList* list, struct Payload data) {
    struct Node* node = getNode(data);
    if (list -> head == NULL) {
        list -> head = node;
    } else {
        node -> next = list -> head;
        list -> head = node;
    }
    list -> size++;
}


struct Node* findNode(struct LinkedList* list, keyType key) {
    struct Node* curr = list -> head;
    while(curr != NULL) {
        if (compareKeys(key, curr -> data.key)) {
            break;
        }
        curr = curr -> next;
    }
    return curr;
}

void printList(struct LinkedList* list) {
    struct Node* curr = list -> head;
    while(curr != NULL) {
        printPayload(curr -> data);
        curr = curr -> next;
    }
}


void clearList(struct LinkedList* list) {
    struct Node* curr = list -> head;
    while(curr != NULL) {
        struct Node* savedNext = curr -> next;
        free(curr);
        curr = savedNext;
    }
    list -> size = 0;
    list -> head = NULL;
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
    for (size_t i = 0; i < table -> size; i++) {
        clearList(&table -> buckets[i]);
    }
    free(table -> buckets);
    table -> buckets = NULL;
    table -> size = 0;
}


size_t getBucket(struct HashTable *table, keyType key) {
    return getHash(key) % table -> size;
}


void setValue(struct HashTable *table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct LinkedList *list = &table -> buckets[bucket];
    struct Node *node = findNode(list, key);
    if (node) {
        node -> data.value = value;
    } else {
        struct Payload payload = {};
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        addNode(list, payload);
    }
}


valueType getValue(struct HashTable *table, keyType key, valueType defValue) {
    size_t bucket = getBucket(table, key);
    struct LinkedList *list = &table -> buckets[bucket];
    struct Node *node = findNode(list, key);
    return node ? node -> data.value : defValue;
}


void printHashTable(struct HashTable *table) {
    int hasData = false;
    for (size_t i = 0; i < table -> size; i++) {
        struct LinkedList *bucket = &table -> buckets[i];
        if (bucket -> size != 0) {
            printList(bucket);
            hasData = true;
        }
    }
    if (!hasData) {
        printf("The hash table is empty\n");
    }
}


int not_null_lists(struct HashTable *table) {
    int n = 0;
    for(size_t i = 0; i < table -> size; i++) {
        struct LinkedList *bucket = &table -> buckets[i];
        if (bucket -> size != 0) {
            n++;
        }
    }
    return n;
}


double list_len(struct HashTable *table) {
    size_t n = 0;
    size_t len = 0;
    for(size_t i = 0; i < table -> size; i++) {
        struct LinkedList *bucket = &table -> buckets[i];
        if (bucket -> size != 0) {
            len += bucket -> size;
            n++;
        }
    }
    double l_len = (double)len / (double)n;
    return l_len;
}


size_t min_len(struct HashTable *table) {
    size_t min_len = 100000;
    for(size_t i = 0; i < table -> size; i++) {
        struct LinkedList *bucket = &table -> buckets[i];
        if (bucket -> size != 0) {
            if (bucket -> size < min_len) {
                min_len = bucket -> size;
            }
        }
    }
    return min_len;
}


size_t max_len(struct HashTable *table) {
    size_t max_len = 1;
    for(size_t i = 0; i < table -> size; i++) {
        struct LinkedList *bucket = &table -> buckets[i];
        if (bucket -> size != 0) {
            if (bucket -> size > max_len) {
                max_len = bucket -> size;
            }
        }
    }
    return max_len;
}


void normal_words(char *word, char *normal_word) {
    keyType not_normal = ".,!():;?/";
    int g = 0;
    int i = 0;

    while(word[i] != '\0') {
        int flag = 0;
        int a = 0;
        while(not_normal[a] != '\0') {
            if (word[i] == not_normal[a]) {
                flag += 1;
            }
            a++;
        }
        if (flag == 0)
        {
            normal_word[g] = word[i];
            g++;
        }
        i++;
    }
    normal_word[g] = '\0';
}


int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH + 1];
    char normal_word[MAX_WORD_LENGTH + 2];
    for(int i = 1; i <= 100000; i *= 10) {
        printf("For table size = %d\n", i);
        file = fopen("My.txt", "r");
        if (file == NULL) {
            printf("The file didn't open.\n");
            exit(1);
        }
        struct HashTable table = createHashTable(i);
        clock_t start = clock();
        while(fscanf(file, "%s", word) != EOF) {
            normal_words(word, normal_word);
            int x;
            x = getValue(&table, normal_word, 0);
            setValue(&table, normal_word, x + 1);
        }
        fclose(file);
        
        //printHashTable(&table);

        clock_t finish = clock();
        double time_elapsed = ((double)(finish - start)) / CLOCKS_PER_SEC;

        printf("Not null lists: %d\n", not_null_lists(&table));
        printf("Average list length: %lf\n", list_len(&table));
        printf("Min list length: %zu\n", min_len(&table));
        printf("Max list length: %zu\n", max_len(&table));
        printf("Time: %lf\n\n", time_elapsed);

        clearHashTable(&table);
    }
    return 0;
}
