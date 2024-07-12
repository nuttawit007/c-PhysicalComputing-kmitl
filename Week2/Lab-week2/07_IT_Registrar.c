#include <stdio.h>

int main() {
    char name[31], surname[31], stdId[9];
    int day, month, year;
    float gpa;

    scanf("%30s", name);
    scanf("%30s", surname);
    scanf("%8s", stdId);
    scanf("%d/%d/%d", &day, &month, &year);
    scanf("%f", &gpa);

    printf("Fullname: %s %s\n", name, surname);
    printf("ID: %s\n", stdId);
    printf("DOB: %02d-%02d-%04d\n",day, month, year);
    printf("GPA: %.2f\n", gpa);
    return 0;
}
