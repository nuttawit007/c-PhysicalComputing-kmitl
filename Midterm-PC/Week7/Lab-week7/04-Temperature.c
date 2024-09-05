#include <stdio.h>
#include <ctype.h>

double celsiusToFarenheit(double celsius);
double farenheitToCelsius(double farenheit);
void printFarenheit(double farenheit);
void printCelsius(double celsius);

int main() {
    double temp;
    char unit;
    scanf("%lf %c", &temp, &unit);

    switch (tolower(unit)) {
        case 'c':
            printFarenheit(celsiusToFarenheit(temp));
            break;
        case 'f':
            printCelsius(farenheitToCelsius(temp));
            break;
    }
}

double celsiusToFarenheit(double celsius) {
    // change celsius to farenheit
    return celsius * 9 / 5 + 32;
}

double farenheitToCelsius(double farenheit) {
    // change farenheit to celsius
    return (farenheit - 32) * 5 / 9;
}

void printFarenheit(double farenheit){
    // printf farenheit
    printf("%.2lf f", farenheit);
}

void printCelsius(double celsius){
    // printf celsius
    printf("%.2lf c", celsius);
}