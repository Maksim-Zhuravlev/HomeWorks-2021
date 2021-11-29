#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>

#include "../include/payload.h"
#include "../include/binary_tree.h"


void count_words_tree(FILE *file, struct Binary_Tree *tree) {
    char buffer[MAX_WORD_LENGTH];
    wchar_t format_string[8];
    swprintf(format_string, 8, L" %%%ds", MAX_WORD_LENGTH);

    while (fwscanf(file, format_string, buffer) == 1) {
        int new_value = tree_get_value(tree, buffer, 0) + 1;
        tree_set_value(tree, buffer, new_value);
    }
}


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    if (argc != 3) {
        printf("usage: tree <input file> <output file>>\n");
        return 1;
    }

    FILE *f_in = fopen(argv[1], "r, ccs=UTF-8");
    if (!f_in) {
        printf("Failed to open input file\n");
        return 1;
    }
    FILE *f_out = fopen(argv[2], "w, ccs=UTF-8");
    if (!f_out) {
        printf("Failed to open output file\n");
        return 1;
    }

    struct Binary_Tree *tree = tree_create("о", 0);
    clock_t start = clock();
    count_words_tree(f_in, tree);
    clock_t stop = clock();
    printf("\n%.3f %zu %zu %.3f\n", (double) (stop - start) / CLOCKS_PER_SEC, tree_min_depth(tree), tree_max_depth(tree), tree_mean_depth(tree));

    tree_to_file(tree, f_out);

    tree_destroy(tree);
}

