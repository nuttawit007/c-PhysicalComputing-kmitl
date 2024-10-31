#include <stdio.h>
#include <math.h>
int paperUse(int size) {
    // ดูจากระยะห่างของขนาดกระดาษ
    return pow(2, size);
}

int main() {
    int p1, p2;
    scanf("A%d\nA%d", &p1, &p2);
    printf("%d\n", paperUse(p2-p1));
    return 0;
}