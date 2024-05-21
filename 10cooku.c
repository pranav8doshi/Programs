#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define MAX_KICKS 5

typedef struct {
    int key;
    int value;
} Entry;

Entry table[TABLE_SIZE];

void init_table() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i].key = -1;  // Indicates an empty slot
    }
}

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return (key / TABLE_SIZE) % TABLE_SIZE;
}

void insert(int key, int value) {
    int idx1 = hash1(key);
    int idx2 = hash2(key);

    if (table[idx1].key == -1) {
        table[idx1].key = key;
        table[idx1].value = value;
    } else if (table[idx2].key == -1) {
        table[idx2].key = key;
        table[idx2].value = value;
    } else {
        // Evict existing key-value pairs using cuckoo hashing
        int idx = idx1;
        int kicks = 0;
        while (kicks < MAX_KICKS) {
            Entry temp = table[idx];
            table[idx] = (Entry){key, value};
            key = temp.key;
            value = temp.value;
            idx = (idx == idx1) ? hash2(key) : hash1(key);
            ++kicks;
            if (table[idx].key == -1) {
                table[idx].key = key;
                table[idx].value = value;
                return;
            }
        }
        // If maximum kicks reached, resize the table or handle the collision in some other way
        printf("Maximum kicks reached. Unable to insert (%d, %d)\n", key, value);
    }
}

void print_table() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i].key != -1) {
            printf("[%d] -> (%d, %d)\n", i, table[i].key, table[i].value);
        } else {
            printf("[%d] -> Empty\n", i);
        }
    }
}

int main() {
    init_table();
    int choice, key, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a key-value pair\n");
        printf("2. Print the hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                print_table();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
