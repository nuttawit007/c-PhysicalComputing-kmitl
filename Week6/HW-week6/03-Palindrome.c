#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char text[100];
    scanf("%s", text);

    int len = strlen(text)-1;
    bool is_palindrome = true;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != text[len]) {
            is_palindrome = false;
            break;
        }
        len--;
    }

    (is_palindrome) ? printf("It is Palindrome.") : printf("It is not Palindrome.");
}