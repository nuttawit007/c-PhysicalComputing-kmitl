#include <stdio.h>

int main() {
    char word[100];
    scanf("%[^\n]", word);
    // นับ ข้อความใน array โดยไม่ใช้ strlen()
    int tmp = 0;
    while (word[tmp] != '\0') {
        tmp++;
    }
    // reverse array
    for (int i = tmp-1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    return 0;
}
