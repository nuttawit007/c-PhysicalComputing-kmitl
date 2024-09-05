#include <stdio.h>

int main(){
    char number[5];
    scanf("%s", number);
    // number + 2 : pointer ชี้ตน. 3, %.2f : เอา 2 ตัวจากจุดเริ่มต้น number
    printf("%s%.2s", number + 2, number);
    return 0;
}