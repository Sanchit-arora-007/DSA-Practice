#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

void sanchit_print_forward(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sanchit_print_backward(struct node* head) {
    struct node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void sanchit_insert_at_beginning(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if(*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void sanchit_insert_at_end(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

void sanchit_insert_at_index(struct node** head, int index, int data) {
    if(index == 0) {
        sanchit_insert_at_beginning(head, data);
        return;
    }

    struct node* temp = *head;
    for(int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    new_node->next = temp->next;
    new_node->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

void sanchit_delete_at_beginning(struct node** head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;

    if(*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void sanchit_delete_at_end(struct node** head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    if(temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void sanchit_delete_at_index(struct node** head, int index) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(index == 0) {
        sanchit_delete_at_beginning(head);
        return;
    }

    struct node* temp = *head;
    for(int i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}
int sanchit_count_nodes(struct node* head) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}


int main() {
    struct node* head = NULL;
    sanchit_insert_at_end(&head, 1);
    sanchit_insert_at_end(&head, 2);
    sanchit_insert_at_end(&head, 3);
    sanchit_print_forward(head);
    sanchit_insert_at_beginning(&head, 0);
    sanchit_print_forward(head);
    sanchit_insert_at_index(&head, 2, 5);
    sanchit_print_forward(head);
    sanchit_delete_at_beginning(&head);
    sanchit_print_forward(head);
    sanchit_delete_at_end(&head);
    sanchit_print_forward(head);
    sanchit_delete_at_index(&head, 1);
    sanchit_print_forward(head);
    printf("Backward: ");
    sanchit_print_backward(head);
    printf("Total nodes: %d\n", sanchit_count_nodes(head));
    return 0;
}
