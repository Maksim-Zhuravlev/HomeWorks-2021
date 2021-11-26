#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>

#include "include/payload.h"
#include "include/linked_list.h"
#include "include/hash_table.h"
#include "include/hash_functions.h"
#include "include/binary_tree.h"
#include "include/utils.h"


void count_words_hash(FILE *file, struct HashTable *hash_table) {
    char buffer[MAX_WORD_LENGTH];
    wchar_t format_string[8];
    swprintf(format_string, 8, L" %%%ds", MAX_WORD_LENGTH);

    while (fwscanf(file, format_string, buffer) == 1) {
        int new_value = getValue(hash_table, buffer, 0) + 1;
        setValue(hash_table, buffer, new_value);
    }
//    printHashTable(hash_table);
}


void count_words_tree(FILE *file, struct Binary_Tree *tree) {
    char buffer[MAX_WORD_LENGTH];
    wchar_t format_string[8];
    swprintf(format_string, 8, L" %%%ds", MAX_WORD_LENGTH);

    while (fwscanf(file, format_string, buffer) == 1) {
        int new_value = tree_get_value(tree, buffer, 0) + 1;
        tree_set_value(tree, buffer, new_value);
    }
//    tree_print(tree, 0);
}


// TODO: results to file
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
//    if (argc != 4) {
//        printf("usage: a.out <tree?> <hash table size> <hash_function> <file>\n"
//               "Hash functions:\n1 - constant\t2 - first_char\t3 - char_sum\n4 - word_length\t5 - djb2\t\t6 - sdbm\n"
//        );
//        return 1;
//    }

    char path[256];
    char proc_path[256];
    strcpy(path, argv[3]);
//    strcpy(proc_path, path);
//    strcpy(proc_path, "_proc");

//    FILE *f_out;
    FILE *f_in = fopen(path, "r, ccs=UTF-8");
//    if (access(proc_path, F_OK) != 0) {
//        FILE *f_in = fopen(path, "r, ccs=UTF-8");
//        if (!f_in) {
//            printf("Failed to open input file\n");
//            return 1;
//        }
//
//        strcat(path, "_proc");
//        f_out = fopen(path, "w, ccs=UTF-8");
//        if (!f_out) {
//            printf("Failed to write processed file\n");
//            return 1;
//        }
//
//        preprocess_file(f_in, f_out);
//        fclose(f_in);
//        fclose(f_out);
//
//    } else {
//        strcat(path, "_proc");
//    }
//
//    f_out = fopen(path, "r, ccs=UTF-8");
//    if (!f_out) {
//        printf("Failed to open processed file\n");
//        return 1;
//    }

//    int ht_size = atol(argv[1]);
//    int h_func = atol(argv[2]);
//    if (ht_size < 1) {
//        printf("Invalid hash table size\n");
//        return 1;
//    } else if (h_func < 0 || h_func > 5) {
//        printf("Invalid hash function\n");
//        return 1;
//    }
//    struct HashTable hash_table = createHashTable(ht_size, Hash_Functions[h_func]);
//
//    clock_t start = clock();
////    count_words_hash(f_out, &hash_table);
//    count_words_hash(f_in, &hash_table);
//    clock_t stop = clock();
//    printf("\n%.3f seconds\n", (double) (stop - start) / CLOCKS_PER_SEC);
//
//    get_hash_table_statistic(&hash_table);
//
//    clearHashTable(&hash_table);

    struct Binary_Tree * tree = tree_create("и", 0);
    count_words_tree(f_in,tree);
//    test_tree();
}


