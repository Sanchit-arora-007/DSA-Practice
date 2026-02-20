#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void sanchit_print(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

void sanchit_insert_at_beginning(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    if(*head == NULL) {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while(temp->next != *head)
        temp = temp->next;

    new_node->next = *head;
    temp->next = new_node;
    *head = new_node;
}

void sanchit_insert_at_end(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    if(*head == NULL) {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while(temp->next != *head)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = *head;
}

void sanchit_delete_at_beginning(struct node** head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    struct node* last = *head;

    while(last->next != *head)
        last = last->next;

    *head = temp->next;
    last->next = *head;
    free(temp);
}

void sanchit_delete_at_end(struct node** head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    while(temp->next->next != *head)
        temp = temp->next;

    struct node* last = temp->next;
    temp->next = *head;
    free(last);
}

int sanchit_count_nodes(struct node* head) {
    if(head == NULL) return 0;

    int count = 0;
    struct node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while(temp != head);

    return count;
}

int main() {
    struct node* head = NULL;
    sanchit_insert_at_end(&head, 1);
    sanchit_insert_at_end(&head, 2);
    sanchit_insert_at_end(&head, 3);
    sanchit_print(head);
    sanchit_insert_at_beginning(&head, 0);
    sanchit_print(head);
    sanchit_delete_at_beginning(&head);
    sanchit_print(head);
    sanchit_delete_at_end(&head);
    sanchit_print(head);
    printf("Total nodes: %d\n", sanchit_count_nodes(head));
    return 0;
}
