#include <stdio.h>
int main() {
    int n, i, found=0;
    float arr[100], key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    printf("Enter the number to search\n");
    scanf("%f", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element is found at position: %d \n", i+1);
    }
    else {
        printf("Element Not Found \n");
    }
    return 0;
}