#include <stdio.h>

// int main() {
//     char string_array[5][20];

//     for (int i = 0; i < 5; i++){
//         scanf("%s", string_array[i]);
//     }

//     for (int i = 0; i < 5; i++){
//         printf("%s", string_array[i]);
//     }

// }

int main() {
    char txt;
    for (int i = 0; i < 5; i++) {
        scanf("%c", txt);
    }
}


void merge(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;

        merge(arr, left ,mid);
        merge(arr, mid+1, right);

        int n1 = mid - left + 1, n2 = right - mid;
        double  L[n1], R[n2];
        int i, j, k;
        for (i = 0; i < n1; i++) L[i] = arr[left+i];
        for (j = 0; j < n2; j++) R[j] = arr[mid+1+j];

        i=j=0;
        k = left;

        while(i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while( i < n1) arr[k++] = L[i++];
        while( j < n2) arr[k++] = R[j++];

    }
}
