#pragma once

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

_Bool compare_keys(key_type key1, key_type key2);

struct payload get_payload(key_type key, value_type val);

void print_payload(struct payload data);

size_t get_hash(key_type data);

//----common-part----
//----Linked-List----

struct node {
	struct payload data;
	struct node* next;
};

struct linked_list {
	size_t size;
	struct node* head;
};

struct node* get_node(struct payload data);

void add_node(struct linked_list* list, struct payload data);

struct node* find_node(struct linked_list* list, key_type key);

void clear_list(struct linked_list* list);

struct linked_list create_list();

void print_list(struct linked_list* list);
//----hash-table----

struct hash_table {
	size_t size;
	struct linked_list* buckets;
};

struct hash_table create_hash_table(size_t size);

void clear_hash_table(struct hash_table* table);

size_t get_bucket(struct hash_table* table, key_type key);

void set_value(struct hash_table* table, key_type key, value_type val);

value_type get_value(struct hash_table* table, key_type key, value_type default_val);

void print_hash_table(struct hash_table* table);