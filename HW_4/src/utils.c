#include <string.h>
#include <stdio.h>


size_t min(size_t a, size_t b) { return a <= b ? a : b; }

size_t max(size_t a, size_t b) { return a >= b ? a : b; }

int open_files(FILE **f_in, char *path_in, FILE **f_out, char *path_out) {
    *f_in = fopen(path_in, "r, ccs=UTF-8");
    if (!*f_in) {
        printf("Failed to open input file\n");
        goto err1;
    }
    *f_out = fopen(path_out, "w, ccs=UTF-8");
    if (!*f_in) {
        printf("Failed to open output file\n");
        goto err2;
    }
    return 0;

    err2:
    fclose(*f_out);
    *f_out = NULL;

    err1:
    fclose(*f_in);
    *f_in = NULL;

    return 1;
}
