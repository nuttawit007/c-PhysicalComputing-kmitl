#include <stdio.h>

int main() {
    double distance;
    scanf("%lf", &distance);

    if (distance > 58.855 || distance < 0) {
        printf("InValid");
    } else if (distance >= 0 && distance <= 5.032) {
        printf("Bangkok");
    } else if (distance > 5.032 && distance <= 35.477) {
        printf("Samut Prakarn");
    } else if (distance > 35.477 && distance <= 52.9) {
        printf("Chachoengsao");
    } else if (distance > 52.9 && distance <= 58.855){
        printf("Chon Buri");
    };

    return 0;

}