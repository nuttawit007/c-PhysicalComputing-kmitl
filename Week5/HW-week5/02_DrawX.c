#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    // draaw x
    for (int row = 0; row < n; row++) {
        // ตต 0 - ก่อนเลขที่ input
        for (int col = 0; col < n; col++){
            // แถว == คอ หรือ แถว + คอ == จำนวน-1
            if (row == col || row + col == n - 1) {
                printf("-");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}