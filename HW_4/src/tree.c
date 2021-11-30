#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>

#include "../include/payload.h"
#include "../include/binary_tree.h"
#include "../include/utils.h"


void count_words_tree(FILE *file, struct Binary_Tree *tree) {
    keyType buffer;
    keyType_ format_string[8];
    swprintf(format_string, 8, L" %%%dS", MAX_WORD_LENGTH);

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

    FILE *f_in, *f_out;
    if (open_files(&f_in, argv[1], &f_out, argv[2])) {
        exit(1);
    }

    struct Binary_Tree *tree = tree_create(L"о", 0);

    clock_t start = clock();
    count_words_tree(f_in, tree);
    clock_t stop = clock();
    printf("\n%.3f %zu %zu %.3f\n", (double) (stop - start) / CLOCKS_PER_SEC, tree_min_depth(tree), tree_max_depth(tree), tree_mean_depth(tree));

    tree_to_file(tree, f_out);

    tree_destroy(tree);

    fclose(f_in);
    fclose(f_out);
}

