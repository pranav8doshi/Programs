SIMPLE QUEUE

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int data);
int dequeue(void);
void display(void);
int peek(void);
int isempty(void);

int queue[MAX];
int f = -1;
int r = -1;

int main() {
    int choice;
    int data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Peek element: %d\n", peek());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void enqueue(int data) {
    if (isempty()) {
        f = 0;
        r = 0;
        queue[f] = data; 
    } else if (f == 0 && r < MAX - 1) {
        r = r + 1;
        queue[r] = data;
    } else if (r == MAX - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    }
}

int dequeue(void) {
    if (isempty()) {
       
        return -1; 
    }

    int data = queue[f];
    f = f + 1;

    if (f > r) {
      
        f = -1;
        r = -1;
    }

    return data;
}

void display(void) {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int isempty(void) {
    if (f == -1 || f == r + 1) {
        return 1;  // Queue is empty
    } else {
        return 0;  // Queue is not empty
    }
}

int peek(void) {
    if (isempty()) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;  // Return an error value indicating empty queue
    }

    return queue[f];
}


2.Circular Queue :

#include<stdio.h>
#include<stdlib.h>
#define max 5

void enqueue(int data);
int dequeue(void);
int isempty(void);
int isfull(void);
void display(void);
int peek(void);

int f = -1;
int r = -1;
int queue[max];

