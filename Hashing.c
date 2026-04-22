#include <stdio.h>

#define SIZE 10

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    if (table[index] == -1) {
        table[index] = key;
        printf("Inserted %d at index %d\n", key, index);
    } else {
        printf("Collision occurred! Cannot insert %d\n", key);
    }
}

void search(int key) {
    int index = hashFunction(key);

    if (table[index] == key) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
}

void deleteKey(int key) {
    int index = hashFunction(key);

    if (table[index] == key) {
        table[index] = -1;
        printf("Element deleted\n");
    } else {
        printf("Element not found\n");
    }
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("%d --> EMPTY\n", i);
        else
            printf("%d --> %d\n", i, table[i]);
    }
}

int main() {
    int choice, key;

    init();

    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}