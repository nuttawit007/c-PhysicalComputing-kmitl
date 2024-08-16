#include <stdio.h>

int main() {
    //Define matrix 3x3
    double M[3][3] = {};
    double N[3][3] = {};
    // input
    for(int i = 0; i < 6; i++) {
        (i < 3) ? scanf("%lf %lf %lf", &M[i][0], &M[i][1], &M[i][2]) : scanf("%lf %lf %lf", &N[i-3][0], &N[i-3][1], &N[i-3][2]);
    }

    printf("A x B\n");
    // Multiplication Mattrix 3x3
    for (int k = 0; k < 3; k++) {
        printf("%.02lf ", (M[k][0] * N[0][0]) + (M[k][1] * N[1][0]) + (M[k][2] * N[2][0]));
        printf("%.02lf ", (M[k][0] * N[0][1]) + (M[k][1] * N[1][1]) + (M[k][2] * N[2][1]));
        printf("%.02lf\n", (M[k][0] * N[0][2]) + (M[k][1] * N[1][2]) + (M[k][2] * N[2][2]));
    }
    return 0;
}