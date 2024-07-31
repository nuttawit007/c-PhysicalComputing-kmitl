#include <stdio.h>
 
int main(){
    int number, tmp = 0;
    scanf("%d", &number);
    while (1){
        if (number > 0){
            printf("%d ", number);
            number--;
        } else if (number < 0){
            printf("%d ", number);
            number++;
        }
        if (number == 0){
            printf("%d ", number);
            break;
        }
    }
    return 0;
}