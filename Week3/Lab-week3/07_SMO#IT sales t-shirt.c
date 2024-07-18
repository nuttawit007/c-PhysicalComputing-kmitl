#include <stdio.h>

int main(){
    float price, percent, amount;

    scanf("%f\n%f\n%f", &price, &percent, &amount);
    float newprice = price - (price*(percent/100));
    float total = newprice*amount;
    printf("%.2f", total);
    return 0;
}