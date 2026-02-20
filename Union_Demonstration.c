#include <stdio.h>
#include <string.h>
union Data {
    int i;
    float f;
    char str[20];
};
int main() {
    union Data d;
    printf("Size of union: %lu bytes\n\n", sizeof(d));
    d.i = 10;
    printf("After storing int:\n");
    printf("i = %d\n", d.i);
    d.f = 25.5;
    printf("\nAfter storing float:\n");
    printf("f = %.2f\n", d.f);
    strcpy(d.str, "Hello");
    printf("\nAfter storing string:\n");
    printf("str = %s\n", d.str);
    return 0;
}
