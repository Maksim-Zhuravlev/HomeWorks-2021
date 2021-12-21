#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"

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

void main()
{
    FILE *fileForRead = fopen("book.txt", "r");
    FILE *fileForStatistic = fopen("statistic.txt", "a");
    int height;
    char phrase[MAX_WORD_LENGTH + 1];
    char word[MAX_WORD_LENGTH + 2];
    struct Node *tree = createBinaryTree();
    struct Payload commonWord = {.value = 0, .key = ""};

    if (fileForRead == NULL || fileForStatistic == NULL)
    {
        printf("Did not open the file.");
        exit(1);
    }

    while (fscanf(fileForRead, "%s", phrase) != EOF)
    {
        correctWord(phrase, word);
        setValue(tree, word, getValue(tree, word, 0) + 1);
    }
    frequentWord(tree, &commonWord);
    height = binaryTreeHeight(tree);

    fprintf(fileForStatistic, "Binary tree's height: %d.\n", height);
    fprintf(fileForStatistic, "This word occurs %d times in the text: %s.\n", commonWord.value, commonWord.key);

    clearTree(tree);

    fclose(fileForRead);
    fclose(fileForStatistic);
}