#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000

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

int compareKeys(char *key1, char *key2)
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

struct Payload getPayload(keyType key, valueType value)
{
    struct Payload tmp;
    setPayloadKey(&tmp, key);
    setPayloadValue(&tmp, value);
    return tmp;
}

struct Node
{
    struct Payload data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node *getFreeNode(struct Node *parent, struct Payload data)
{
    struct Node *tmp = malloc(sizeof(struct Node));
    if (tmp == NULL)
    {
        printf("Not enough memory.\n");
        exit(1);
    }
    tmp->left = NULL;
    tmp->right = NULL;
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
    struct Node *tmp = getNodeByKey(tree, key);
    if (tmp)
    {
        tmp->data.value = value;
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