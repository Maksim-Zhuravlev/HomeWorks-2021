#ifndef UNTITLED_BINARY_TREE_H
#define UNTITLED_BINARY_TREE_H

#include "payload.h"


struct Binary_Tree {
    struct Payload data;
    struct Binary_Tree *left, *right;
};


struct Binary_Tree *tree_create_node(struct Payload data);

struct Binary_Tree *tree_insert(struct Binary_Tree *tree, struct Payload data);

struct Binary_Tree *tree_find(struct Binary_Tree *tree, keyType key);

valueType tree_get_value(struct Binary_Tree *tree, keyType key, valueType default_value);

struct Binary_Tree * tree_set_value(struct Binary_Tree *tree, keyType key, valueType value);

void tree_destroy(struct Binary_Tree *tree);

size_t tree_count_nodes(struct Binary_Tree *tree);

size_t tree_max_depth(struct Binary_Tree *tree);

size_t tree_min_depth(struct Binary_Tree *tree);

float tree_mean_depth(struct Binary_Tree *tree);

void tree_to_file(struct Binary_Tree *tree, FILE *file);

void tree_print(struct Binary_Tree *tree, int depth);


#endif //UNTITLED_BINARY_TREE_H
