#include <stdio.h>
#include <stdlib.h>
int i = 0;
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *p, *temp, *head;
void add()
{
    if (i == 0)
    {
        head = (node *)malloc(sizeof(node));
        head->next = NULL;
        head->prev = NULL;
        printf("\nenter data :");
        scanf("%d", &head->data);
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter data:");
        scanf("%d", &temp->data);
        p = head;
        while (p->next != NULL)
        {

            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
        temp->prev = p;
    }
    i++;
}
void insertAtbegining()
{
    printf("\nEnter data: ");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
}
void insert_at_location()
{
    printf("\nEnter position to insert:");
    int pos;
    scanf("%d", &pos);
    temp = (node *)malloc(sizeof(node));
    p = head;
    for (int i = 1; i < pos; i++)
    {
        p = p->next;
    }
    printf("\nEnter data");
    scanf("%d", &temp->data);
    temp->next = p->next;
    p->next = temp;
    temp->prev = p;
}
void insert_at_end()
{
    printf("Enter data");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
}
void print()
{
    p = head;
    printf("\nThe list is:-");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}
void delete_at_start()
{
    head = head->next;
    head->prev = NULL;
}
void delete_at_end()
{
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
}
void delete_at_position()
{
    int pos;
    printf("\nEnter position to delete node:");
    scanf("%d", &pos);
}
void main()
{
    int ch, ans = 1;
    while (1)
    {
        printf("\n----------MENU--------\n1)Add element \n2)Display list\n3)InsertAtEND\n4)InsertAtbegining\n5)Insert at a location\n6)Delete starting node\n7)Delete end node\n8)Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            print();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insertAtbegining();
            break;
        case 5:
            insert_at_location();
            break;
        case 6:
            delete_at_start();
            break;
        case 7:
            delete_at_end();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }
}