#include <stdio.h>
#include <string.h>
#define MAX 100
#define LEN 50
char stack[MAX][LEN];
int top = -1;

void push(char page[]){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
    }
    if (top != -1 && strcmp(stack[top], page) == 0) {
        printf("Same page entered. Not added again.\n");
        return;
    }
    else {
        top++;
        strcpy(stack[top], page);
        printf("%s pushed to stack\n", page);
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    } else {
        printf("%s popped from stack\n", stack[top]);
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty\n");
    } else {
        printf("Top element is %s\n", stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    } else {
        printf("Browsing History: ");
        for(int i = top; i >= 0; i--){
            printf("%s ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    char input[LEN];

    while (1) {
        printf("Enter page name (or BACK / EXIT): ");
        scanf("%s", input);

        if (strcmp(input, "EXIT") == 0) {
            break;
        } else if (strcmp(input, "BACK") == 0) {
            pop();
        } else {
            push(input);
        }

        peek();
        display();
    }

    return 0;
}