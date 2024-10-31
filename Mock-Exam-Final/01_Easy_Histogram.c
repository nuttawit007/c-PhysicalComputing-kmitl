#include <stdio.h>
#include <string.h>

int main() {
    // ประกาศตัวแปรสำหรับเก็บจำนวนครั้งของแต่ละตัวอักษร
    int count[128] = {0};  // รองรับอักขระจาก ASCII 0 - 127
    char text[100];

    // รับข้อความจากผู้ใช้
    scanf("%[^\n]", text);
    // นับจำนวนครั้งที่ตัวอักษรแต่ละตัวปรากฏ
    for (int i = 0; text[i] != '\0'; i++) {
        count[(int)text[i]]++;
    }

    // แสดงผลการนับ โดยเรียงลำดับ aA ถึง zZ
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[(int)c] > 0) {
            printf("%c = %d\n", c, count[(int)c]);
        }
        if (count[(int)(c - 32)] > 0) {  // ตัวอักษรพิมพ์ใหญ่ เช่น 'A'
            printf("%c = %d\n", c - 32, count[(int)(c - 32)]);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    char message[300];
    int *small = (int*)calloc(26, sizeof(int));
    int *big = (int*)calloc(26, sizeof(int));
    scanf(" %[^\n]s", message);
    for(int i = 0; message[i]; i++) { 
        if(message[i] >= 'a' && message[i] <= 'z')  *(small + (message[i] - 97)) += 1;
        else if(message[i] >= 'A' && message[i] <= 'Z') *(big + (message[i] - 65)) += 1;
    }
    for(int i = 0; i < 26; i++) {
        if(small[i] > 0) printf("%c = %d\n", 97 + i, small[i]);
        if(big[i] > 0) printf("%c = %d\n", 65 + i, big[i]);
    }
    free(small);
    free(big);
    return 0;
}

int main() {
    char message[300];
    int *small = (int*)calloc(26, sizeof(int));
    int *big = (int*)calloc(26, sizeof(int));
    scanf("%[^\n]s", message);
    for(int i = 0; message[i]; i++){
        if(message[i] >= 'a' && message[i] <= 'z') *(small + (message[i] - 97)) += 1;
        else if(message[i] >= 'A' && message[i] <= 'Z') *(big + (message[i] - 65)) += 1;
    }
    for(int i=0; i<26; i++){
        if(small[i] > 0) printf("%c = %d\n", 97 + i, small[i]);
        if(big[i] > 0) prinf("%c = %d\n", 65 + i, big[i]);
    }
    free(small);
    free(big);
    return 0;
}