#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;
node *create()
{
    node *newNode;
    newNode=(node*)malloc(sizeof(node));
    printf("\nenter data(-1for no node)");
    scanf("%d",&newNode->data);
    if(newNode->data==-1)
    return 0;
    printf("\nenter data for left child of %d",newNode->data);
    newNode->left=create();
    printf("\nenter data for Rightchild of %d",newNode->data);
    newNode->right=create();
    return newNode;
}
void Inorder(node *root)
{
    if(root==0)
    return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Preorder(node *root)
{
    if(root==0)
    return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node *root)
{
    if(root==0)
    return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data); 
}
void main()
{
    node *root;
    root=create();
    printf("\nInorder traversal is: ");
    Inorder(root);
    printf("\nPreorder traversal is: ");
    Preorder(root);
    printf("\nPostorder traversal is: ");
    Postorder(root);
}