
#include <stdio.h>
#include <math.h>

int main() {
    float price, diameter, height;
    scanf("%f\n%f\n%f", &price, &diameter, &height);

    float volume = height*M_PI*((diameter/2)*(diameter/2));
    float perprice = price/volume;

    printf("Volume : %.2fml\n", volume);
    printf("Baht/ml : %.4f", perprice);
    return 0;
}