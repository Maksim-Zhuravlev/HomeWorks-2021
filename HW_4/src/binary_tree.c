#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/binary_tree.h"


struct Binary_Tree *tree_create(keyType key, valueType value) {     // TODO: change?
    struct Payload payload = {};
    setPayloadKey(&payload, key);
    setPayloadValue(&payload, value);
    return tree_create_node(payload);
}


struct Binary_Tree *tree_create_node(struct Payload data) {
    struct Binary_Tree *node = malloc(sizeof(struct Binary_Tree));
    if (node == NULL) {
        perror("Not enough memory");
        exit(1);
    }

    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}


struct Binary_Tree *tree_insert(struct Binary_Tree *tree, struct Payload data) {    // TODO: slow
    if (!tree) {
        return tree_create_node(data);
    } else if (strcmp(data.key, tree->data.key) < 0) {
        tree->left = tree_insert(tree->left, data);
    } else {
        tree->right = tree_insert(tree->right, data);
    }
    return tree;
}


struct Binary_Tree *tree_find(struct Binary_Tree *tree, keyType key) {
    if (!tree) {
        return NULL;
    }

    int cmp = strcmp(tree->data.key, key);
    if (cmp == 0) {
        return tree;
    } else if (cmp == -1) {
        return tree_find(tree->left, key);
    } else {
        return tree_find(tree->right, key);
    }
}


valueType tree_get_value(struct Binary_Tree *tree, keyType key, valueType default_value) {
    struct Binary_Tree *node = tree_find(tree, key);
    return node ? node->data.value : default_value;
}


void tree_set_value(struct Binary_Tree *tree, keyType key, valueType value) {
    struct Binary_Tree *node = tree_find(tree, key);
    if (node) {
        tree->data.value = value;
    } else {
        struct Payload payload = {};
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        tree_insert(tree, payload);
    }
}


void tree_print(struct Binary_Tree *tree, int depth) {
    if (!tree) {
//        printf("%*s\n", depth * 8, "null");
        return;
    }
    tree_print(tree->left, 1 + depth);
    printf("%*s\n", depth * 8, tree->data.key);
    tree_print(tree->right, 1 + depth);
}


void test_tree() {
    struct Binary_Tree *tree = tree_create("test", 0);
//    struct Binary_Tree *tree;
//    struct Binary_Tree *tree = tree_insert(tree, NULL);
    tree_set_value(tree, "12", 3);
    tree_set_value(tree, "42", 3);
    tree_set_value(tree, "02", 3);
    tree_set_value(tree, "abc", 5);
    tree_set_value(tree, "xyz", 4);
    tree_set_value(tree, "def", 3);
    tree_print(tree, 0);
}
