#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void printTree(struct Node* root, int space) {

    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main() {

    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nRecursive BST:\n");
    printTree(root, 0);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &key);

    if (search(root, key) != NULL)
        printf("%d found in BST.\n", key);
    else
        printf("%d not found in BST.\n", key);

    return 0;
}