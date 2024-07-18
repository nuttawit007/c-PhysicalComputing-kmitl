#include <stdio.h>

int main() {
    float num1, num2, num3, num4;
    scanf("%f\n%f\n%f\n%f", &num1, &num2, &num3, &num4);

    float sum = num1 + num2 + num3 + num4;
    float avg = (num1 + num2 + num3 + num4) / 4;

    printf("Summation is %.2f\n", sum);
    printf("Average is %.3f", avg);

    return 0;
}