#include <stdio.h>

long modify_factorial (int start, int end) {
    long result = 1;
    for (int i = start; i > end; i--) {
        result *= i;
    }
    return result;
}

long calProb (int n, int m) {
    int stop = (n - m) > m ? (n - m) : m;
    long result = modify_factorial(n, stop) / modify_factorial(n - stop, 1);
    return result;
}

int main () {
    int num;
    scanf("%d", &num);
    int possible2 = (int) num/2;
    long prob = 0;
    for (int i = 0; i <= possible2; i++) {
        prob = (prob + calProb((num-(i*2))+i, i));
    }
    printf("method = %ld", prob);
}
