#include <stdio.h>

void highest(int *num1, int *num2, int *num3, int *num4, int *num5) {
    int high_tmp = *num1;
    if (*num2 > high_tmp) high_tmp = *num2;
    if (*num3 > high_tmp) high_tmp = *num3;
    if (*num4 > high_tmp) high_tmp = *num4;
    if (*num5 > high_tmp) high_tmp = *num5;
    printf("MAX : %d", high_tmp);
};

void lowest(int *num1, int *num2, int *num3, int *num4, int *num5) {
    int low_tmp = *num1;
    if (*num2 < low_tmp) low_tmp = *num2;
    if (*num3 < low_tmp) low_tmp = *num3;
    if (*num4 < low_tmp) low_tmp = *num4;
    if (*num5 < low_tmp) low_tmp = *num5;
    printf("MIN : %d", low_tmp);
};

int main() {
    char ch1, ch2, ch3;
    int num1, num2, num3, num4, num5;
    scanf("%c%c%c", &ch1, &ch2, &ch3);
    scanf("%d\n%d\n%d\n%d\n%d", &num1, &num2, &num3, &num4, &num5);
    if (ch2 == 'A') {
        highest(&num1, &num2, &num3, &num4, &num5);
    } else if (ch2 == 'I') {
        lowest(&num1, &num2, &num3, &num4, &num5);
    }
};

//006
#include <stdio.h>
#include <stdlib.h>
int main() {
    char x,y;
    int num, top=0, low=0;
    scanf("M%c%c", &x, &y);
    scanf("%d", &num);
    top=num;
    low=num;
    scanf("%d", &num);
    if (num > top) top=num;
    if (num < low) low=num;
    scanf("%d", &num);
    if (num > top) top=num;
    if (num < low) low=num;
    scanf("%d", &num);
    if (num > top) top=num;
    if (num < low) low=num;
    scanf("%d", &num);    
    if (num > top) top=num;
    if (num < low) low=num;
    printf("%s : %d", (x == 'A') ? "MAX" : "MIN", (x == 'A') ? top : low);
    return 0;
}