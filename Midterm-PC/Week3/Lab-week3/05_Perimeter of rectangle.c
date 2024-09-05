#include <stdio.h>

int main() {
    double width, height;
    scanf("%lf\n%lf", &width, &height);
    double area = (width*2)+(height*2);
    printf("Perimeter of rectangle = %.4lf units", area);
    return 0;
}