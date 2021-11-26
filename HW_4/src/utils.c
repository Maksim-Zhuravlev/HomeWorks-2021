#include <stdio.h>
#include <string.h>

#include "../include/payload.h"
#include "../include/linked_list.h"
#include "../include/hash_table.h"


size_t min(size_t a, size_t b) { return a <= b ? a : b; }

size_t max(size_t a, size_t b) { return a >= b ? a : b; }

void get_hash_table_statistic(struct HashTable *table) {
    size_t num_nodes = 0;
    size_t num_elements = 0;
    size_t num_non_empty_buckets = 0;
    size_t min_in_bucket = -1;
    float mean_in_bucket = 0;
    size_t max_in_bucket = 0;
    char most_popular_word[MAX_WORD_LENGTH] = {0};
    int value = 0;

//    int max_str_len = 0;
//    char buf[MAX_WORD_LENGTH];

    for (int i = 0; i < table->size; ++i) {
        struct Linked_List *bucket = &table->buckets[i];
        mean_in_bucket += bucket->size;
        min_in_bucket = min(min_in_bucket, bucket->size);
        max_in_bucket = max(max_in_bucket, bucket->size);

        struct List_Node *current = bucket->head;
        if (current) { num_non_empty_buckets++; }
        while (current) {
            num_nodes++;
            num_elements += current->data.value;
            if (current->data.value > value) {
                strcpy(most_popular_word, current->data.key);
                value = current->data.value;
            }
//            if (strlen(current->data.key) > max_str_len){
//                max_str_len = strlen(current->data.key);
//                strcpy(buf, current->data.key);
//            }
            current = current->next;
        }
    }
    printf(
        "num_nodes %zu\nnum_elements %zu\nnum_non_empty_buckets %zu\nmin_in_bucket %zu\nmax_in_bucket %zu\nmean_in_bucket %.2f\nmost popular word '%s' %d\n",
        num_nodes, num_elements, num_non_empty_buckets, min_in_bucket, max_in_bucket,
        (mean_in_bucket / num_non_empty_buckets), most_popular_word, value
    );
//    printf("%s\n%d", buf, max_str_len);
}
