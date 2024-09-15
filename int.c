#include <stdio.h>

int main() {
    int arr_num[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr_num[i]);
    };

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_num[i]);
    };
    printf("%d", arr_num[2]);
    return 0;
}

// 1 2 3 4 ////////////////////////////////////////////////////////////////////////////////////////////////////5
