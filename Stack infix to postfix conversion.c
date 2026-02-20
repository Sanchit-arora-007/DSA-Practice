#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter Infix: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
            push(infix[i]);
        }

        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else {
            while (top != -1 && prec(stack[top]) >= prec(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s", postfix);

    return 0;
}
