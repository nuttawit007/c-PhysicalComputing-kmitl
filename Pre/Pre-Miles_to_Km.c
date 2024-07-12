#include <stdio.h>

int main() {
    float mile, km;

    scanf("%f", &mile);
    km = mile * 1.60934;

    printf("%.2f", km);
    return 0;
}