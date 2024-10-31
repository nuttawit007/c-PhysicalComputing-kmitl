#include <stdio.h>
int main() {
    int book_id;
    scanf("%d", &book_id);

    if (book_id < 1000) {
        int last_digit = book_id % 10;
        if (last_digit == 0 || last_digit == 5) {
            printf("Science");
        } else if (last_digit == 3 || last_digit == 7) {
            printf("Literature");
        } else {
            printf("General Collection");
        }
    } else if (book_id >= 1000) {
        int last_digit = book_id % 100;
        if (last_digit % 4 == 0) {
            printf("Reference");
        } else if (last_digit == 11 || last_digit == 22 || last_digit == 33) {
            printf("History");
        } else {
            printf("Unclassified");
        }
    }
    return 0;
}