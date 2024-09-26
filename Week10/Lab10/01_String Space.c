#include<stdio.h>
 
int main() {
    char text[150];
    scanf("%[^\n]s", &text);
    for (int i = 0; i < 150; i++) {
        if (text[i] == '\0') {
            break;
        }
        else if (text[i] == ' ') {
            continue;
        }
        else {
            printf("%c", text[i]);
        }
    }
    return 0;
}