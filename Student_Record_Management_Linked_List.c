#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    float marks;
    struct student* next;
};
void sanchit_add_student(struct student** head, int roll, char name[], float marks) {
    struct student* new_node = (struct student*)malloc(sizeof(struct student));
    new_node->roll = roll;
    strcpy(new_node->name, name);
    new_node->marks = marks;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct student* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}
void sanchit_display_students(struct student* head) {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    struct student* temp = head;
    while (temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}
void sanchit_search_student(struct student* head, int roll) {
    struct student* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Record Found:\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}
void sanchit_delete_student(struct student** head, int roll) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct student* temp = *head;
    struct student* prev = NULL;

    if (temp->roll == roll) {
        *head = temp->next;
        free(temp);
        printf("Record deleted.\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Record deleted.\n");
}
void sanchit_update_marks(struct student* head, int roll, float new_marks) {
    struct student* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            temp->marks = new_marks;
            printf("Marks updated.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}
int main() {
    struct student* head = NULL;
    int choice, roll;
    char name[50];
    float marks;

    while (1) {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Marks\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll, Name, Marks: ");
                scanf("%d %s %f", &roll, name, &marks);
                sanchit_add_student(&head, roll, name, marks);
                break;

            case 2:
                sanchit_display_students(head);
                break;

            case 3:
                printf("Enter Roll to search: ");
                scanf("%d", &roll);
                sanchit_search_student(head, roll);
                break;

            case 4:
                printf("Enter Roll to delete: ");
                scanf("%d", &roll);
                sanchit_delete_student(&head, roll);
                break;

            case 5:
                printf("Enter Roll and New Marks: ");
                scanf("%d %f", &roll, &marks);
                sanchit_update_marks(head, roll, marks);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
