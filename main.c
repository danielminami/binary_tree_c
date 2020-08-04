#include <stdio.h>
#include <stdlib.h>

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

int main() {
    
    tree_node_t *root = createNewNode(8);
    root->left = createNewNode(3);
    root->left->left = createNewNode(1);
    root->left->right = createNewNode(6);
    root->left->right->left = createNewNode(4);
    root->left->right->right = createNewNode(7);
    root->right = createNewNode(10);
    root->right->right = createNewNode(14);
    root->right->right->left = createNewNode(13);
    
    printf("Pre Order: ");
    preOrder(root);
    printf("\n");
    
    printf("In Order: ");
    inOrder(root);
    printf("\n");
    
    printf("Post Order: ");
    postOrder(root);
    printf("\n");
    
    exit(0);
}

