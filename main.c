#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <limits.h>
#include <locale.h>
#include <time.h>

void getWords(FILE *text, struct Tree* tree){
    char word[MAX_WORD_LENGTH];
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
                addWord(tree, word);
            }

            strcpy(word, "");
        }
    }
}


int main()
{
    setlocale(LC_ALL, "");
    struct Tree tree = createTree();

    FILE *text;
    text = fopen("text.txt", "r");

    if (text == NULL)
    {
		perror("Cannot open the file");
		exit(1);
	}

    clock_t start = clock();
    getWords(text, &tree);
    clock_t finish = clock();

    fclose(text);

    double time = ( (double)(finish - start)) / CLOCKS_PER_SEC;

    printf("tree height = %d, time = %f", getHeight(&tree), time);
    return 0;
}
