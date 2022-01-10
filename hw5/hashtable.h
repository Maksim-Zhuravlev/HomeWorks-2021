#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_WORD_LENGTH 31

typedef char keyType[MAX_WORD_LENGTH + 1];
typedef int valueType;

struct Payload
{
  keyType key;
  valueType value;
};

size_t getHash(keyType key)
{
  // // Constant
  // return 666;

  // // Sum of character codes
  // int hash = 0;
  // for (int i = 0; key[i]; i++)
  // {
  //   hash += key[i];
  // }
  // return hash;

  int hash = 1;
  for (int i = 0; key[i]; i++)
  {
    hash += key[i] * hash;
    hash += hash >> 13;
  }
  return hash;
}

void printPayload(struct Payload data)
{
  printf("key = %s, value = %i\n", data.key, data.value);
}

_Bool compareKeys(keyType key1, keyType key2)
{
  return !strcmp(key1, key2);
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
  struct Node *next;
};

struct LinkedList
{
  size_t size;
  struct Node *head;
};

struct LinkedList createLinkedList()
{
  struct LinkedList list = {.size = 0, .head = NULL};
  return list;
}

struct Node *getNode(struct Payload data)
{
  struct Node *result = malloc(sizeof(struct Node));
  if (result == NULL)
  {
    perror("Can't allocate memory for a node!");
    exit(1);
  }
  result->data = data;
  result->next = NULL;
  return result;
}

void addNode(struct LinkedList *list, struct Payload data)
{
  struct Node *node = getNode(data);
  if (list->head == NULL)
  {
    list->head = node;
  }
  else
  {
    node->next = list->head;
    list->head = node;
  }
  list->size++;
}

struct Node *findNode(struct LinkedList *list, keyType key)
{
  struct Node *current = list->head;
  while (current != NULL)
  {
    if (compareKeys(key, current->data.key))
    {
      break;
    }
    current = current->next;
  }
  return current;
}

void printList(struct LinkedList *list)
{
  struct Node *current = list->head;
  while (current != NULL)
  {
    printPayload(current->data);
    current = current->next;
  }
}

void clearList(struct LinkedList *list)
{
  struct Node *current = list->head;
  while (current != NULL)
  {
    struct Node *savedNext = current->next;
    free(current);
    current = savedNext;
  }
  list->size = 0;
  list->head = NULL;
}

// --------------------------------------------------------------

struct HashTable
{
  size_t size;
  struct LinkedList *buckets;
};

struct HashTable createHashTable(size_t size)
{
  struct LinkedList *buckets = malloc(sizeof(struct LinkedList) * size);

  if (buckets == NULL)
  {
    perror("Can't allocate memory for a hash table!");
    exit(1);
  }

  for (size_t i = 0; i < size; i++)
  {
    buckets[i] = createLinkedList();
  }

  struct HashTable table = {.size = size, .buckets = buckets};
  return table;
}

void clearHashTable(struct HashTable *table)
{
  for (size_t i = 0; i < table->size; i++)
  {
    clearList(&table->buckets[i]);
  }
  free(table->buckets);
  table->buckets = NULL;
  table->size = 0;
}

size_t getBucket(struct HashTable *table, keyType key)
{
  return getHash(key) % table->size;
}

void setValue(struct HashTable *table, keyType key, valueType value)
{
  size_t bucket = getBucket(table, key);
  struct LinkedList *list = &table->buckets[bucket];
  struct Node *node = findNode(list, key);
  if (node)
  {
    node->data.value = value;
  }
  else
  {
    struct Payload payload;
    setPayloadKey(&payload, key);
    setPayloadValue(&payload, value);
    addNode(list, payload);
  }
}

valueType getValue(struct HashTable *table, keyType key)
{
  size_t bucket = getBucket(table, key);
  struct LinkedList *list = &table->buckets[bucket];
  struct Node *node = findNode(list, key);
  return node ? node->data.value : 0;
}

void printHashTable(struct HashTable *table)
{
  _Bool hasData = false;
  for (size_t i = 0; i < table->size; i++)
  {
    struct LinkedList *bucket = &table->buckets[i];
    if (bucket->size != 0)
    {
      printList(bucket);
      hasData = true;
    }
  }
  if (!hasData)
  {
    printf("The hash table is empty!\n");
  }
}