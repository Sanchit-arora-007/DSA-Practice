#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, found = 0;
    float *arr, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (float *)malloc(n * sizeof(float));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%f", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element found at position: %d\n", i + 1);
    } else {
        printf("Element not found!\n");
    }

    free(arr);

    return 0;
}
