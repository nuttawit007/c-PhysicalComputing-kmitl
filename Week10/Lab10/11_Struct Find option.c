#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Information {
    char name[61];
    char surname[61];
    char sex[5];
    int age;
    char id[13];
    double gpa;
};
 
void bubbleSort(struct Information students[], int count, char* condition) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;
            if ((strcasecmp(condition, "name") == 0 && strcasecmp(students[j].name, students[j + 1].name) > 0) || (strcasecmp(condition, "surname") == 0 && 
            strcasecmp(students[j].surname, students[j + 1].surname) > 0) || (strcasecmp(condition, "id") == 0 && strcasecmp(students[j].id, students[j + 1].id) > 0)){
                swap = 1;
            } 
            if (swap) {
                struct Information temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
 
int main() {
    struct Information students[20];
    char check[14];
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s %d %s %lf", students[i].name, students[i].surname, students[i].sex, &students[i].age, students[i].id, &students[i].gpa);
    }
 
    scanf("%s", check);
    bubbleSort(students, 20, check);
 
    for (int i = 0; i < 20; i++) {
        if (strcmp(students[i].sex, "Male") == 0) {
            printf("Mr %c %s (%d) ID: %s GPA %.2lf\n", students[i].name[0], students[i].surname, students[i].age, students[i].id, students[i].gpa);
        } else {
            printf("Miss %c %s (%d) ID: %s GPA %.2lf\n", students[i].name[0], students[i].surname, students[i].age, students[i].id, students[i].gpa);
        }
    }
    return 0;
}