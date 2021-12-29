#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include <limits.h>
#include <locale.h>
#include <math.h>

//#define MAX_WORD_LENGTH 20

//typedef int valueType;
//typedef char keyType[MAX_WORD_LENGTH];


void getWords(FILE *text, struct HashTable* table){
    char word[20];
    char c;

    strcpy(word, "");
    while (!feof(text))
    {
        c = fgetc(text);
        if ( (('À' <= c) && ('ß' >= c)) || (('à' <= c) && ('ÿ' >= c)) )
        {
           char *str;
           str[0] = c;
           str[1] = '\0';

           strcat(word, str);
        }
        else
        {
            if ( strcmp(word, "") )
            {
                addWord(table, word);
            }

            strcpy(word, "");
        }
    }
}


int main()
{
    setlocale(LC_ALL, "");
    struct HashTable table = createHashTable(100000);

    FILE *text;
    text = fopen("text.txt", "r");

    getWords(text, &table);
    printf_statistic(&table);

    fclose(text);
    return 0;
}


