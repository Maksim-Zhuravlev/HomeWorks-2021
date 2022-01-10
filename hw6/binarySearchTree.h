#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAX_WORD_LENGTH 31

typedef char keyType[MAX_WORD_LENGTH + 1];
typedef int valueType;

struct Payload
{
  keyType key;
  valueType value;
};

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

// --------------------------------------------------------------

struct Node
{
  struct Payload data;
  struct Node *left;
  struct Node *right;
};

struct BinarySearchTree
{
  struct Node *root;
};

struct Node *findNode(struct BinarySearchTree *tree, keyType key)
{
  struct Node *current = tree->root;

  if (!current)
  {
    return NULL;
  }

  bool found = false;

  while (current && !found)
  {
    int result = compareKeys(key, current->data.key);

    if (result < 0)
    {
      current = current->left;
    }
    else if (result > 0)
    {
      current = current->right;
    }
    else
    {
      found = true;
    }
  }

  return current;
}

static struct Node *createNode(struct Payload data)
{
  struct Node *node = malloc(sizeof(struct Node));

  if (node == NULL)
  {
    printf("Can't allocate memory for a node!\n");
    exit(1);
  }

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct Node *insertNode(struct BinarySearchTree *tree, struct Payload data)
{
  struct Node *current = tree->root;
  struct Node *newNode = createNode(data);

  if (!current)
  {
    tree->root = newNode;
    return newNode;
  }

  while (true)
  {
    int result = compareKeys(current->data.key, newNode->data.key);

    if (result < 0)
    {
      if (current->left == NULL)
      {
        current->left = newNode;
        return newNode;
      }
      else
      {
        current = current->left;
      }
    }
    else if (result > 0)
    {
      if (current->right == NULL)
      {
        current->right = newNode;
        return newNode;
      }
      else
      {
        current = current->right;
      }
    }
    else
    {
      current->data.value = current->data.value + 1;
      return current;
    }
  }
}

struct BinarySearchTree *createTree()
{
  struct BinarySearchTree *tree = malloc(sizeof(struct BinarySearchTree));

  if (tree == NULL)
  {
    printf("Can't allocate memory for a BST!\n");
    exit(1);
  }

  tree->root = NULL;

  return tree;
}

void clearTree(struct Node *root)
{
  if (!root)
  {
    return;
  }

  clearTree(root->left);
  clearTree(root->right);

  free(root);
}

int getTreeHeight(struct Node *root)
{
  if (!root)
  {
    return 0;
  }

  int leftHeight = getTreeHeight(root->left);
  int rightHeight = getTreeHeight(root->right);

  return MAX(leftHeight, rightHeight) + 1;
}