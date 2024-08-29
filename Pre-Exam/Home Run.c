#include <stdio.h>

int main() {
    int amount;
    double homerun;
    scanf("%d\n%lf", &amount, &homerun);
    double distance[amount];
    int count = 0;

    for (int i = 0; i < amount; i++) {
        scanf("%lf", &distance[i]);
        if (distance[i] < homerun) {
            count += 1;
        }
    }

    printf("%d", count);
}