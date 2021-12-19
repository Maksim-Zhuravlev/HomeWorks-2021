#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

//----specific-part----

#define max_word_length 30

typedef int value_type;
typedef char key_type[max_word_length + 1];

struct payload {
	value_type value;
	key_type key;
};

int compare_keys(char* key1, char* key2) {
	size_t pos = -1;
	int res = 0;
	do {
		++pos;
		res = key1[pos] - key2[pos];
	} while ((key1[pos] == key2[pos]) && key1[pos] && key2[pos]);
	return res;
}

struct payload get_payload(key_type key, value_type val) {
	struct payload rec;
	strcpy(rec.key, key);
	rec.value = val;
	return rec;
}

void print_payload(struct payload data) {
	printf("key = %s, value = %d\n", data.key, data.value);
}

size_t get_hash(key_type data) {
	const size_t p = 37;
	size_t hash = 0, p_pow = 1;
	size_t pos = 0;
	while (data[pos]) {
		hash += p_pow * (data[pos] - 'À' + 1);
		p_pow *= p;
		++pos;
	}
	return hash;
}

//----common-part----
//----binary-tree----

struct binary_tree_node {
	struct payload data;
	struct binary_tree_node* left, * right;
};

struct binary_tree {
	struct binary_tree_node* root;
};

struct binary_tree_node* new_node(struct payload data) {
	struct binary_tree_node* res = malloc(sizeof(struct binary_tree_node));
	if (!res) {
		perror("binary_tree get_node: Not enough memory");
		exit(1);
	}
	res->data = data;
	res->right = NULL;
	res->left = NULL;
	return res;
}

void add_node(struct binary_tree* tree, struct payload data) {
	if (!tree->root) {
		tree->root = new_node(data);
		return;
	}
	struct binary_tree_node* curr = tree->root, * prev = NULL;
	int diff;
	while (curr) {
		diff = compare_keys(data.key, (curr->data).key);
		if (!diff) {
			curr->data = data;
			return;
		}
		else {
			if (diff > 0) {
				prev = curr;
				curr = curr->right;
			}
			else {
				prev = curr;
				curr = curr->left;
			}
		}
	}
	if (diff > 0) {
		prev->right = new_node(data);
	}
	else {
		prev->left = new_node(data);
	}
}

struct binary_tree_node* find_node(struct binary_tree* tree, key_type key) {
	if (!tree->root) {
		return NULL;
	}
	struct binary_tree_node* curr = tree->root;
	int diff;
	while (curr) {
		diff = compare_keys(key, (curr->data).key);
		if (!diff) {
			return curr;
		}
		else {
			if (diff > 0) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
	}
	return NULL;
}

void remove_node(struct binary_tree* tree, key_type key) {
	struct binary_tree_node* curr = tree->root, * prev = NULL;
	if (curr && !(compare_keys(key, curr->data.key) || curr->left || curr->right)) {
		tree->root = NULL;
		free(curr);
		return;
	}
	int diff;
	while (curr) {
		diff = compare_keys(key, (curr->data).key);
		if (!diff) {
			if (curr->right) {
				struct binary_tree_node* node = curr->right;
				if (!node->left) {
					curr->data = node->data;
					curr->right = node->right;
					free(node);
					return;
				}
				while (node->left->left) {
					node = node->left;
				}
				struct binary_tree_node* removable = node->left;
				curr->data = removable->data;
				node->left = removable->right;
				free(removable);
			}
			else {
				struct binary_tree_node* removable = curr->left;
				if (removable) {
					*curr = (struct binary_tree_node){ .data = removable->data, .left = removable->left, .right = removable->right };
					free(removable);
				}
				else {
					if (prev->left == curr) {
						prev->left = NULL;
					}
					else {
						prev->right = NULL;
					}
					free(curr);
				}
			}
			return;
		}
		else {
			if (diff > 0) {
				prev = curr;
				curr = curr->right;
			}
			else {
				prev = curr;
				curr = curr->left;
			}
		}
	}
}

value_type get_value(struct binary_tree* tree, key_type key, value_type default_val) {
	struct binary_tree_node* res = find_node(tree, key);
	return res ? res->data.value : default_val;
}

void set_value(struct binary_tree* tree, key_type key, value_type val) {
	struct binary_tree_node* res = find_node(tree, key);
	if (res) {
		res->data.value = val;
	}
	else {
		add_node(tree, get_payload(key, val));
	}
}

struct binary_tree create_binary_tree() {
	return (struct binary_tree) { .root = NULL };
}

void clear_subtree(struct binary_tree_node* curr) {
	if (!curr) {
		return;
	}
	clear_subtree(curr->right);
	clear_subtree(curr->left);
	free(curr);
}

void clear_binary_tree(struct binary_tree* tree) {
	clear_subtree(tree->root);
	tree->root = NULL;
}

void print_subtree(struct binary_tree_node* curr, size_t space_num) {
	if (!curr) {
		return;
	}
	print_subtree(curr->right, space_num + 2);
	for (size_t i = 0; i < space_num; ++i) {
		printf(" ");
	}
	print_payload(curr->data);
	print_subtree(curr->left, space_num + 2);
}

void print_binary_tree(struct binary_tree* tree) {
	print_subtree(tree->root, 0);
}