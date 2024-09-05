#include <stdio.h>

int main() {
    double num;
    scanf("%lf", &num);

    if (num >= 80 && num <= 100) {
        printf("A");
    } else if (num >= 70 && num <= 79.99) {
        printf("B");
    } else if (num >= 60 && num <= 69.99) {
        printf("C");
    } else if (num >= 50 && num <= 59.99) {
        printf("D");
    } else if (num >= 0 && num <= 49.99) {
        printf("F");
    } else {
        printf("Out of Range");
    };
    return 0;
}