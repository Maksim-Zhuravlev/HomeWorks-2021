#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//===================== specific part =========================

#define MAX_WORD_LENGTH 50


typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
    keyType key;
    valueType value;
};


void printPayload(struct Payload data) {
    printf("key = %s, value = %d\n", data.key, data.value);
}


int compare_keys(keyType key1, keyType key2) {
    return strcmp(key1, key2);
}


void set_payload_key(struct Payload *payload, keyType key) {
    strcpy(payload -> key, key);
}

void set_payload_value(struct Payload *payload, valueType value) {
    payload -> value = value;
}


struct Node {
    struct Payload data;
    struct Node *right;
    struct Node *left;
};


void set_value(struct Node *node, valueType value) {
    node -> data.value = value + 1;
}

//===================== common part =========================\

struct binary_tree {
    struct Node *head;
};


struct Node* get_node(struct Payload data) { //создаем узел
    struct Node *res = malloc(sizeof(struct Node));
    res -> data = data;
    res -> left = NULL;
    res -> right = NULL;
    return res;
}


valueType get_value(struct Node *node, keyType key, valueType defValue) { //получаем value из узла
    int result = compare_keys(key, node -> data.key);
    if (result > 0) {
        if (node -> right == NULL) {
            return defValue;
        }
        else {
            return get_value(node -> right, key, defValue);
        }
    }
    else if (result < 0) {
        if (node -> left == NULL) {
            return defValue;
        }
        else {
            return get_value(node -> left, key, defValue);
        }
    }
    else {
        return node -> data.value;
    }
}


void add_node(struct Node *node, struct Payload data) { //проверяем существует ли узел, если нет - создаем
    int res = compare_keys(data.key, node -> data.key);
    if (res > 0) {
        if (node -> right == NULL) {
            node -> right = get_node(data);
        }
        else {
            add_node(node -> right, data);
        }
    }
    if (res < 0) {
        if (node -> left == NULL) {
            node -> left = get_node(data);
        }
        else {
            add_node(node -> left, data);
        }
    }
    if (res == 0) {
        int x = get_value(node, data.key, data.value);
        set_value(node, x);
    }
}


void add_head(struct binary_tree *tree, struct Payload data) {
    if (tree -> head == NULL) {
        tree -> head = get_node(data);
    }
    else {
        add_node(tree -> head, data);
    }
}


struct binary_tree *create_binary_tree() { //создаем дерево, память под указатель, указатель в NULL
    struct binary_tree *tree = malloc(sizeof(struct binary_tree));
    tree -> head = NULL;
    return tree;
}


void print_binary_tree(struct Node *node) { //печатаем дерево
    if (node == NULL) {
        return;
    }
    print_binary_tree(node -> left);
    printPayload(node -> data);
    print_binary_tree(node -> right);
}


void delete_nodes(struct Node *node) { //чистим узлы
    if (node == NULL) {
        return;
    }
    delete_nodes(node -> left);
    delete_nodes(node -> right);
    free(node);
}


void tree_height(struct Node *node, int *height, int curr_height) {
    if (curr_height >= *height) {
        *height = curr_height;
    }
    if (node == NULL) {
        return;
    }
    tree_height(node -> left, height, curr_height + 1);
    tree_height(node -> right, height, curr_height + 1);
}


void normal_words(char *word, char *normal_word) {
    keyType not_normal = ".,!():;?/";
    int g = 0;
    int i = 0;

    while(word[i] != '\0') {
        int flag = 0;
        int a = 0;
        while(not_normal[a] != '\0') {
            if (word[i] == not_normal[a]) {
                flag += 1;
            }
            a++;
        }
        if (flag == 0)
        {
            normal_word[g] = word[i];
            g++;
        }
        i++;
    }
    normal_word[g] = '\0';
}


int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH + 1];
    char good_word[MAX_WORD_LENGTH + 2];
    if ((file = fopen("my.txt", "r")) == NULL) {
        printf("Did not open the file.\n");
        exit(1);
    }
    clock_t start = clock();
    struct binary_tree *tree = create_binary_tree();
    while (fscanf(file, "%s", word) != EOF) {
        normal_words(word, good_word);
        struct Payload data;
        set_payload_value(&data, 1);
        set_payload_key(&data, good_word);
        add_head(tree, data);
    }

    clock_t finish = clock();
    double timeElapsed = ((double) (finish - start)) / CLOCKS_PER_SEC;

    print_binary_tree(tree -> head);
    fclose(file);

    int *height_pointer;
    int height = 0;
    height_pointer = &height;
    tree_height(tree -> head, height_pointer, 0);
    printf("Height of tree: %d\n", *height_pointer);

    delete_nodes(tree -> head);
    free(tree);

    printf("Time: %f\n\n", timeElapsed);

    return 0;
}