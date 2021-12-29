/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

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

int compareKeys(char key1, char key2)
{
    return strcmp(key1, key2);
}

void setPayloadKey(struct Payload *payload, keyType key)
{
    strcpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value)
{
    payload->value = value;
}
//===================== common part =========================

struct Node
{
    struct Payload data;
    struct Node *left;
    struct Node *right;
    struct Node *root;
};

struct Payload getPayload(keyType key, valueType value)
{
    struct Payload tmp;
    setPayloadKey(&tmp, key);
    setPayloadValue(&tmp, value);
    return tmp;
}

struct Node *getFreeNode(struct Node *parent, struct Payload data)
{
    struct Node *res = malloc(sizeof(struct Node));
    if (res == NULL)
    {
        printf("Not enough memory.\n");
        exit(1);
    }
    res->left = NULL;
    res->right = NULL;
    setPayloadKey(&tmp->data, data.key);
    setPayloadValue(&tmp->data, data.value);
    tmp->parent = parent;
    return tmp;
}

void insertNode(struct Node *root, struct Payload data)
{
    struct Node *curr = root;
    struct Node *prev = NULL;
    int cmpKey;

    while (curr)
    {
        cmpKey = compareKeys(data.key, curr->data.key);
        if (cmpKey > 0)
        {
            prev = curr;
            curr = curr->right;
        }
        else if (cmpKey < 0)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            curr->data = data;
            return;
        }
    }
    if (cmpKey > 0)
    {
        prev->right = getFreeNode(prev, data);
    }
    else
    {
        prev->left = getFreeNode(prev, data);
    }
}

struct Node *getNodeByKey(struct Node *node, keyType key)
{
    struct Node *curr = node;
    int cmpKey;
    while (curr)
    {
        if (curr == node && node->data.key[0] == '\0')
        {
            setPayloadKey(&node->data, key);
            return node;
        }
        cmpKey = compareKeys(key, curr->data.key);
        if (cmpKey > 0)
        {
            curr = curr->right;
        }
        else if (cmpKey < 0)
        {
            curr = curr->left;
        }
        else
        {
            return curr;
        }
    }
    return NULL;
}

void setValue(struct Node *tree, keyType key, valueType value)
{
    struct Node *res = getNodeByKey(tree, key);
    if (res)
    {
        res->data.value = value;
    }
    else
    {
        insertNode(tree, getPayload(key, value));
    }
}

valueType getValue(struct Node *tree, keyType key, valueType defVal)
{
    struct Node *tmp = getNodeByKey(tree, key);
    if (tmp)
    {
        return tmp->data.value;
    }
    else
    {
        return defVal;
    }
}

struct Node *getMaxNode(struct Node *node)
{
    while (node->right)
    {
        node = node->right;
    }
    return node;
}

void removeNode(struct Node *node)
{
    if (node->left && node->right)
    {
        struct Node *localMax = getMaxNode(node->left);
        node->data = localMax->data;
        removeNode(localMax);
        return;
    }
    else if (node->left)
    {
        if (node == node->parent->left)
        {
            node->parent->left = node->left;
        }
        else
        {
            node->parent->right = node->left;
        }
    }
    else if (node->right)
    {
        if (node == node->parent->right)
        {
            node->parent->right = node->right;
        }
        else
        {
            node->parent->left = node->right;
        }
    }
    else
    {
        if (node == node->parent->left)
        {
            node->parent->left = NULL;
        }
        else
        {
            node->parent->right = NULL;
        }
    }
    free(node);
}

void deleteValue(struct Node *root, keyType key)
{
    struct Node *node = getNodeByKey(root, key);
    removeNode(node);
}

struct Node *createBinaryTree()
{
    struct Node *tree = malloc(sizeof(struct Node));
    if (tree == NULL)
    {
        printf("Not enough memory.\n");
        exit(1);
    }
    tree->parent = NULL;
    tree->data.key[0] = '\0';
    tree->data.value = 0;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void clearTree(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    clearTree(node->right);
    clearTree(node->left);
    free(node);
}

void printTree(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printTree(node->right);
    printPayload(node->data);
    printTree(node->left);
}

int binaryTreeHeight(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = binaryTreeHeight(node->left);
        int rightHeight = binaryTreeHeight(node->right);
        int fullHeight = 0;
        if (leftHeight > rightHeight)
        {
            fullHeight = leftHeight + 1;
        }
        else
        {
            fullHeight = rightHeight + 1;
        }
        return fullHeight;
    }
}

void frequentWord(struct Node *node, struct Payload *data)
{
    if (node == NULL)
    {
        return;
    }
    if (data->value < node->data.value)
    {
        setPayloadValue(data, node->data.value);
        setPayloadKey(data, node->data.key);
    }
    frequentWord(node->right, data);
    frequentWord(node->left, data);
}



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
    FILE *fileForRead = fopen("C:\\Users\\lgolo\\Desktop\\Andreev Roman\\Hash_Table\\book.txt", "r");
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
}*/

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
    FILE *file = fopen("C:\\Users\\lgolo\\Desktop\\Andreev Roman\\Hash_Table\\book.txt", "r");
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