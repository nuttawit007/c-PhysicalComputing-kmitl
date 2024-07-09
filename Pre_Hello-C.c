#include <stdio.h>

int main() {
    int id;
    char name[100];

    // รับข้อมูล ID จากผู้ใช้
    scanf("%d\n", &id);
    // รับข้อมูลชื่อจากผู้ใช้ โดยไม่รับ newline (\n)
    scanf("%[^\n]", name);

    printf("Hello! My name is %s, %d", name, id);
    return 0;
}