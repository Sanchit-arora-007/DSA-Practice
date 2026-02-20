#include <stdio.h>
struct Student {
    char name[50];
    int rollNo;
    float marks;
    char grade;
};
int main() {
    struct Student s;
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    printf("Enter grade: ");
    scanf(" %c", &s.grade);
    printf("\n--- Student Details ---\n");
    printf("Name      : %s\n", s.name);
    printf("Roll No   : %d\n", s.rollNo);
    printf("Marks     : %.2f\n", s.marks);
    printf("Grade     : %c\n", s.grade);
    return 0;
}
