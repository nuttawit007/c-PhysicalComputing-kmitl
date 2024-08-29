#include <stdio.h>
#include <math.h>

int main() {
    int amount;
    scanf("%d", &amount);

    double number[amount];

    for (int i = 0; i < amount; i++){
        scanf("%lf", &number[i]);
    }

    int check = 0;
    for (int j = 0; j < amount - 1 ; j++) {
        for (int k = j + 1; k < amount; k++) {
            if (number[j] > number[k]) {
                if(fmod(number[j], 1) != 0 || fmod(number[k], 1) != 0){
                    check++;
                }
                double copy = number[j];
                number[j] = number[k];
                number[k] = copy;
            }
        }
    }

    for (int i = 0; i < amount; i++){
        if (check != 0) { printf("%.2lf ", number[i]); }
    }
}