#include <stdio.h>

int main() {
    float price, percent, amount;
    scanf("%f\n%f\n%f", &price, &percent, &amount);
    float buy2_get1 = (amount*price) - ((int) (amount/3)*price);
    float discount = (price*amount) - (price * amount * (percent/100));
    if (buy2_get1 == discount) {
        printf("Discount %.f%%\n%.2f", percent, discount);
    } else if (buy2_get1 < discount){
        printf("Buy 2 Get 1\n%.2f", buy2_get1);
    } else if (discount < buy2_get1) {
        printf("Discount %.f%%\n%.2f", percent, discount);
    }
    return 0;
}