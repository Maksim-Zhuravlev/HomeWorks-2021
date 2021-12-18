#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"

void correctWord(char *phrase, char *word)
{
    int end = 0;
    int start = 0;
    char signs[20] = ".,!?;:-()\'\"";

    for (int i = 0; i < strlen(signs); i++)
    {
        if (phrase[0] == signs[i])
        {
            start = 1;
        }
    }

    for (int i = 0; i < 3; i++)
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
            for (int i = 0; i < 4; i++)
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

void main()
{
    FILE *fileForRead = fopen("book.txt", "r");
    FILE *fileForStatistic = fopen("statistic.txt", "a");

    if (fileForRead == NULL || fileForStatistic == NULL)
    {
        printf("Did not open the file.");
        exit(1);
    }

    char phrase[MAX_WORD_LENGTH + 1];
    char word[MAX_WORD_LENGTH + 2];
    struct Node *tree = createBinaryTree();

    while (fscanf(fileForRead, "%s", phrase) != EOF)
    {
        correctWord(phrase, word);
        setValue(tree, word, getValue(tree, word, 0) + 1);
    }

    int height = binaryTreeHeight(tree);

    fprintf(fileForStatistic, "Binary tree's height: %d.\n", height);

    clearTree(tree);

    fclose(fileForRead);
    fclose(fileForStatistic);
}