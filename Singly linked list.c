#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void sanchit_print(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sanchit_insert_at_beginning(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void sanchit_insert_at_end(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void sanchit_insert_at_index(struct node** head, int index, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    if(index == 0){
        new_node->next = *head;
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    for(int i=0; temp != NULL && i<index-1; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Index out of bounds\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;

}
void sanchit_delete_at_beginning(struct node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);

}
void sanchit_delete_at_end(struct node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

}
void sanchit_delete_at_index(struct node** head, int index){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if(index == 0){
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node* temp = *head;
    for(int i=0; temp != NULL && i<index-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Index out of bounds\n");
        return;
    }
    struct node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);

}

int sanchit_count_nodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    struct node* head = NULL;
    sanchit_insert_at_end(&head, 1);
    sanchit_insert_at_end(&head, 2);
    sanchit_insert_at_end(&head, 3);
    sanchit_print(head);
    sanchit_insert_at_beginning(&head, 0);
    sanchit_print(head);
    sanchit_insert_at_index(&head, 2, 5);
    sanchit_print(head);
    sanchit_delete_at_beginning(&head);
    sanchit_print(head);
    sanchit_delete_at_end(&head);
    sanchit_print(head);
    sanchit_delete_at_index(&head, 1);
    printf(head);
    printf("sanchit_count_nodes: %d\n", sanchit_count_nodes(head));
    return 0;
}