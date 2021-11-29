#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>

#include "../include/payload.h"
#include "../include/linked_list.h"
#include "../include/hash_table.h"
#include "../include/hash_functions.h"


void count_words_hash(FILE *file, struct HashTable *hash_table) {
    keyType_ buffer[MAX_WORD_LENGTH];
    keyType_ format_string[8];
    swprintf(format_string, 8, L" %%%ds", MAX_WORD_LENGTH);

    while (fwscanf(file, format_string, buffer) == 1) {
        int new_value = getValue(hash_table, buffer, 0) + 1;
//        wprintf(L"%s %d\n", buffer, new_value);
        setValue(hash_table, buffer, new_value);
    }
//    printHashTable(hash_table);
}


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    if (argc != 5) {
        printf("usage: hash <hash table size> <hash_function> <input file> <output file>\n"
               "Hash functions:\n1 - constant\t2 - first_char\t3 - char_sum\t4 - word_length\t5 - djb2\n"
        );
        return 1;
    }

    FILE *f_in = fopen(argv[3], "r, ccs=UTF-8");
    if (!f_in) {
        printf("Failed to open input file\n");
        return 1;
    }
    FILE *f_out = fopen(argv[4], "w, ccs=UTF-8");
    if (!f_out) {
        printf("Failed to open output file\n");
        return 1;
    }

    int ht_size = atol(argv[1]);
    int h_func = atol(argv[2]);
    if (ht_size < 1) {
        printf("Invalid hash table size\n");
        return 1;
    } else if (h_func < 0 || h_func > 4) {
        printf("Invalid hash function\n");
        return 1;
    }

    struct HashTable hash_table = createHashTable(ht_size, Hash_Functions[h_func]);

    clock_t start = clock();
    count_words_hash(f_in, &hash_table);
    clock_t end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);

    get_hashtable_statistic(&hash_table);

    hashtable_to_file(&hash_table, f_out);

    clearHashTable(&hash_table);
}


