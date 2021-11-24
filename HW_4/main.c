#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "wctype.h"
#include "unistd.h"
#include "time.h"

#include "payload.h"
#include "linked_list.h"
#include "hash_table.h"
#include "hash_functions.h"


// Make lowercase, remove punctuation
void preprocess_file(FILE *fin, FILE *fout) {
    wchar_t chr;
    while ((chr = fgetwc(fin)) != WEOF) {
        if (!iswpunct(chr)) {
            fputwc(towlower(chr), fout);
        }
    }
}


void process_file(FILE *file, struct HashTable *hash_table) {
    char buffer[MAX_WORD_LENGTH];
    wchar_t format_string[8];
    swprintf(format_string, 8, L" %%%ds", MAX_WORD_LENGTH);

    while (fwscanf(file, format_string, buffer) == 1) {
        int new_value = getValue(hash_table, buffer, 0) + 1;
        setValue(hash_table, buffer, new_value);
    }
//    printHashTable(hash_table);
}


size_t min(size_t a, size_t b) { return a <= b ? a : b; }

size_t max(size_t a, size_t b) { return a >= b ? a : b; }

void get_hash_table_statistic(struct HashTable *table) {
    size_t num_nodes = 0;
    size_t num_elements = 0;
    size_t num_non_empty_buckets = 0;
    size_t min_in_bucket = -1;
    size_t mean_in_bucket = 0;
    size_t max_in_bucket = 0;
    char most_popular_word[MAX_WORD_LENGTH] = {0};
    int value = 0;

    for (int i = 0; i < table->size; ++i) {
        struct LinkedList *bucket = &table->buckets[i];
        mean_in_bucket += bucket->size;
        min_in_bucket = min(min_in_bucket, bucket->size);
        max_in_bucket = max(max_in_bucket, bucket->size);

        struct Node *current = bucket->head;
        if (current) { num_non_empty_buckets++; }
        while (current) {
            num_nodes++;
            num_elements += current->data.value;
            if (current->data.value > value) {
                strcpy(most_popular_word, current->data.key);
                value = current->data.value;
            }
            current = current->next;
        }
    }
    printf(
        "num_nodes %zu\nnum_elements %zu\nnum_non_empty_buckets %zu\nmin_in_bucket %zu\nmax_in_bucket %zu\nmean_in_bucket %.2f\nmost popular word '%s' %d",
        num_nodes, num_elements, num_non_empty_buckets, min_in_bucket, max_in_bucket,
        ((float) mean_in_bucket / num_non_empty_buckets), most_popular_word, value);
}


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    if (argc != 4) {
        printf("usage: a.out <tree?> <hash table size> <hash_function> <file>\n"
               "Hash functions:\n1 - constant\t2 - first_char\t3 - char_sum\n4 - word_length\t5 - djb2\t\t6 - sdbm\n"
        );
        return 1;
    }

    char path[256];
    char proc_path[256];
    strcpy(path, argv[3]);
    strcpy(proc_path, path);
    strcpy(proc_path, "_proc");

    FILE *f_out;
    if (access(proc_path, F_OK) != 0) {
        FILE *f_in = fopen(path, "r, ccs=UTF-8");
        if (!f_in) {
            printf("Failed to open input file\n");
            return 1;
        }

        strcat(path, "_proc");
        f_out = fopen(path, "w, ccs=UTF-8");
        if (!f_out) {
            printf("Failed to write processed file\n");
            return 1;
        }

        preprocess_file(f_in, f_out);
        fclose(f_in);
        fclose(f_out);

    } else {
        // Comment out to use unprocessed file
        strcat(path, "_proc");
    }

    f_out = fopen(path, "r, ccs=UTF-8");
    if (!f_out) {
        printf("Failed to open processed file\n");
        return 1;
    }

    int ht_size = atol(argv[1]);
    int h_func = atol(argv[2]);
    if (ht_size < 1) {
        printf("Invalid hash table size\n");
        return 1;
    } else if (h_func < 0 || h_func > 5) {
        printf("Invalid hash function\n");
        return 1;
    }
    struct HashTable hash_table = createHashTable(ht_size, Hash_Functions[h_func]);

    clock_t start = clock();
    process_file(f_out, &hash_table);
    clock_t stop = clock();
    printf("\n%.3f seconds\n", (double)(stop - start) / CLOCKS_PER_SEC);

    get_hash_table_statistic(&hash_table);
}


