#include <stdio.h>

int main () {
    char letter;
    scanf("%c", &letter);

    if (letter >= 'A' && letter <= 'Z') {
        letter += 32;
        printf("%c", letter);
    } else if (letter >= 'a' && letter <= 'z') {
        letter -= 32;
        printf("%c", letter);
    } else {
        printf("error");
    };

    return 0;
}