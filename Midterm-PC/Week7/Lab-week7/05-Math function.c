#include <stdio.h>

double getValue();
double findMin(double number[], int size);
double findMax(double number[], int size);
double findAvg(double number[], int size);

int main () {
    int size;
    scanf("%d", &size);

    double number[size];
    for (int i = 0; i < size; i++) {
        number[i] = getValue();
    }

    double min, max, avg;
    min = findMin(number, size);
    max = findMax(number, size);
    avg = findAvg(number, size);

    printf("%d Values\n", size);
    printf("Min: %.3lf\n", min);
    printf("Max: %.3lf\n", max);
    printf("Avg: %.3lf", avg);

    return 0;
}

double getValue() {
    // input
    double value;
    scanf("%lf", &value);
    return value;
}

double findMin(double number[], int size) {
    // find min value
    double min = number[0];
    for (int i = 1; i < size; i++) {
        if (number[i] < min) {
            min = number[i];
        }
    }
    return min;
}

double findMax(double number[], int size) {
    // find Max value
    double max = number[0];
    for (int i = 1; i < size; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    return max;
}

double findAvg(double number[], int size) {
    // Avg value
    double avg = 0;
    for (int i = 0; i < size; i++) {
        avg += number[i];
    }
    return avg / size;
}