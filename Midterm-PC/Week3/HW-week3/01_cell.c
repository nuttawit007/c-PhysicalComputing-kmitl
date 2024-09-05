#include <stdio.h>

int main(){
    char txt[4];
    scanf("%s", txt);

    printf("*****\n");
    printf("*-*-*\n");
    printf("*%s*\n", txt);
    printf("*-*-*\n");
    printf("*****\n");

    return 0;
}