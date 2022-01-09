#include "hashtable.h"

// https://stackoverflow.com/questions/3437404/min-and-max-in-c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX_PHRASE_LENGTH 620

void collectStatistics(struct HashTable table, FILE *outputFile)
{
  int maxLength = 0;
  int minLength = INT_MAX;

  int nonZeroChains = 0;
  int sumOfLen = 0;

  for (size_t i = 0; i < table.size; i++)
  {
    if ((table.buckets[i]).size)
    {
      maxLength = MAX((table.buckets[i]).size, maxLength);
      minLength = MIN((table.buckets[i]).size, minLength);

      nonZeroChains++;
      sumOfLen += (table.buckets[i]).size;
    }
  }

  fprintf(outputFile, "Number of non-zero chains: %i\n", nonZeroChains);
  fprintf(outputFile, "Average chain length: %i\n", sumOfLen / nonZeroChains);
  fprintf(outputFile, "Minimun non-empty chain length: %i\n", minLength);
  fprintf(outputFile, "Maximum non-empty chain length: %i\n", maxLength);
  fprintf(outputFile, "----------------------------------\n");
}

int main()
{
  for (int i = 1; i <= 100000; i *= 10)
  {
    FILE *statisticsFile = fopen("statistics.txt", "a");
    FILE *inputTextFile = fopen("book.txt", "r");

    if (inputTextFile == NULL)
    {
      printf("Can't open input text file!\n");
      exit(1);
    }

    char phrase[MAX_PHRASE_LENGTH];

    const char *delimiters = " -_,.!?:;()'\"";

    struct HashTable table = createHashTable(i);

    while (fscanf(inputTextFile, "%s", phrase) != EOF)
    {
      char *word = strtok(phrase, delimiters);
      while (word != NULL)
      {
        setValue(&table, word, getValue(&table, word) + 1);

        word = strtok(NULL, delimiters);
      }
    }

    fprintf(statisticsFile, "Size of hash table: %i\n", i);

    collectStatistics(table, statisticsFile);

    clearHashTable(&table);

    fclose(inputTextFile);
  }

  return 0;
}