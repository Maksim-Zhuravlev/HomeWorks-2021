#include <string.h>

#include "../include/hash_functions.h"


size_t hf_constant(const keyType key) {
    return 42;
}

size_t hf_first_char(const keyType key) {
    return key[0];
}

size_t hf_word_length(const keyType key) {
    return wcslen(key);
}

size_t hf_char_sum(const keyType key) {
    size_t ret = 0;

    int i = 0;
    while (key[i]) {
        ret += key[i++];
    }

    return ret;
}

//http://www.cse.yorku.ca/~oz/hash.html
size_t hf_djb2(const keyType key) {
    unsigned long hash = 5381;
    wchar_t c;

    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    } /* hash * 33 + c */

    return hash;
}


HFunc Hash_Functions[] = {&hf_constant, &hf_first_char, &hf_word_length, &hf_char_sum, &hf_djb2};
