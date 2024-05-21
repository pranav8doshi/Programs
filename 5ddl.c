#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* p, * temp, * head;

void create_list() {
    int no;
    head = (node*)malloc(sizeof(node));
    printf("\n Enter how many nodes you have to create:");
    scanf("%d", &no);
    printf("Enter data:");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    p = head; // Set p to head initially
    for (int i = 1; i < no; i++) {
        temp = (node*)malloc(sizeof(node));
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = p;
        p->next = temp;
        p = p->next;
    }
}

void insertAtbegining() {
    printf("\nEnter data: ");
    temp = (node*)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
}

void insert_at_location() {
    printf("\nEnter position to insert:");
    int pos;
    scanf("%d", &pos);
    temp = (node*)malloc(sizeof(node));
    p = head;
    for (int i = 1; i < pos; i++) {
        p = p->next;
    }
    printf("\nEnter data");
    scanf("%d", &temp->data);
    temp->next = p->next;
    p->next = temp;
    temp->prev = p;
}

void insert_at_end() {
    printf("Enter data");
    temp = (node*)malloc(sizeof(node));
    scanf("%d", &temp->data);
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
    
}

void print() {
    p = head;
    printf("\nThe list is:-");
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void delete_at_start() {
    if (head != NULL) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
}

void delete_at_end() {
    if (head != NULL) {
        p = head;
        while (p->next != NULL) {
            temp = p;
            p = p->next;
        }
        if (temp != NULL) {
            temp->next = NULL;
        }
    }
}

int main() {
    int ch;
    while(1)
    {
        printf("\n----------Menu----------\n1)Create list \n2)Insert at Beginning\n3)Insert at a location\n4)Insert at End\n5)Delete starting node\n6)Delete end node\n7)Print list\n8)Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            create_list();
            break;
        case 2:
            insertAtbegining();
            break;
        case 3:
            insert_at_location();
            break;
        case 4:
            insert_at_end();
            break;
        case 5:
            delete_at_start();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            print();
            break;
        case 8:
            printf("Program ended.");
            exit(0);
        default:
            printf("Wrong choice");
            break;
        }
    }
    return 0;
}