#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define the structure for a Node in BST
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal with recursion
void inorderRecursion(struct Node* root) {
    if (root != NULL) {
        inorderRecursion(root->left);
        printf("%d ", root->data);
        inorderRecursion(root->right);
    }
}

// Function for preorder traversal with recursion
void preorderRecursion(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursion(root->left);
        preorderRecursion(root->right);
    }
}

// Function for postorder traversal with recursion
void postorderRecursion(struct Node* root) {
    if (root != NULL) {
        postorderRecursion(root->left);
        postorderRecursion(root->right);
        printf("%d ", root->data);
    }
}

// Function for inorder traversal without recursion
void inorderNoRecursion(struct Node* root) {
    struct Node* stack[100]; // Stack to store nodes
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function for preorder traversal without recursion
void preorderNoRecursion(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100]; // Stack to store nodes
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function for postorder traversal without recursion
void postorderNoRecursion(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100]; // Stack to store nodes
    struct Node* stack2[100]; // Stack to reverse the postorder traversal
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Driver code with menu-driven approach
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("-------------------------------------");
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);;

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                do {
                    printf("-------------------------------------");
                    printf("\nTraversal Options\n");
                    printf("1. With Recursion\n");
                    printf("2. Without Recursion\n");
                    printf("3. Back to main menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("-------------------------------------");
                            printf("\nTraversal with Recursion\n");
                            printf("1. Inorder\n");
                            printf("2. Preorder\n");
                            printf("3. Postorder\n");
                            printf("4. Back to traversal options\n");
                            printf("Enter your choice: ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    printf("Inorder Traversal (With Recursion): ");
                                    inorderRecursion(root);
                                    printf("\n");
                                    break;
                                case 2:
                                    printf("Preorder Traversal (With Recursion): ");
                                    preorderRecursion(root);
                                    printf("\n");
                                    break;
                                case 3:
                                    printf("Postorder Traversal (With Recursion): ");
                                    postorderRecursion(root);
                                    printf("\n");
                                    break;
                                case 4:
                                    break;
                                default:
                                    printf("Invalid choice. Please try again.\n");
                            }
                            break;
                        case 2:
                            printf("-------------------------------------");
                            printf("\nTraversal without Recursion\n");
                            printf("1. Inorder\n");
                            printf("2. Preorder\n");
                            printf("3. Postorder\n");
                            printf("4. Back to traversal options\n");
                            printf("Enter your choice: ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    printf("Inorder Traversal (Without Recursion): ");
                                    inorderNoRecursion(root);
                                    printf("\n");
                                    break;
                                case 2:
                                    printf("Preorder Traversal (Without Recursion): ");
                                    preorderNoRecursion(root);
                                    printf("\n");
                                    break;
                                case 3:
                                    printf("Postorder Traversal (Without Recursion): ");
                                    postorderNoRecursion(root);
                                    printf("\n");
                                    break;
                                case 4:
                                    break;
                                default:
                                    printf("Invalid choice. Please try again.\n");
                            }
                            break;
                        case 3:
                            printf("Returning to main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 3);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
