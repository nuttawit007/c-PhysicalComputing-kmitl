#include <stdio.h>

int getNum(void);
int sqr(int x);
int printOne(int x);

int main() {
// main
    int a;
    int b;
    a = getNum();
    b = sqr(a);
    printOne(b);

    return 0;
}

int getNum(void) {
// input number
    int numIn;
    scanf("%d", &numIn);

    return numIn;
}

int sqr(int x) {
// sqeare area
    return x * x;
}

int printOne(int x) {
    printf("The value is: %d\n", x);

    return 0;
}





