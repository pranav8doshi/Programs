#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right, *left;
    int height;
} node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

node* create_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->height = 1; // New node is at height 1
    return newnode;
}

node* right_rotate(node *y) {
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* left_rotate(node *x) {
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance_factor(node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node* insert(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicate keys are not allowed in AVL tree
        return root;
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed
    int balance = get_balance_factor(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return right_rotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return left_rotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

node* find_min(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* delete_node(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed
    int balance = get_balance_factor(root);

    // Left Left Case
    if (balance > 1 && get_balance_factor(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance_factor(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance_factor(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance_factor(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void postorder(node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right); 
    printf(" %d ", root->data);
}

int main() {
    int ans = 1, data, ch;
    node *root = NULL;

    do {
        printf("\nMenu\n\t1)Insert\n\t2)Delete\n\t3)Print Postorder\n\t4)Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter data to insert in AVL tree: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nEnter data to be deleted: ");
                scanf("%d", &data);
                root = delete_node(root, data);
                break;
            case 3:
            postorder(root);
            break;
            case 4:
                ans = 0;
                break;
            default:
                printf("\nWrong choice!");
        }
    } while (ans == 1);

    return 0;
}

