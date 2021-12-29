#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#endif // TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


#define MAX_WORD_LENGTH 20

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH];

size_t max(size_t x, size_t y){
    if (x < y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int getHashMul(char* str)
{
	int l = strlen(str);
	int res = 0;
	int mul = 31;

	for (int i = 0; i < l; i++)
	{
		res =  res+str[i]*mul;
		mul=mul*31;
	}
	return res;
}


struct Payload {
	keyType key;
	valueType value;
};


void setPayloadKey(struct Payload* payload, keyType key){
	strcpy(payload->key, key);
}


void setPayloadValue(struct Payload* payload, valueType value){
	payload->value = value;
}


void printPayload(struct Payload data){
	printf("key = %s, value = %d\n", data.key, data.value);
}


_Bool compareKeys(keyType key1, keyType key2){
	return !strcmp(key1, key2);
}


struct Node{
    struct Payload data;
    struct Node* left;
    struct Node* right;
};


struct Tree{
    struct Node* root;
};


struct Tree createTree(){
    struct Tree newTree = { .root = NULL };

    return newTree;
}


struct Node* getNode(struct Payload data){
	struct Node* res = malloc(sizeof(struct Node));
	if (res == NULL)
    {
		perror("Not enough memory");
		exit(1);
	}

	res->data = data;
	res->left = NULL;
	res->right = NULL;

	return res;
}


void insertNode(struct Node* tree, struct Node* node){
    if ( node->data.value <= tree->data.value )
    {
        if (tree->left == NULL)
        {
            tree->left = node;
        }
        else
        {
            insertNode(tree->left, node);
        }
    }
    else
    {
         if (tree->right == NULL)
        {
            tree->right = node;
        }
        else
        {
            insertNode(tree->right, node);
        }
    }
}


void addNode(struct Tree* tree, struct Payload newData){
    struct Node* newNode = getNode(newData);


    if (tree->root == NULL)
    {
        tree->root = newNode;
    }
    else
    {
        insertNode(tree->root, newNode);
    }
}


struct Node* findNode(struct Node* node, keyType key, valueType value){
    if (node->data.value == value)
    {
        if ( compareKeys(node->data.key, key) )
        {
            return node;
        }
    }

    if (value <= node->data.value)
    {
        if (node->left == NULL)
        {
            return NULL;
        }
        else
        {
            return findNode(node->left, key, value);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            return NULL;
        }
        else
        {
            return findNode(node->right, key, value);
        }
    }

};


valueType getValue(struct Tree* tree, keyType key, valueType defValue) {
	struct Node* node = findNode(tree, key, getHashMul(key));
	return node ? node->data.value : defValue;
}


void setValue(struct Tree* tree, keyType key, valueType value){
    if (tree->root == NULL)
    {
        struct Payload payload = {};
        setPayloadKey(&payload, key);
        setPayloadValue(&payload, value);
        addNode(tree, payload);
    }
    else
    {
        struct Node* node = findNode(tree->root, key, value);

        if (node)
        {
            node->data.value = value;
        }
        else
        {
            struct Payload payload = {};
            setPayloadKey(&payload, key);
            setPayloadValue(&payload, value);
            addNode(tree, payload);
        }
    }
}


void addWord(struct Tree* tree, char* str){
    setValue(tree, str, getHashMul(str));
}


size_t getNodeHeght(struct Node* node){
    size_t leftSubTree = 0;
    size_t rightSubTree = 0;

    if (node->left != NULL)
    {
      leftSubTree = getNodeHeght(node->left);
    }

    if (node->right != NULL)
    {
      rightSubTree = getNodeHeght(node->right);
    }

    return 1+max(leftSubTree, rightSubTree);
}


size_t getHeight(struct Tree* tree){
    if (tree->root == NULL)
    {
        return 0;
    }
    else
    {
        return getNodeHeght(tree->root);
    }
}


void printNodeDfs(struct Node* node){
     printPayload(node->data);

    if (node->left != NULL)
    {
        printNodeDfs(node->left);
    }

    if (node->right != NULL)
    {
        printNodeDfs(node->right);
    }
}


 void printTreeDfs(struct Tree* tree){
    if (tree->root == NULL)
    {
        printf("The bin tree is empty\n");
    }
    else
    {
        printNodeDfs(tree->root);
    }
 }


 void clearNode(struct Node* node){
    if (node->left != NULL)
    {
        clearNode(node->left);
    }
    if (node->right != NULL)
    {
        clearNode(node->right);
    }

    free(node);
}


 void clearTree(struct Tree* tree){
    if (tree->root != NULL)
        clearNode(tree->root);
 }

