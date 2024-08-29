#include <stdio.h>
#include <math.h>

double degreeToRadius(double degree);
double findH(double u, double radius);

int main() {
    int degree, u;
    scanf("%d\n%d", &degree, &u);

    printf("theta (degree) : %d\n", degree);
    printf("u (m/s) : %d\n", u);
    printf("h (m) : %.4lf", findH((double) u, degreeToRadius((double) degree)));
}

double degreeToRadius(double degree){
    // sin in c use radius
    return (degree * M_PI) / 180.0;
}

double findH(double u, double radius){
    // find h in "h = (u^2 * sin^2) / 2g" by g = 9.81
    return (pow(u, 2) * pow(sin(radius), 2)) / (2*9.81);
}

