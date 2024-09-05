#include <stdio.h>
 
int main(){
    int number, tmp = 1;
    scanf("%d", &number);
    while (tmp <= number) {
        printf("%d ", tmp);
        tmp++;
    }
    return 0;
}