#include "binarySearchTree.h"

#define MAX_PHRASE_LENGTH 620

int main()
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

  struct BinarySearchTree *tree = createTree();

  while (fscanf(inputTextFile, "%s", phrase) != EOF)
  {
    char *word = strtok(phrase, delimiters);

    while (word != NULL)
    {
      struct Payload data;
      setPayloadKey(&data, word);
      setPayloadValue(&data, 1);

      insertNode(tree, data);

      word = strtok(NULL, delimiters);
    }
  }

  int height = getTreeHeight(tree->root);

  fprintf(statisticsFile, "BST height: %i", height);

  clearTree(tree->root);

  fclose(inputTextFile);

  return 0;
}