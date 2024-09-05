#include <stdio.h>

int main() {
    float age, height, weight;

    int con1 = 0, con2 = 0, con3 = 0, con4 = 0;
    float avg_age = 0, avg_h = 0, avg_w = 0;

    for (int people = 1; people <= 50; people++) {
        scanf("%f %f %f", &age, &height, &weight);

        avg_age += age; avg_h += height; avg_w += weight;
        if ((age >= 20) && (height >= 160)) {
            con1++;
        } if ((age < 20) && ((height <= 180) || (weight >= 60))) {
            con2++;
        } if ((age >= 30) && ((weight >= 40) && (weight <= 80))) {
            con3++;
        } if ((age < 40) && ((weight < 85) || (height <= 200))) {
            con4++;
        };
    };
    printf("Age >= 20 and Height >= 160: %d\n", con1);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", con2);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", con3);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", con4);
    printf("Average Age: %.0f\n", (avg_age/50));
    printf("Average Height: %.2f\n", (avg_h/50));
    printf("Average Weight: %.2f", (avg_w/50));

    return 0;
}