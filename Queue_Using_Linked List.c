#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

void sanchit_enqueue(int value) {

    if (count == MAX) {
        printf("Queue Overflow \n");
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    count++;
}

void sanchit_dequeue() {

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    count--;
}

void sanchit_display() {

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                sanchit_enqueue(value);
                break;
            case 2:
                sanchit_dequeue();
                break;
            case 3:
                sanchit_display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}