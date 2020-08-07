#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data {
    int number;
} node_data_t;

typedef struct node {
    node_data_t data;
    struct node *left;
    struct node *right;
} tree_node_t;

tree_node_t *createNewNode(int newData) {
    tree_node_t *newNode = (tree_node_t*)malloc(sizeof(tree_node_t));
    newNode->data.number = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void visitNode(tree_node_t* node) {
    printf("%d ", node->data.number);
}

void preOrder(tree_node_t* node) {
    if (node != NULL) {
        visitNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(tree_node_t* node) {
    if (node != NULL) {
        inOrder(node->left);
        visitNode(node);
        inOrder(node->right);
    }
}

void postOrder(tree_node_t* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        visitNode(node);
    }
}

int nodeCount(tree_node_t *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + nodeCount(node->left) + nodeCount(node->right);
}

tree_node_t* insert(tree_node_t* node, int key) {
    if(node==NULL) return createNewNode(key);
    
    if(key < node->data.number)
        node->left = insert(node->left,key);
    else if(key > node->data.number)
        node->right = insert(node->right,key);
    return node;
}

tree_node_t* contains(tree_node_t* node, int key) {
    if (node==NULL) return NULL;
    if (key == node->data.number) {
        return node;
    } else if (key > node->data.number) {
        contains(node->right, key);
    } else {
        contains(node->left, key);
    }
}

int main() {
    
    tree_node_t *root = insert(root, 9);
    insert(root, 15);
    insert(root, 5);
    insert(root, 20);
    insert(root, 20);
    insert(root, 20);
    insert(root, 16);
    insert(root, 8);
    insert(root, 12);
    insert(root, 3);
    insert(root, 6);
    
    printf("Pre Order: ");
    preOrder(root);
    printf("\n");
    
    printf("In Order: ");
    inOrder(root);
    printf("\n");
    
    printf("Post Order: ");
    postOrder(root);
    printf("\n");
    
    printf("Node Counting: %d", nodeCount(root));
    printf("\n");
    
    printf("Function contains should be 5: %d", contains(root, 5)->data.number);
    printf("\n");
    
    if (contains(root, 13) == NULL) {
        printf("Function contains should be NULL: %s", NULL);        
    }
    

    printf("\n");
    
    exit(0);
}

