#ifndef UNTITLED_BINARY_TREE_H
#define UNTITLED_BINARY_TREE_H

#include "payload.h"



struct Binary_Tree {
    struct Payload data;
    struct Binary_Tree *left, *right;
};

struct Binary_Tree *tree_create(keyType key, valueType value);

struct Binary_Tree *tree_create_node(struct Payload data);

struct Binary_Tree *tree_insert(struct Binary_Tree *tree, struct Payload data);

struct Binary_Tree *tree_find(struct Binary_Tree *tree, keyType key);

valueType tree_get_value(struct Binary_Tree *tree, keyType key, valueType default_value);

void tree_set_value(struct Binary_Tree *tree, keyType key, valueType value);

void tree_print(struct Binary_Tree *tree, int depth);

void test_tree();


#endif //UNTITLED_BINARY_TREE_H
