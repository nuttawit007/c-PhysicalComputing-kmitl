#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2, num3;
    scanf("%f %f %f", &num1, &num2, &num3);
    float sum = num1 + num2 + num3;
    float max_num = fmax(num1, fmax(num2, num3));
    float min_num = fmin(num1, fmin(num2, num3));
    printf("%.2f", sum - max_num - min_num);
    return 0;
}