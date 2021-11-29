#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/binary_tree.h"
#include "../include/utils.h"


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


struct Binary_Tree *tree_insert(struct Binary_Tree *tree, struct Payload data) {
    if (!tree) {
        return tree_create_node(data);
    } else if (compareKeys(data.key, tree->data.key) < 0) {
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
    int cmp = compareKeys(key, tree->data.key);
    if (cmp == 0) {
        return tree;
    } else if (cmp < 0) {
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
        node->data.value = value;
    } else {
        struct Payload payload = {};
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        tree_insert(tree, payload);
    }
}


void tree_destroy(struct Binary_Tree *tree) {
    if (tree->left) { tree_destroy(tree->left); }
    if (tree->right) { tree_destroy(tree->right); }
    free(tree);
}


size_t tree_count_nodes(struct Binary_Tree *tree) {
    if (!tree) { return 0; }
    return 1 + tree_count_nodes(tree->left) + tree_count_nodes(tree->right);
}


size_t tree_max_depth(struct Binary_Tree *tree) {
    if (!tree) { return 0; }
    return max(tree_max_depth(tree->left), tree_max_depth(tree->right)) + 1;
}


size_t tree_min_depth(struct Binary_Tree *tree){
    if (!tree) { return 0; }
    return min(tree_min_depth(tree->left), tree_min_depth(tree->right)) + 1;
}


float tree_mean_depth(struct Binary_Tree *tree){
    if (!tree) { return 0; }
    return (tree_mean_depth(tree->left) + tree_mean_depth(tree->right)) / 2 + 1;
}


void tree_to_file(struct Binary_Tree *tree, FILE *file) {
    size_t size = tree_count_nodes(tree);
    struct Payload *data[size];
    struct Binary_Tree *current, *stack[size];
    int stack_ptr = 0, payload_ptr = 0;
    stack[stack_ptr] = tree;

    while (stack_ptr >= 0) {
        current = stack[stack_ptr];
        --stack_ptr;

        data[payload_ptr] = &current->data;
        ++payload_ptr;
        if (current->left != NULL) {
            stack[stack_ptr + 1] = current->left;
            ++stack_ptr;
        }
        if (current->right != NULL) {
            stack[stack_ptr + 1] = current->right;
            ++stack_ptr;
        }
    }

    qsort(data, size, sizeof(struct Payload *), compare_payloads);
    for (int i = 0; i < size; ++i) {
        if (data[i]->value > 0) {
            fprintf(file, "%s %d\n", data[i]->key, data[i]->value);
        }
    }
}


void tree_print(struct Binary_Tree *tree, int depth) {
    if (!tree) {
//        printf("%*s\n", depth * 8, "null");
        return;
    }
    tree_print(tree->left, 1 + depth);
    printf("%*s %d\n", depth * 8, tree->data.key, tree->data.value);
    tree_print(tree->right, 1 + depth);
}

/*
void test_tree() {
    struct Binary_Tree *tree = tree_create("test", 0);
    tree_set_value(tree, "12", 3);
    tree_set_value(tree, "42", 3);
    tree_set_value(tree, "02", 3);
    tree_set_value(tree, "abc", 5);
    tree_set_value(tree, "xyz", 4);
    tree_set_value(tree, "def", 3);
    tree_print(tree, 0);
}
*/
