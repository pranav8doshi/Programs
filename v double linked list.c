#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create()
{
    int n, i, x;
    node *head, *p;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    head = (node *)malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d", &x);
    head->data = x;
    head->next = NULL;
    p = head;
    for (i = 1; i < n; i++)
    {
        p->next = (node *)malloc(sizeof(node));
        printf("Enter data part: ");
        scanf("%d", &x);
        p->data = x;
        p->next = NULL;
    }
    return head;
}

void display(node *head)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        printf("<-%d->", p->data);
        p = p->next;
    }
}

int count(node *head)
{
    int cnt = 0;
    node *p;
    p = head;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

node *insert_b(node *head)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d", &p->data);
    p->next = head;
    head = p;
    return head;
}

node *insert_e(node *head)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    printf("ENter data : ");
    scanf("%d", &p->data);
    p->next = NULL;
    q = head;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    return head;
}

node *insert_i(node *head)
{
    node *p, *q;
    int key;
    p = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    q = head;
    printf("Enter key: ");
    scanf("%d", &key);
    while (q->data != key)
    {
        if (q->next == NULL)
        {
            printf("key not found");
            return head;
        }
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return head;
}

node *delete_b(node *head)
{
    node *p;

    if (head == NULL)
        printf("LL is empty  ");
    else if (head->next == NULL)
    {
        p = head;
        head = NULL;
        free(p);
        printf("LL is empty now");
    }
    else
    {
        p = head;
        head = head->next;
        free(p);
    }
    return head;
}

node *delete_e(node *head)
{
    node *p, *q;
    if (head == NULL)
        printf("LL is empty");
    else if (head->next == NULL)
    {
        p = head;
        head = NULL;
        free(p);
        printf("LL is empty now");
    }
    else
    {
        q = head;
        while (q->next->next != NULL)
            q = q->next;
        p = q->next;
        q->next = NULL;
    }
    return head;
}

node *delete_(node *head)
{
    node *p, *q;
    int key;
    printf("ENter element to be deleted: ");
    scanf("%d", &key);
    if (head == NULL)
        printf("LL is empty");
    else if (head->next == NULL)
    {
        if (key == head->data)
        {
            p = head;
            free(p);
            head = NULL;
        }
        else
            printf("key not found");
    }
    else
    {
        if (key == head->data)
        {
            p = head;
            head = head->next;
            free(p);
        }
        else
        {
            q = head;
            while (q->next->data != key)
            {
                if (q->next->next == NULL)
                {
                    printf("Key not found");
                    return head;
                }
                q = q->next;
            }
            p = q->next;
            q->next = p->next;
            free(p);
        }
    }
    return head;
}

int main()
{
    node N;
    int n, x, y;
    do
    {
        printf("\n----------MENU--------\n");
        printf("\n 1.create \n 2.diplay\n3.count\n4.insert \n 5. delete  \n Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create(&N);

        case 2:
            display(&N);

        case 3:
            count(&N);

        case 4:
        {
            printf("\n 1Insert at begining \n2.Insert at middle \n 3.insert at end");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                insert_b(&N);

            case 2:
                insert_e(&N);

            case 3:
                insert_i(&N);
            }
        }

        case 5:
        {
            printf("\n 1.delete at beginign \n2.delete at end \n 3.delete at end \n ");
            scanf("%d", &y);
            switch (y)
            {
            case 1:
                delete_b(&N);

            case 2:
                delete_e(&N);

            case 3:
                delete_(&N);
            }
        }
        }
    } while (n <= 9);
}