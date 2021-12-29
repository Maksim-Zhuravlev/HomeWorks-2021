#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//===================== specific part=========================

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

size_t getHash(keyType key)
{
    int hash = 0;
    for (int i = 0; key[i]; i++)
    {
        hash += key[i];
    }
    return hash;
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

//===================== common part =========================

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

struct HashTable
{
    size_t size;
    struct LinkedList *buckets;
};

struct Node *getNode(struct Payload data)
{
    struct Node *res = malloc(sizeof(struct Node));
    if (NULL == res)
    {
        perror("Not enough memory.");
        exit(1);
    }
    res->data = data;
    res->next = NULL;
    return res;
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
    struct Node *curr = list->head;
    while (curr != NULL)
    {
        if (compareKeys(key, curr->data.key))
        {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

void printList(struct LinkedList *list)
{
    struct Node *curr = list->head;
    while (curr != NULL)
    {
        printPayload(curr->data);
        curr = curr->next;
    }
}

void clearList(struct LinkedList *list)
{
    struct Node *curr = list->head;
    while (curr != NULL)
    {
        struct Node *savedNext = curr->next;
        free(curr);
        curr = savedNext;
    }
    list->size = 0;
    list->head = NULL;
}

struct LinkedList createLinkedList()
{
    struct LinkedList list = {.size = 0, .head = NULL};
    return list;
}

struct HashTable createHashTable(size_t size)
{
    struct LinkedList *buckets = malloc(sizeof(struct LinkedList) * size);

    if (buckets == NULL)
    {
        perror("Cannot allocate memory for HashTable.");
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

void setValueInc(struct HashTable *table, keyType key)
{
    size_t bucket = getBucket(table, key);
    struct LinkedList *list = &table->buckets[bucket];
    struct Node *node = findNode(list, key);
    if (node)
    {
        node->data.value = (node->data.value + 1);
    }
    else
    {
        struct Payload payload;
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, 1);
        addNode(list, payload);
    }
}

valueType getValue(struct HashTable *table, keyType key, valueType defValue)
{
    size_t bucket = getBucket(table, key);
    struct LinkedList *list = &table->buckets[bucket];
    struct Node *node = findNode(list, key);
    return node ? node->data.value : defValue;
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
        printf("The hash table is empty.\n");
    }
}


void correctWord(char *word, char *correct_word)
{
    int start = 0, end = 0, null = 0;
    char symbols[32] = "1234567890-…[]«».,!?;:()\'\"";
    for (int i = 0; i < 2; i++)
    {
        if (start == i)
        {
            for (int j = 0; j < strlen(symbols); j++)
            {
                if (word[i] == symbols[j])
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
            for (int j = 0; j < strlen(symbols); j++)
            {
                if (word[strlen(word) - (i + 1)] == symbols[j])
                {
                    end = i + 1;
                }
            }
        }
    }
    for (int i = 0; i < strlen(word) - (start + end); i++)
    {
        correct_word[i] = word[start + i];
        null = i;
    }
    correct_word[null + 1] = '\0';
}

void information(struct HashTable table)
{
    int min_length = MAX_WORD_LENGTH, max_length = 0, not_empty = 0, count_of_length = 0;
    for (size_t i = 0; i < table.size; ++i)
    {
        if ((table.buckets[i]).size)
        {
            min_length = MIN((table.buckets[i]).size, min_length);
            max_length = MAX((table.buckets[i]).size, max_length);
            count_of_length += (table.buckets[i]).size;
            not_empty++;
        }
    }

    printf("==============\n");
    printf("The min length of chain: %d\n", min_length);
    printf("The max length of chain: %d]n", max_length);
    printf("Average chain length: %d\n", (count_of_length / not_empty));
    printf("Number of non-zero chains: %d\n", not_empty);
    printf("==============\n");
}

int main()
{
    for (int i = 1; i < 100000 + 1; i *= 10)
    {
        FILE *file = fopen("book.txt", "r");
        char word[MAX_WORD_LENGTH], correct_word[MAX_WORD_LENGTH];
        struct HashTable table = createHashTable(i);
        if (!file)
        {
            printf("The file is missing");
            exit(1);
        }
        while (fscanf(file, "%s", word) != EOF)
        {
            correctWord(word, correct_word);
            setValue(&table, word, getValue(&table, word, 0) + 1);
        }
        printf("Size of hash-table: %d\n", i);
        information(table);
        clearHashTable(&table);
        fclose(file);
    }
    return 0;
}