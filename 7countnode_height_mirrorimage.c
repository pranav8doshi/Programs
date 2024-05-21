#include <stdio.h>
#include <stdlib.h>

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

// Function to count nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1; // Height of an empty tree is -1

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return the maximum of leftHeight and rightHeight plus 1 (for the current level)
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to swap left and right subtrees to create a mirror image of the tree
void mirrorImage(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right subtrees
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorImage(root->left);
    mirrorImage(root->right);
}

// Function to deallocate memory of the tree
void deleteTree(struct Node* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Function to display the menu and get user's choice
int getMenuChoice() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Insert data into the tree\n");
    printf("2. Count nodes in the tree\n");
    printf("3. Find height of the tree\n");
    printf("4. Create mirror image of the tree\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Driver code
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                printf("Enter data to insert into the tree: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Number of nodes in the tree: %d\n", countNodes(root));
                break;
            case 3:
                printf("Height of the tree: %d\n", findHeight(root));
                break;
            case 4:
                printf("Creating mirror image of the tree...\n");
                mirrorImage(root);
                printf("Mirror image created.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Deallocate memory of the tree before exiting
    deleteTree(root);

    return 0;
}
