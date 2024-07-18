#include <stdio.h>
#include <math.h> // gcc source.c -lm

int main() {
    double side1, side2, side3;

    scanf("%lf\n%lf", &side1, &side2);
    side3 = sqrt((side1*side1)+(side2*side2));

    printf("%.2lf", side3);

    return 0;
    // double >> %lf
}