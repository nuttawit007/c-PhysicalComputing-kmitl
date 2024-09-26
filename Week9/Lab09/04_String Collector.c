#include <stdio.h>
#include <stdlib.h>

int main() {
    char letter;
    char *str;

    while (1) {
        scanf("%c", &letter);     // Read an char from the user
        if (letter == '-')          // Stop if the user enters -
            break;
    }
}