#include <stdio.h>

int main() {
    double num1, num2;
    scanf("%lf,%lf", &num1, &num2);

    double sum, diff, multi, div;
    sum = num1 + num2;
    diff = num1 - num2;
    multi = num1 * num2;
    div = num1 / num2;

    printf("The sum of the given numbers : %lf\n", sum);
    printf("The difference of the given numbers : %lf\n", diff);
    printf("The product of the given numbers : %lf\n", multi);
    printf("The quotient of the given numbers : %lf", div);

    return 0;
}