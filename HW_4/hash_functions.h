#ifndef UNTITLED_HASH_FUNCTIONS_H
#define UNTITLED_HASH_FUNCTIONS_H

#include <stddef.h>
#include "payload.h"


typedef size_t (*Hash_Functions)(const keyType);

extern Hash_Functions hash_functions[];

enum Hash_Functions_List{
    THE_ANSWER,
    FIRST_CHAR,
    CHAR_SUM,
    WORD_LENGTH,
    DJB2,
    SDBM,
};


size_t hf_constant(const keyType key);

size_t hf_first_char(const keyType key);

size_t hf_char_sum(const keyType key);

size_t hf_word_length(const keyType key);

size_t hf_djb2(const keyType key);

size_t hf_sdbm(const keyType key);


#endif //UNTITLED_HASH_FUNCTIONS_H
