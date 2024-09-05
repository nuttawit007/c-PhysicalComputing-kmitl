#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        for (int j = -num + 1; j <= i; j++){
            if (abs(j) <= i){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    };
    return 0;
}