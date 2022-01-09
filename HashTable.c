#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <limits.h>
#include <math.h>
#include <time.h>

#define MAX_WORD_LENGTH 200



typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload
{
    keyType key;
    valueType value;
};

struct HashTable {
    size_t size;
    struct LinkedList* buckets;
};


size_t getHash(keyType key) {
    const int p = 67; // первое простое число после 66 (количество букв в русском алфавите * 2 )
    long long hash = 0, p_pow = 1;
    for (size_t i = 0; i < MAX_WORD_LENGTH; ++i)
    {
        // желательно отнимать 'А' от кода буквы
        // единицу прибавляем, чтобы у строки вида "АААА" хэш был ненулевой
        hash += (key[i] - 'А' + 1) * p_pow;
        p_pow *= p;
    }
    return hash;
}

_Bool compareKeys(keyType key1, keyType key2) {
    return !strcmp(key1, key2);
}

void setPayloadKey(struct Payload* payload, keyType key) {
    strcpy(payload->key, key);
}

void setPayloadValue(struct Payload* payload, valueType value) {
    payload->value = value;
}


void printPayload(struct Payload data) // выводит на экран пару ключ-значение
{
    printf("key = %s, value = %d\n", data.key, data.value);
}

struct Node
{
    struct Payload data;
    struct Node* next;
};

struct LinkedList // структура, указывающая на первый элемент списка
{
    size_t size;
    struct Node* head;
};

struct LinkedList createLinkedList() // инициализация структуры, через которую мы производим все манипуляции со списком
{
    struct LinkedList list = { .size = 0, .head = NULL };
    return list;
};

struct Node* getNode(struct Payload data) // создание узла (упаковка полезной нагрузки в структуру Node)
{
    struct Node* res = malloc(sizeof(struct Node));
    if (res == NULL)
    {
        perror("Not enough memory");
        exit(1);
    }
    res->data = data; //(*res).data 
    res->next = NULL;
    return res;
};

void addNode(struct LinkedList* list, struct Payload data) // добавление узла в список
{
    struct Node* node = getNode(data);
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
struct Node* findNode(struct LinkedList* list, keyType key) // поиск узла по ключу с помощью перебора
{
    struct Node* curr = list->head;
    while (curr != NULL)
    {
        if (compareKeys(key, curr->data.key))
        {
            break;
        }
        curr = curr->next;
    }
    return curr;
};
void printList(struct LinkedList* list) // вывод значений
{
    struct Node* curr = list->head;
    while (curr != NULL)
    {
        printPayload(curr->data);
        curr = curr->next;
    }
}
void clearList(struct LinkedList* list) // очищение списка
{
    struct Node* curr = list->head;
    while (curr != NULL)
    {
        struct Node* savedNext = curr->next;
        free(curr);
        curr = savedNext;
    }
    list->size = 0;
    list->head = NULL;
}

struct HashTable createHashTable(size_t size) {
    struct LinkedList* buckets = malloc(sizeof(struct LinkedList) * size);
    if (buckets == NULL) {
        perror("Cannot allocate memory for HashTable");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        buckets[i] = createLinkedList();
    }


    struct HashTable table = { .size = size, .buckets = buckets };
    return table;
}

void clearHashTable(struct HashTable* table) {
    for (size_t i = 0; i < table->size; i++) {
        clearList(&table->buckets[i]);
    }
    free(table->buckets);
    table->buckets = NULL;
    table->size = 0;
}


size_t getBucket(struct HashTable* table, keyType key) {
    return getHash(key) % table->size; // остаток от деления = номер корзины
}
void setValue(struct HashTable* table, keyType key, valueType value) {
    size_t bucket = getBucket(table, key);
    struct LinkedList* list = &table->buckets[bucket];
    struct Node* node = findNode(list, key);
    if (node) {
        node->data.value = value;
    }
    else {
        struct Payload payload;
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        addNode(list, payload);
    }
}

valueType getValue(struct HashTable* table, keyType key, valueType defValue) {
    size_t bucket = getBucket(table, key);
    struct LinkedList* list = &table->buckets[bucket];
    struct Node* node = findNode(list, key);
    return node ? node->data.value : defValue;
}

void printHashTable(struct HashTable* table) {
    _Bool hasData = false;
    for (size_t i = 0; i < table->size; i++) {
        struct LinkedList* bucket = &table->buckets[i];
        if (bucket->size != 0) {
            printList(bucket);
            hasData = true;
        }
    }
    if (!hasData) {
        printf("The hash table is empty\n");
    }
}

void statistic(struct HashTable* table) {
    size_t max_len = 0, min_len = _CRT_SIZE_MAX, not_empty_num = 0, lens_sum = 0;
    for (size_t i = 0; i < table->size; ++i) {
        if ((table->buckets[i]).size) {
            if (max_len < (table->buckets[i]).size) {
                max_len = (table->buckets[i]).size;
            }
            if (min_len > (table->buckets[i]).size) {
                min_len = (table->buckets[i]).size;
            }
            ++not_empty_num;
            lens_sum += (table->buckets[i]).size;
        }
    }
    printf("number of not empty chains = %d\n", not_empty_num);
    printf("average chain length = %d\n", (lens_sum / (table->size)));
    printf("min length = %d\n", min_len);
    printf("max length = %d\n", max_len);
    printf("%d\t%d\t%d\t%d\n", not_empty_num, (lens_sum / (table->size)), min_len, max_len);
    printf("------\n");
}

int main() {
    int i = 0;
    clock_t start, finish;
    struct HashTable hashtable = createHashTable(100000); // количество корзин 
    char data[MAX_WORD_LENGTH]; // массив для чтения
    FILE* file = NULL;
    file = fopen("C:/Test/dostoevsky.txt", "rt");
    if (file == NULL) {
        perror("File error");
        exit(1);
    }
    printf("%s\n", "File is ok");
    start = clock();

    while (!feof(file)) // пока файл не закончится
    {
        fscanf(file, "%s", data); // считываем строку в массив
        setValue(&hashtable, data, getHash(data)); // заполняем ассоциативный массив
        ++i;
    }
    finish = clock();
    fclose(file);
    printHashTable(&hashtable);
    printf("%i\n", i);
    printf("Time %d msec\n", (finish - start));
    statistic(&hashtable);
    clearHashTable(&hashtable);

}