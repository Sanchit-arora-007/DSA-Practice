#include <stdio.h>
#include <stdlib.h>
int sap;
char C;
int countr=1;
struct node{
    int SAP;
    int room;
    char c[100];
    struct node* next;
};

void print(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->SAP);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_beginning(struct node** head, int SAP, int room, char c[100]){
    if (SAP==sap) {
        if (c == C) {
            countr++;
            return;
        }
    }
    else {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->SAP = SAP;
        new_node->next = *head;
        *head = new_node;
        SAP = sap;
        c = C;
    }
}

void insert_at_end(struct node** head, int SAP, int room, char c[100]){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->SAP = SAP;
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
void insert_at_index(struct node** head, int index, int SAP, int room, char c[100]){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->SAP = SAP;
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
void delete_at_beginning(struct node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);

}
void delete_at_end(struct node** head){
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
void delete_at_index(struct node** head, int index){
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

int count_nodes(struct node* head) {
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

    insert_at_end(&head, 5900, 511, 'Plumbing');
    if (C == 'Electricity') {
        insert_at_beginning(&head, 5100, 511, 'Electricity');
    }
    else {
        insert_at_end(&head, 5200, 511, 'Wifi');
    }
    print(head);
    insert_at_beginning(&head, 5100, 511, 'Electricity');
    printf("Invalid Complaints: %d\n", countr);
    printf("Valid Complaints: %d\n", count_nodes(head));
    return 0;
}