int main() {
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                data = peek();
                if (data != -1) {
                    printf("Peek element: %d\n", data);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

void enqueue(int data) {
    if (isfull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (f == -1) {
        f = 0;
    }
    r = (r + 1) % max;
    queue[r] = data;
    printf("Enqueued element: %d\n", data);
}

int dequeue(void) {
    if (isempty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue[f];
    if (f == r) {
        f = -1;
        r = -1;
    } else {
        f = (f + 1) % max;
    }
    return data;
}

void display(void) {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = f;
    while (i != r) {
        printf("%d ", queue[i]);
        i = (i + 1) % max;
    }
    printf("%d\n", queue[r]);
}

int isempty(void) {
    if (f == -1 && r == -1) {
        return 1;  // Queue is empty
    } else {
        return 0;  // Queue is not empty
    }
}

int isfull(void) {
    if ((r + 1) % max == f) {
        return 1;  // Queue is full
    } else {
        return 0;  // Queue is not full
    }
}

int peek(void) {
    if (isempty()) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue[f];
}
3.Double ended Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int f = -1, r = -1;
void insert_front_end(int ele);
void insert_rear_end(int ele);
int delete_front_end();
int delete_rear_end();
void display();
int is_empty();
int is_full();

int deque_arr[MAX];

int main()
{
    int choice, ele;
    
    while (1)
    {
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be added at the front: ");
            scanf("%d", &ele);
            insert_front_end(ele);
            break;
        case 2:
            printf("Enter the element to be added at the rear: ");
            scanf("%d", &ele);
            insert_rear_end(ele);
            break;
        case 3:
            printf("Deleted element is %d\n", delete_front_end());
            break;
        case 4:
            printf("Deleted element is %d\n", delete_rear_end());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}

void insert_front_end(int ele)
{
    if (is_full())
    {
        printf("Queue overflow. Cannot insert at front.\n");
        return;
    }

    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else if (f == 0)
    {
        f = MAX - 1;
    }
    else
    {
        f = f - 1;
    }
    deque_arr[f] = ele;
}

void insert_rear_end(int ele)
{
    if (is_full())
    {
        printf("Queue overflow. Cannot insert at rear.\n");
        return;
    }

    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else if (r == MAX - 1)
    {
        r = 0;
    }
    else
    {
        r = r + 1;
    }
    deque_arr[r] = ele;
}

int delete_front_end()
{
    int ele;
    if (is_empty())
    {
        printf("Queue underflow. Cannot delete from front.\n");
        exit(1);
    }

    ele = deque_arr[f];
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        if (f == MAX - 1)
            f = 0;
        else
            f = f + 1;
    }
    return ele;
}

int delete_rear_end()
{
    int ele;
    if (is_empty())
    {
        printf("Queue underflow. Cannot delete from rear.\n");
        exit(1);
    }

    ele = deque_arr[r];
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        r = MAX - 1;
    }
    else
    {
        r = r - 1;
    }
    return ele;
}

int is_full()
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (f == -1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    i = f;
    if (f <= r)
    {
        while (i <= r)
        {
            printf("%d ", deque_arr[i]);
            i++;
        }
    }
    else
    {
        while (i <= MAX - 1)
        {
            printf("%d ", deque_arr[i]);
            i++;
        }
        i = 0;
        while (i <= r)
        {
            printf("%d ", deque_arr[i]);
            i++;
        }
    }
    printf("\n");
}












4. Linked List :
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *head);
struct node *insert_at_begin(struct node *head, int data);
struct node *insert_at_end(struct node *head, int data);
struct node *insert_at_position(struct node *head, int data);
struct node *delete_begin(struct node *head);

int main()
{
    struct node *head = NULL;
    int choice, pos, data;

    while (1)
    {
        printf("\nEnter 1 to add at the beginning\n");
        printf("Enter 2 to add at the end\n");
        printf("Enter 3 to add at a specific position\n");
        printf("Enter 4 to delete from the beginning\n");
        printf("Enter 5 to display the list\n");
        printf("Enter 6 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to add: ");
            scanf("%d", &data);
            head = insert_at_begin(head, data);
            break;
        case 2:
            printf("Enter the data to add: ");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            break;
        case 3:
            printf("Enter the data to add: ");
            scanf("%d", &data);
            head = insert_at_position(head, data);
            break;
        case 4:
            head = delete_begin(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

struct node *insert_at_begin(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = head;
    head = newNode;
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;

    return head;
}

struct node *insert_at_position(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("List is empty. Inserting at position is not possible.\n");
        return head;
    }

    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;

    if (pos == 1)
    {
        newNode->link = head;
        head = newNode;
        return head;
    }

    struct node *temp = head;
 int count = 1;

    while (temp != NULL && count < pos - 1)
    {
        temp = temp->link;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position. Insertion not possible.\n");
        return head;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

struct node *delete_begin(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    struct node *temp = head;
    head = head->link;
    free(temp);
return head;
}










5.Circular Linked List :
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *head);
struct node *insert_at_begin(struct node *head, int data);
struct node *insert_at_end(struct node *head, int data);
struct node *insert_at_position(struct node *head, int data, int pos);
struct node *delete_begin(struct node *head);

int main()
{
    struct node *head = NULL;

    while (1)
    {
        int choice, pos;
        int data;
        printf("\nEnter 1 to add at the beginning\nEnter 2 to add at the end\nEnter 3 to add at a specific position\nEnter 4 to delete from the beginning\nEnter 5 to display the list\nEnter 6 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to add at the beginning: ");
            scanf("%d", &data);
            head = insert_at_begin(head, data);
            break;
        case 2:
            printf("\nEnter the data to add at the end: ");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            break;
        case 3:
            printf("\nEnter the data to add: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            head = insert_at_position(head, data, pos);
            break;
        case 4:
            head = delete_begin(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    printf("List: ");
    do
    {
        printf("%d ", temp->info);
        temp = temp->link;
    } while (temp != head);

    printf("\n");
}

struct node *insert_at_begin(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;

    if (head == NULL)
    {
        newNode->link = newNode;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != head)
            temp = temp->link;

        newNode->link = head;
        temp->link = newNode;
        head = newNode;
    }

    return head;
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;

    if (head == NULL)
    {
        newNode->link = newNode;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != head)
            temp = temp->link;

        temp->link = newNode;
        newNode->link = head;
    }

    return head;
}

struct node *insert_at_position(struct node *head, int data, int pos)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;

    if (head == NULL)
    {
        if (pos == 1)
        {
            newNode->link = newNode;
            head = newNode;
        }
        else
        {            printf("Invalid position.\n");
        }
    }
    else
    {
        if (pos == 1)
        {
            struct node *temp = head;
            while (temp->link != head)
                temp = temp->link;

            newNode->link = head;
            temp->link = newNode;
            head = newNode;
        }
        else
        {
            struct node *temp = head;
            int count = 1;

            while (count < pos - 1 && temp->link != head)
            {
                temp = temp->link;
                count++;
            }

            if (count == pos - 1)
            {
                newNode->link = temp->link;
                temp->link = newNode;
            }
            else
            {
                printf("Invalid position.\n");
            }
        }
    }

    return head;
}

struct node *delete_begin(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct node *temp = head;

    if (head->link == head)
    {
        head = NULL;
    }
    else
    {
        struct node *lastNode = head;
        while (lastNode->link != head)
            lastNode = lastNode->link;

        head = head->link;
        lastNode->link = head;
    }

    free(temp);
    return head;
}




















6.SORTING :
1. INSERTION SORT
#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int arr[5];
  for(int i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}





2. SelectionSort
 #include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int arr[5] ;
    //{64, 25, 12, 22, 11};
  for(int i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    
    printArray(arr, n);
    return 0;
}

3. BubbleSort
#include <stdio.h> 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[5];
  for(int i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    
    printArray(arr, n);
    return 0;
}
          



4.quicksort
         #include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
  
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] < pivot) {

            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[5] ;
  for (int i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
    int N = sizeof(arr) / sizeof(arr[0]);
   
   
    quickSort(arr, 0, N - 1);
    
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}

7.Binary Search :
#include <stdio.h>  
#include<stdlib.h>
int binarySearch(int a[], int l, int h, int x)    
{    
    int m;    
    if(h>= l)     
    {        m = (l + h)/2;    

        if(a[m] == x)    
        {                 
            return m+1;    
        }    
              
        else if(a[m] < x)     
        {  
            return binarySearch(a, m+1, h, x);    
        }    
              
        else     
        {  
            return binarySearch(a, l, m-1, x);    
        }          
    }    
    return -1;     
}   
int main() {  
  int a[5];
  int x;
  for(int i=0;i<5;i++)
  {
    scanf("%d",&a[i]);
  }
  scanf("%d",&x);
  int n = sizeof(a) / sizeof(a[0]);
  int res = binarySearch(a, 0, n-1, x);  
  if (res == -1)  
  printf("\nelement not found");  
  else  
  printf("\nelement found at position %d", res);  
  return 0;  
}
7.merge sort 
#include <stdio.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // Merge the two subarrays into the original array
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[] if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[] if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2) {
        return; // Base case: an array with 0 or 1 element is already sorted
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Divide the array into two subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the two subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted subarrays
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[] = {9, 2, 5, 1, 7, 4, 6, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
} 
