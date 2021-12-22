#define _CRT_SECURE_NO_WARNINGS

#include "hash_table.h"

//----specific-part----

_Bool compare_keys(key_type key1, key_type key2) {
	return !(strcmp(key1, key2));
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
	//return 4; //constant

	/*
	size_t hash = 0; // sum of symbol codes
	size_t pos = 0;
	while (data[pos]) {
		hash += data[pos];
		++pos;
	}
	return hash;
	*/

	const size_t p = 101;
	unsigned long long hash = 0, p_pow = 1;
	size_t pos = 0;
	while (data[pos]) {
		hash += p_pow * (data[pos] - 'À' + 1);
		p_pow *= p;
		++pos;
	}
	return hash;
}

//----common-part----
//----Linked-List----

struct node* get_node(struct payload data) {
	struct node* res = malloc(sizeof(struct node));
	if (res == NULL) {
		perror("get_node: Not enough memory");
		exit(1);
	}
	res->data = data;
	res->next = NULL;
	return res;
}

void add_node(struct linked_list* list, struct payload data) {
	struct node* new_node = get_node(data);
	new_node->next = list->head;
	list->head = new_node;
	list->size++;
}

struct node* find_node(struct linked_list* list, key_type key) {
	struct node* curr = list->head;
	while (curr != NULL) {
		if (compare_keys(key, (*curr).data.key)) {
			break;
		}
		curr = curr->next;
	}
	return curr;
}

void clear_list(struct linked_list* list) {
	struct node* curr = list->head;
	while (curr != NULL) {
		struct node* next = curr->next;
		free(curr);
		curr = next;
	}
	list->size = 0;
	list->head = NULL;
}

struct linked_list create_list() {
	struct linked_list list = { .size = 0, .head = NULL };
	return list;
}

void print_list(struct linked_list* list) {
	struct node* curr = list->head;
	while (curr != NULL) {
		print_payload(curr->data);
		curr = curr->next;
	}
}
//----hash-table----

struct hash_table create_hash_table(size_t size) {
	struct linked_list* buckets = calloc(size, sizeof(struct linked_list));
	if (buckets == NULL) {
		perror("create_hash_table: Not enough memory for hash table");
		exit(1);
	}
	for (size_t i = 0; i < size; ++i) {
		buckets[i] = create_list();
	}
	struct hash_table res = { .size = size, .buckets = buckets };
	return res;
}

void clear_hash_table(struct hash_table* table) {
	for (size_t i = 0; i < table->size; ++i) {
		clear_list(&table->buckets[i]);
	}
	free(table->buckets);
	table->buckets = NULL;
	table->size = 0;
}

size_t get_bucket(struct hash_table* table, key_type key) {
	return get_hash(key) % table->size;
}

void set_value(struct hash_table* table, key_type key, value_type val) {
	struct linked_list* list = &table->buckets[get_bucket(table, key)];
	struct node* elem = find_node(list, key);
	if (elem) {
		elem->data.value = val;
	}
	else {
		add_node(list, get_payload(key, val));
	}
}

value_type get_value(struct hash_table* table, key_type key, value_type default_val) {
	struct linked_list* list = &table->buckets[get_bucket(table, key)];
	struct node* node = find_node(list, key);
	return node ? node->data.value : default_val;
}

void print_hash_table(struct hash_table* table) {
	_Bool empty = 1;
	for (size_t i = 0; i < table->size; ++i) {
		struct linked_list* list = &table->buckets[i];
		if (list->size) {
			print_list(list);
			empty = 0;
		}
	}
	if (empty) {
		printf("The hash table is empty\n");
	}
}