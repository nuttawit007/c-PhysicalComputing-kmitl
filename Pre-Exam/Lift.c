#include <stdio.h>
#include <stdbool.h>

int main() {
    //Define
    int amount, age_re = 12;
    double lift_weight;
    bool pass_re = false;
    scanf("%d\n%lf", &amount, &lift_weight);

    // Lift empty people
    if (amount == 0){ pass_re = true; }

    // Input
    int age[amount];
    double weight[amount], total_weight = 0;


    for (int i = 0; i < amount; i++) {
        scanf("%d", &age[i]);
        scanf("%lf", &weight[i]);
        if (age[i] >= age_re) {
            pass_re = true;
        }
        total_weight += weight[i];
    }
    (pass_re && (lift_weight >= total_weight)) ? printf("Safe") : printf("Not Safe");
}