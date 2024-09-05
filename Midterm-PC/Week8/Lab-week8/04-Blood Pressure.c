#include <stdio.h>

int main() {
    double sbp, dbp;
    scanf("%lf\n%lf", &sbp, &dbp);
    (sbp >= 140.0 || dbp >= 90.0) ? printf("Hypertension") : printf("Normal");
}