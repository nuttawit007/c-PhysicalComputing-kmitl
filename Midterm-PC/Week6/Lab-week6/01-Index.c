#include <stdio.h>
#include <stdbool.h>
 
int main() {
    // Define
    int M[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[] = {1, 3, 9, 7, 11, 15, 19};
    int number;
    bool noAnswer = true;
    // input
    while (1){
        scanf("%d", &number);
        if (number > 0 && number < 21){
            break;
        }
    }
    // If number in M
    for (int i = 0; i < 8; i++) {
        if (number == M[i]) {
            printf("%d is in M at index [%d]", number, i);
            noAnswer = false;
        }
    }
    // If number in N
    for (int j = 0; j < 7; j++) {
        if (number == N[j]) {
            printf("%d is in N at index [%d]", number, j);
            noAnswer = false;
        }
    }
    // If number not in M & N
    if (noAnswer) {
        printf("%d is not in neither M nor N", number);
    }

    return 0;
}