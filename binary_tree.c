#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include <time.h>

//===================== specific part =========================

#define MAX_WORD_LENGTH 100

int max = 0;
char maxWord[MAX_WORD_LENGTH];

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];

struct Payload
{
    keyType key;
    valueType value;
};

void printPayload(struct Payload data)
{
    printf("key = %s, value = %d\n", data.key, data.value);
}

int compareKeys(keyType key1, keyType key2)
{
    return strcmp(key1, key2);
}

void setPayloadKey(struct Payload* payload, keyType key)
{
    strcpy(payload->key, key);
}

void setPayloadValue(struct Payload* payload, valueType value)
{
    payload->value = value;
}

struct Node
{
    struct Payload data;
    struct Node* left;
    struct Node* right;
};

void setValue(struct Node* node, valueType value)
{
    node->data.value = value + 1;
    if (node->data.value > max)
    {
        max = node->data.value;
        strcpy(maxWord, node->data.key);
    }
}

//===================== common part =========================

struct binaryTree
{
    struct Node* head;
};

struct Node* getNode(struct Payload data)
{
    struct Node* res = malloc(sizeof(struct Node));
    res->data = data;
    res->left = NULL;
    res->right = NULL;
    return res;
}

valueType getValue(struct Node* node, keyType key, valueType defValue)
{
    int result = compareKeys(key, node->data.key);
    if (result > 0)
    {
        if (node->right == NULL)
        {
            return defValue;
        }
        else
        {
            return getValue(node->right, key, defValue);
        }
    }
    else if (result < 0)
    {
        if (node->left == NULL)
        {
            return defValue;
        }
        else
        {
            return getValue(node->left, key, defValue);
        }
    }
    else
    {
        return node->data.value;
    }
}

void addNode(struct Node* node, struct Payload data)
{
    int res = compareKeys(data.key, node->data.key);
    if (res > 0)
    {
        if (node->right == NULL)
        {
            node->right = getNode(data);
        }
        else
        {
            addNode(node->right, data);
        }
    }
    if (res < 0)
    {
        if (node->left == NULL)
        {
            node->left = getNode(data);
        }
        else
        {
            addNode(node->left, data);
        }
    }
    if (res == 0)
    {
        int x = getValue(node, data.key, data.value);
        setValue(node, x);
    }
}

void addHead(struct binaryTree* tree, struct Payload data)
{
    if (tree->head == NULL)
    {
        tree->head = getNode(data);
    }
    else
    {
        addNode(tree->head, data);
    }
}

struct binaryTree* createBinaryTree()
{
    struct binaryTree* tree = malloc(sizeof(struct binaryTree));
    tree->head = NULL;
    return tree;
}

void printBinaryTree(struct Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    printBinaryTree(node->left);
    printPayload(node->data);
    printBinaryTree(node->right);
}

void deleteNodes(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    deleteNodes(node->left);
    deleteNodes(node->right);
    free(node);
}

void treeHeight(struct Node* node, int* height, int currHeight)
{
    if (currHeight >= *height) {
        *height = currHeight;
    }
    if (node == NULL) {
        return;
    }
    treeHeight(node->left, height, currHeight + 1);
    treeHeight(node->right, height, currHeight + 1);
}

void normalWords(char* word, char* normalWord)
{
    keyType notNormal = ".,!():;?/";
    int i = 0, j, flag, k = 0;
    while (word[i] != '\0')
    {
        flag = 1;
        j = 0;
        while (notNormal[j] != '\0' && flag != 0)
        {
            if (word[i] == notNormal[j] || word[i] == '\"')
            {
                flag = 0;
            }
            j++;
        }
        if (flag != 0)
        {
            normalWord[k] = word[i];
            k++;
        }
        i++;
    }
    normalWord[k] = '\0';
}

void main() {
    setlocale(LC_ALL, "Rus");
    struct binaryTree* tree = createBinaryTree();
    int* heightPointer;
    int height = 0;
    heightPointer = &height;
    FILE* file;
    char word[MAX_WORD_LENGTH], normalWord[MAX_WORD_LENGTH];
    file = fopen("AnnaKarenina.txt", "rt");
    if (file == NULL)
    {
        perror("Failed to open file AnnaKarenina.");
        exit(1);
    }
    const clock_t start = clock();
    while (!feof(file)) {
        fscanf(file, "%s", word);
        normalWords(word, normalWord);
        struct Payload data;
        setPayloadValue(&data, 1);
        setPayloadKey(&data, normalWord);
        addHead(tree, data);
    }
    clock_t finish = clock();
    double time = (double)(finish - start) / CLOCKS_PER_SEC;
    treeHeight(tree->head, heightPointer, 0);
    printf("Height of tree: %d\n", *heightPointer);
    printf("The word %s occurs %d times.\n", maxWord, max);
    fclose(file);
    file = NULL;
    deleteNodes(tree->head);
    free(tree);
    printf("Time taken: %1f.\n", time);
}