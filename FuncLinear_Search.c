#include <stdio.h>

int sanchit(int n, float A[], float key) {
    int i, found = 0;

    for (i = 0; i < n; i++) {
        if (A[i] == key) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element is found at position: %d\n", i + 1);
    } else {
        printf("Element Not Found\n");
    }

    return 0;
}

int main() {
    int n, i;
    float arr[100], key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%f", &key);

    sanchit(n, arr, key);

    return 0;
}
