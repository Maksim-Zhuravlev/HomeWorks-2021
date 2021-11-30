#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/payload.h"
#include "../include/linked_list.h"
#include "../include/hash_table.h"
#include "../include/hash_functions.h"
#include "../include/utils.h"


size_t getHash(struct HashTable *hash_table, keyType key) {
    return hash_table->hash_function(key);
}


struct HashTable createHashTable(size_t size, size_t (*function_ptr)(const keyType)) {
    struct Linked_List *buckets = malloc(sizeof(struct Linked_List) * size);
    if (buckets == NULL) {
        perror("Cannot allocate memory for HashTable");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        buckets[i] = createLinkedList();
    }

    struct HashTable table = {.size = size, .buckets = buckets, .hash_function = function_ptr};
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
    return getHash(table, key) % table->size;
}


void setValue(struct HashTable *table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct Linked_List *list = &table->buckets[bucket];
    struct List_Node *node = findNode(list, key);
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
    struct Linked_List *list = &table->buckets[bucket];
    struct List_Node *node = findNode(list, key);
    return node ? node->data.value : defValue;
}


void printHashTable(struct HashTable *table) {
    _Bool hasData = false;
    for (size_t i = 0; i < table->size; i++) {
        struct Linked_List *bucket = &table->buckets[i];
        if (bucket->size != 0) {
            printList(bucket);
            hasData = true;
        }
    }
    if (!hasData) {
        printf("The hash table is empty\n");
    }
}


size_t hashtable_count_elements(struct HashTable *table) {
    size_t c = 0;
    for (int i = 0; i < table->size; ++i) {
        struct List_Node *current = table->buckets[i].head;
        while (current) {
            ++c;
            current = current->next;
        }
    }
    return c;
}


void hashtable_to_file(struct HashTable *table, FILE *file) {
    size_t size = hashtable_count_elements(table);
    struct Payload *data[size];
    int ind = 0;

    for (int i = 0; i < table->size; ++i) {
        struct List_Node *current = table->buckets[i].head;
        while (current) {
            data[ind] = &current->data;
            current = current->next;
            ++ind;
        }
    }

    qsort(data, size, sizeof(struct Payload *), compare_payloads);
    for (int i = 0; i < size; ++i) {
        if (data[i]->value > 0) {
//            wprintf(L"%S %d\n", data[i]->key, data[i]->value);
            fwprintf(file, L"%S %d\n", data[i]->key, data[i]->value);
        }
    }
}


void get_hashtable_statistic(struct HashTable *table) {
    size_t num_non_empty_buckets = 0;
    size_t min_in_bucket = -1;
    float mean_in_bucket = 0;
    size_t max_in_bucket = 0;
//    char most_popular_word[MAX_WORD_LENGTH] = {0};
//    int value = 0;

//    int max_str_len = 0;
//    char buf[MAX_WORD_LENGTH];

    for (int i = 0; i < table->size; ++i) {
        struct Linked_List *bucket = &table->buckets[i];
        mean_in_bucket += bucket->size;
        min_in_bucket = min(min_in_bucket, bucket->size ? bucket->size : min_in_bucket);
        max_in_bucket = max(max_in_bucket, bucket->size);

        struct List_Node *current = bucket->head;
        if (current) { ++num_non_empty_buckets; }
        while (current) {
//            if (current->data.value > value) {
//                strcpy(most_popular_word, current->data.key);
//                value = current->data.value;
//            }
//            if (strlen(current->data.key) > max_str_len){
//                max_str_len = strlen(current->data.key);
//                strcpy(buf, current->data.key);
//            }
            current = current->next;
        }
    }
//    printf(
//        "num_nodes %zu\nnum_elements %zu\nnum_non_empty_buckets %zu\nmin_in_bucket %zu\nmax_in_bucket %zu\nmean_in_bucket %.2f\nmost popular word '%s' %d\n",
//        num_nodes, num_elements, num_non_empty_buckets, min_in_bucket, max_in_bucket,
//        (mean_in_bucket / num_non_empty_buckets), most_popular_word, value
//    );
    printf(
        "%zu\n%zu\n%zu\n%.2f\n",
        num_non_empty_buckets, min_in_bucket, max_in_bucket,
        (mean_in_bucket / num_non_empty_buckets)
    );
//    printf("%s\n%d", buf, max_str_len);
}

