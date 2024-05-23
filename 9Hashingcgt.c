#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

Entry* hashTable[TABLE_SIZE];

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    unsigned int index = hash(key);
    Entry* newEntry = (Entry*) malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
    printf("Inserted (%d, %d) at index %d\n", key, value, index);
}

void delete(int key) {
    unsigned int index = hash(key);
    Entry* current = hashTable[index];
    Entry* previous = NULL;

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found\n", key);
        return;
    }

    if (previous == NULL) {
        hashTable[index] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Key %d deleted\n", key);
}

Entry* search(int key) {
    unsigned int index = hash(key);
    Entry* current = hashTable[index];

    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Entry* current = hashTable[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key, value;
    Entry* result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(key);
                if (result != NULL) {
                    printf("Found key %d with value %d\n", key, result->value);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
