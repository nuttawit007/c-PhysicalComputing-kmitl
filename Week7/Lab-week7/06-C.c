#include <stdio.h>
#include <math.h>

void printSqrt(long x, long y);

int main() {
    long x, y;
    scanf("%ld %ld", &x, &y);
    printSqrt(x, y);
    return 0;
}

void printSqrt(long x, long y) {
    // print sqrt
    double c = sqrt(pow(x, 2) + pow(y, 2));
    printf("sqrt(%ld^2+%ld^2)=%.2lf", x, y, c);
}