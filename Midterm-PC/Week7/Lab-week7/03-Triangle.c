#include <stdio.h>
#include <math.h>

void perimeter(double a, double b, double c);
void area(double a, double b);

int main() {
    double a, b, c;
    scanf("%lf\n%lf", &a, &b);

    c = sqrt((pow(a, 2) + pow(b, 2)));
    perimeter(a, b, c);
    area(a, b);
    return 0;
}

void perimeter(double a, double b, double c) {
    printf("Perimeter: %.2lf\n", a + b + c);
}

void area(double a, double b) {
    printf("Area: %.2lf",  0.5 * a * b);
}
