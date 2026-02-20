#include <stdio.h>
int sum(int a[], int n){
    if (n==0) {
     return 0;
    }
    else{
        return a[n-1] + sum(a, n-1);
    }
}
int main(){
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Sum of Array is: %d",sum(a,n));
    return 0;
}