#include <stdio.h>

int main() {
    int a1[100], n, i, element, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);

    printf("Enter position(i) to insert : ");
    scanf("%d", &i);

    if(i < 1 || i > n + 1) {
        printf("Invalid position for insertion\n");
    }
    for(j = n; j >= i; j--) {
        a1[j] = a1[j - 1];
    }
    a1[i-1] = element;
    n++;
    printf("Array after insertion: \n");
    for (j=0; j<n; j++) {
        printf("%d ", a1[j]);
    }
    printf("\n");
    printf("Enter position(j) to delete : ");
    scanf("%d", &j);

    if(j < 1 || j > n + 1) {
        printf("Invalid position for delete\n");
    }
    for(i = j - 1; i < n - 1; i++) {
        a1[i] = a1[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a1[i]);
    }

    return 0;
}