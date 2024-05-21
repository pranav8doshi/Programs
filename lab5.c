#include <stdio.h>
#define MAX 100
int array[MAX][MAX];
int queue[MAX];
int stack[MAX];
int top = -1;
int front = -1;
int rear = -1;
void push(int *a)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack[top] = *a;
}
int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    int a = stack[top];
    top = top - 1;
    return a;
}
void enqueue(int num)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full");
        return;
    }
    if (rear == -1)
    {
        front = rear = 0;
    }
    queue[rear] = num;
    rear = rear + 1;
}
int dequeue()
{
    if (rear == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    int value = queue[front];
    if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        front = front + 1;
    }
    return value;
}
void initialize(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            array[i][j] = 0;
        }
    }
}
void add_edge(int vertex1, int vertex2)
{
    array[vertex1][vertex2] = 1;
    array[vertex2][vertex1] = 1;
}
void print_array(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}
int empty_queue()
{
    if (rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BFS(int vertices)
{
    int visited[MAX], a;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    printf("Enter base vertex: ");
    scanf("%d", &a);
    printf("\n BFS traversal is:-");
    visited[a] = 1;
    enqueue(a);
    printf("%d\n", a);
    while (!empty_queue())
    {
        int node = dequeue();
        for (int j = 0; j < vertices; j++)
        {
            if (array[node][j] == 1 && visited[j] == 0)
            {
                enqueue(j);
                printf("%d\n", j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}
void DFS(int vertices)
{
    int visited[MAX], a;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    printf("Enter base vertex: "); //
    scanf("%d", &a);
    printf("\n DFS traversal is:-");
    visited[a] = 1;
    push(&a);
    while (!is_empty())
    {
        int b = pop();
        printf("%d  ", b);
        for (int i = 0; i < vertices; i++)
        {
            if (array[b][i] == 1 && visited[i] == 0)
            {
                push(&i); // Push index instead of array[b][i]
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int vertices, edges, vertex1, vertex2;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    initialize(vertices);
    for (int i = 0; i < edges; i++)
    {
        printf("Enter the vertices in which there is an edge: ");
        scanf("%d %d", &vertex1, &vertex2);
        add_edge(vertex1, vertex2);
    }
    print_array(vertices);
    int ans = 1, ch;
    do
    {
        printf("\nMenu\n\t1)BFS\n\t2)DFS\n\t3)Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            BFS(vertices);
            break;
        case 2:
            DFS(vertices);
            break;
        case 3:
            ans = 0;
            break;
        default:
            printf("\n wrong choice ");
        }
    } while (ans == 1);

    return 0;
}

