#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void selectionSort(double arr[
], int n) {

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Find the minimum element in the remaining
        // unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first
        // element
        double temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    double value[num], me, cm, sd, sos, sum =0;
    for( int i = 0; i < num; i++){
        scanf("%lf", &value[i]);
        sum = sum + value[i];
    }
    me = sum/(sizeof(value)/sizeof(value[0]));
    selectionSort(value, (sizeof(value)/sizeof(value[0])));
    if (num % 2 == 0){
        cm = (value[num/2 - 1] + value[num/2]) / 2.0;
    }
    else{
        cm = value[num/2];
    }
    for (int i = 0; i < num; i++){
        sos += pow(value[i] - me, 2);
    }
    sd = sqrt(sos / num);
    printf("%.2lf \n%.2lf \n%.2lf", me, cm, sd);
    return 0;
}