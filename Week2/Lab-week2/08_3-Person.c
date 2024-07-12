// #include <stdio.h>

// int main() {
//     char fname1[31], sname1[31], person2[61], person3[61];
//     scanf("%s", fname1);
//     scanf("%s\n", sname1);
//     scanf("%[^\n]\n", person2);
//     scanf("%[^\n]", person3);

//     printf("Person 1: %s %s\n", fname1, sname1);
//     printf("Person 2: %s\n", person2);
//     printf("Person 3: %s", person3);
//     return 0;
// }

#include<stdio.h>
 
int main() {
    char f_name[30], l_name[30];
    char f_person2[30], l_person2[30];
    char f_person3[30], l_person3[30];
    scanf("%s", f_name);
    scanf("%s", l_name);
    scanf("%s %s", f_person2, l_person2);
    scanf("%s %s", f_person3, l_person3);
    printf("Person 1: %s %s\n", f_name, l_name);
    printf("Person 2: %s %s\n", f_person2, l_person2);
    printf("Person 3: %s %s\n", f_person3, l_person3);
    return 0;
}