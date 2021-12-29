#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//===================== specific part =========================

#define MAX_WORD_LENGTH 50


typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
    keyType key;
    valueType value;
};


void printPayload(struct Payload data) {
    printf("key = %s, value = %d\n", data.key, data.value);
}


int compareKeys(keyType key1, keyType key2) {
    return strcmp(key1, key2);
}

void setPayloadKey(struct Payload *payload, keyType key) {
    strcpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value) {
    payload->value = value;
}


struct Node {
    struct Payload data;
    struct Node *right;
    struct Node *left;
};

void setValue(struct Node *node, valueType value) {
    node->data.value = value + 1;
}
//===================== common part =========================\


struct BinaryTree
{
    struct Node *head;
};


struct Node* getNode(struct Payload data) {
    struct Node *res = malloc(sizeof(struct Node));
    if (res == NULL) {
        perror("Not enough memory");
        exit(1);
    }
    res->data = data; //(*res).data
    res->left = NULL;
    res->right = NULL;
    return res;
}

valueType getValue(struct Node *node, keyType key, valueType defValue) {
    int result = compareKeys(key, node->data.key);
    if (result > 0) {
        if (node->right == NULL) {
            return defValue;
        } else {
            return getValue(node->right, key, defValue);
        }
    }
    else if (result < 0) {
        if (node->left == NULL) {
            return defValue;
        } else {
            return getValue(node->left, key, defValue);
        }
    }
    else {
        return node->data.value;
    }
}


void addFromNode(struct Node *node, struct Payload data)
{
    int result = compareKeys(data.key, node->data.key);
    if (result > 0)
    {
        if (node->right == NULL)
        {
            node->right = getNode(data);
        }
        else
        {
            addFromNode(node->right, data);
        }
    }
    if (result < 0)
    {
        if (node->left == NULL)
        {
            node->left = getNode(data);
        }
        else
        {
            addFromNode(node->left, data);
        }
    }
    if (result == 0)
    {
        int x = getValue(node, data.key, data.value); //data.value = 0; - äåôîëòíîå çíà÷åíèå
        setValue(node, x);
    }

}

void addFromHead(struct BinaryTree *tree, struct Payload data) {
    if (tree->head == NULL) {
        tree->head = getNode(data);
    }
    else {
        addFromNode(tree->head, data);
    }
}

struct BinaryTree *createBinaryTree() {
    struct BinaryTree *tree = malloc(sizeof(struct BinaryTree));
    if (tree == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    tree->head = NULL;
    return tree;
}

void printTree(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printPayload(node->data);
    printTree(node->right);
}

void clearTree(struct Node *node) {
    if (node == NULL) {
        return;
    }
    clearTree(node->left);
    clearTree(node->right);
    free(node);
}



void heightTree(struct Node *node, int *height, int curr_height) {
    if (curr_height >= *height) {
        *height = curr_height;
    }
    if (!node) {
        return;
    }
    heightTree(node->left, height, curr_height + 1);
    heightTree(node->right, height, curr_height + 1);
}

void correctWord(char *word, char *correct_word)
{
    int start = 0, end = 0, null = 0;
    char symbols[32] = "1234567890-[].,!?;{}:()\'\"";
    for (int i = 0; i < 2; i++)
    {
        if (start == i)
        {
            for (int j = 0; j < strlen(symbols); j++)
            {
                if (word[i] == symbols[j])
                {
                    start++;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (end == i)
        {
            for (int j = 0; j < strlen(symbols); j++)
            {
                if (word[strlen(word) - (i + 1)] == symbols[j])
                {
                    end++;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        if (start == i) {
            for (int j = 0; j < 7; j++) {
                if (end == j) {
                    for (int k = 0; k < strlen(word) - (i + j); k++) {
                        correct_word[k] = word[i + k];
                        null = k;
                    }
                    correct_word[null + 1] = '\0';
                }
            }
        }
    }
}



int main()
{
    FILE *file = fopen("book.txt", "r");
    char word[MAX_WORD_LENGTH], correct_word[MAX_WORD_LENGTH];
    int *height_p;
    int height = 0;
    struct BinaryTree *tree = createBinaryTree();
    clock_t start = clock();

    if (!file)
    {
        printf("Did not open the file.");
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        struct Payload data;
        correctWord(word, correct_word);
        setPayloadValue(&data, 1);
        setPayloadKey(&data, correct_word);
        addFromHead(tree, data);
    }
    printTree(tree->head);
    fclose(file);

    height_p = &height;
    heightTree(tree->head, height_p, 0);
    printf("Height = %d\n", *height_p);

    clearTree(tree->head);
    free(tree);

    clock_t finish = clock();
    double time = ((double) (finish - start)) / CLOCKS_PER_SEC;
    printf("Work-time: %f sec.\n", time);
}