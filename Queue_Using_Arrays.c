#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void sanchit_enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void sanchit_dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
}

void sanchit_display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
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
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}