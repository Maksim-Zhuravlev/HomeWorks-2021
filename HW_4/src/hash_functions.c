#include <string.h>

#include "../include/hash_functions.h"


size_t hf_constant(const keyType key) {
    return 42;
}

size_t hf_first_char(const keyType key) {
    return key[0];
}

size_t hf_char_sum(const keyType key) {
    size_t ret = 0;
    // Русские символы в UTF-8 занимают по 2 байта
    // В GNU/Linux тип wchar_t имеет размер 32 бита. © вики
    // поэтому есть шанс перепрыгнуть через \0
    // можно, конечно, в UTF-32 файл перекодировать, но у меня она в консоли не отображается
    char *key_ = (char *) key;
    for (int i = 0; i < sizeof(keyType) * (sizeof(keyType) / sizeof(char)); ++i) {
        if (key_[i] == '\0') {
            break;
        }
        ret += key_[i];
    }
//    for (int i = 0; i < sizeof(keyType); ++i) {
//        if (key[i] == '\0') {
//            break;
//        }
//        ret += key[i];
//    }
//    Вывод wprintf из 21 строки hash.c на ./texts/utf.txt
//    текст 1
//    текст 2
//    текст 3
//    ааааааА 1
//    текст 1
//    ааааааЯ 1
//    текст 1
//    текст 2
//    ааааааА 2
//    текст 2
//    аааааа 1
//    текст 4

    return ret;
}

size_t hf_word_length(const keyType key) {
    return strlen(key);
}

//http://www.cse.yorku.ca/~oz/hash.html
size_t hf_djb2(const keyType key) {
    unsigned long hash = 5381;
    char c;
    char *key_ = (char *) key;
    while (c = *key_++) {
        hash = ((hash << 5) + hash) + c;
    } /* hash * 33 + c */

    return hash;
}


HFunc Hash_Functions[] = {&hf_constant, &hf_first_char, &hf_char_sum, &hf_word_length, &hf_djb2};
