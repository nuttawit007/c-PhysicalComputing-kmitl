#include <stdio.h>
#include <stdbool.h>

int main(){
    double M[3][3] = {};
    // input matrix 3x3
    for(int i = 0;i < 3; i++){
        scanf("%lf %lf %lf", &M[i][0], &M[i][1], &M[i][2]);
    }
    // check scalar
    double num1 = M[0][0], num2 =  M[1][1], num3 = M[2][2];
    bool other_block = M[0][1] == 0 && M[0][2] == 0 && M[1][0] == 0 && M[1][2] == 0 & M[2][0] == 0 && M[2][1] == 0;
    ((num1=num2=num3) && (other_block == true)) ? printf("This is a scalar matrix") : printf("This is not a scalar matrix");
    return 0;
}