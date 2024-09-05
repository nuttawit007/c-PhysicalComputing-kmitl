#include <stdio.h>

int main() {
    char input1[30], input2[30], input3[30], input4[30];

    scanf("%s", input1);
    scanf("%s", input2);
    scanf("%s", input3);
    scanf("%s", input4);

    printf("String 1: %.3s\n", input1);
    printf("String 2: %.4s\n", input2);
    printf("String 3: %.5s\n", input3);
    printf("String 4: %.6s\n", input4);
    return 0;
}