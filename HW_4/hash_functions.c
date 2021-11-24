#include <string.h>

#include "hash_functions.h"


size_t hf_constant(const keyType key){
    return 42;
}

size_t hf_first_char(const keyType key) {
    return key[0];
}

size_t hf_char_sum(const keyType key) {
    size_t ret = 0;
    for (int i = 0; i < sizeof(keyType); ++i) {
        if (key[i] != '\0') {
            ret += key[i];
        }
    }
    return ret;
}

size_t hf_word_length(const keyType key) {
    return strlen(key);
}

//http://www.cse.yorku.ca/~oz/hash.html
size_t hf_djb2(const keyType key) {
    unsigned long hash = 5381;
    int c;

    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    } /* hash * 33 + c */

    return hash;
}

//http://www.cse.yorku.ca/~oz/hash.html
size_t hf_sdbm(const keyType key){
    unsigned long hash = 0;
    int c;

    while (c = *key++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}


HFunc Hash_Functions[] = {&hf_constant, &hf_first_char, &hf_char_sum, &hf_word_length, &hf_djb2, &hf_sdbm};
