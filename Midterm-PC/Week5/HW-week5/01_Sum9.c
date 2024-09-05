#include <stdio.h>

int main() {
    int num, sum = 0;
    // while true
    while (1) {
        scanf("%d", &num);
        if (num == -9){
            break;
        } else {
            sum += num;
        }
    }
    printf("%d", sum);

    return 0;
}