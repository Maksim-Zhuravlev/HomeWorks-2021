/*
Односвязный список -> Хеш-таблица
Реализовать набор функций для работы с односвязными списками
Применить далее для реализации хеш-таблицы, реализующей ассоциативный массив из строк в числа
Использовать хеш-таблицу из предыдущего шага для сбора статистики о количестве слов в каком-либо классическом
    русскоязычном тексте (не менее 400 kib в формате plain text), находящемся в публичном достоянии.
Собрать статистику о работе хеш-таблицы при использовании разного количества корзин (1, 10, 100, 1k, 10k, 100k) и разных
    хеш-функций (константа, сумма кодов символов, что-то получше на ваш выбор): количество ненулевых цепочек, средняя
    длина цепочки, минимальная длина непустой цепочки, максимальная длина непустой цепочки
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>

#include "hash_table.h"
#include "hash_functions.h"

void to_lowercase(char *string){
    for (char *p = string; *p; ++p) {
        *p = tolower(*p);
    }
//    int i = 0;
//    while (string[i]){
//        string[i] = tolower(string[i]);
//        ++i;
//    }
}

void process_file(FILE *file, struct HashTable *hash_table) {
    char buffer[MAX_WORD_LENGTH];
    char format_string[16];
    sprintf(format_string, " %ds", MAX_WORD_LENGTH);    // TODO -----------------------------------------------
//    printf("$ %d\n", fwscanf(file, L" %ls", buffer) > 0);
    while (fscanf(file, " %32s", buffer) == 1) {
        int new_value = getValue(hash_table, buffer, 0) + 1;
        setValue(hash_table, buffer, new_value);
    }
    printHashTable(hash_table);
}


void get_hash_table_statistic(){
}


int main(int argc, char *argv[]) {
//    setlocale(LC_ALL, "Russian");

    if (argc != 3) {
        printf("usage: a.out <hash table size> <hash_function> <file>");
        return 1;
    }

    char path[256] = "/home/sadaell/Documents/SE/HW_4/";    // REMOVE --------------------------------------------------
    strcat(path, argv[2]);;
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Cannot open the file\n");
        return 1;
    }

    int ht_size = atol(argv[1]);
    if (ht_size < 1) {
        printf("Invalid hash table size\n");
        return 1;
    }
    struct HashTable hash_table = createHashTable(ht_size, hash_functions[DJB2]);


    process_file(file, &hash_table);

}


