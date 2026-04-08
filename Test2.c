#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 50

char stack[MAX][LEN];
int top = -1;
void push(char page[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    if (top != -1 && strcmp(stack[top], page) == 0) {
        printf("Same page entered. Not added again.\n");
        return;
    }

    top++;
    strcpy(stack[top], page);
    printf("Visited: %s\n", page);
}

void pop() {
    if (top == -1) {
        printf("No pages to go back.\n");
        return;
    }

    printf("Going back from: %s\n", stack[top]);
    top--;
}

void displayHistory() {
    if (top == -1) {
        printf("No browsing history.\n");
        return;
    }

    printf("\nBrowsing History:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }
}

void displayCurrent() {
    if (top == -1) {
        printf("No current page.\n");
        return;
    }

    printf("\nCurrent Page: %s\n", stack[top]);
    printf("Total Pages: %d\n", top + 1);
}

int main() {
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

        displayCurrent();
        displayHistory();
    }

    return 0;
}