#include <stdio.h>

#define MAX 100
#define LEN 50

char stack[MAX][LEN];
int top = -1;

int isEqual(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }

    if (a[i] == '\0' && b[i] == '\0')
        return 1;
    else
        return 0;
}

void copyStr(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void push(char page[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    if (top != -1 && isEqual(stack[top], page)) {
        printf("Same page entered. Not added again.\n");
        return;
    }

    top++;
    copyStr(stack[top], page);
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
        printf("\nEnter page name (or BACK / EXIT): ");
        scanf("%s", input);

        if (isEqual(input, "EXIT")) {
            break;
        }
        else if (isEqual(input, "BACK")) {
            pop();
        }
        else {
            push(input);
        }

        displayCurrent();
        displayHistory();
    }

    return 0;
}