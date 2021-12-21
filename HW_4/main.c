#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "hash_table.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void correctWord(char *phrase, char *word)
{
    int end = 0;
    int start = 0;
    char signs[32] = "1234567890-…[]«».,!?;:()\'\"";

    for (int i = 0; i < 2; i++)
    {
        if (start == i)
        {
            for (int j = 0; j < strlen(signs); j++)
            {
                if (phrase[i] == signs[j])
                {
                    start = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (end == i)
        {
            for (int j = 0; j < strlen(signs); j++)
            {
                if (phrase[strlen(phrase) - (i + 1)] == signs[j])
                {
                    end = i + 1;
                }
            }
        }
    }

    for (int k = 0; k < 2; k++)
    {
        if (start == k)
        {
            for (int i = 0; i < 7; i++)
            {
                if (end == i)
                {
                    int j;
                    for (j = 0; j < strlen(phrase) - (i + k); j++)
                    {
                        word[j] = phrase[j + k];
                    }
                    word[j] = '\0';
                }
            }
        }
    }
}

void statistics(struct HashTable table)
{
    int maxLen = 0;
    int minLen = INT_MAX;
    int nonZeroChains = 0;
    int sumOfLen = 0;

    for (size_t i = 0; i < table.size; ++i)
    {
        if ((table.buckets[i]).size)
        {
            maxLen = MAX((table.buckets[i]).size, maxLen);
            minLen = MIN((table.buckets[i]).size, minLen);
            ++nonZeroChains;
            sumOfLen += (table.buckets[i]).size;
        }
    }

    printf("Number of non-zero chains: %d\n", nonZeroChains);
    printf("Average chain length: %d\n", sumOfLen / nonZeroChains);
    printf("Min length of non-empty chain: %d\n", minLen);
    printf("Max length of non-empty chain: %d\n", maxLen);
    printf("---------------------------------------\n");
}

int main()
{
    for (int i = 1; i < 100000 + 1; i *= 10)
    {
        FILE *fileForStatistic = fopen("statistics.txt", "a");
        FILE *fileForRead = fopen("book.txt", "r");
        char phrase[MAX_WORD_LENGTH];
        char word[MAX_WORD_LENGTH];
        struct HashTable table;
        struct Payload commonWord = {.value = 0, .key = ""};

        if (fileForRead == NULL)
        {
            printf("Did not open files.");
            exit(1);
        }

        table = createHashTable(i);

        while (fscanf(fileForRead, "%s", phrase) != EOF)
        {
            correctWord(phrase, word);
            setValue(&table, word, getValue(&table, word, 0) + 1);
        }

        if (i == 1)
        {
            frequentWord(&table, &commonWord);
            fprintf(fileForStatistic, "This word occurs %d times in the text: %s.\n", commonWord.value, commonWord.key);
        }

        printf("Size of hash-table: %d\n", i);
        statistics(table);

        clearHashTable(&table);

        fclose(fileForRead);
    }

    return 0;
}