#include <stdio.h>
#include <ctype.h>

int main() {
    int index = 0, size_array, array_total[27] = {};
    char alphabet[2] = {}, array_alphabet[27] = {};
    scanf("%d", &size_array);
    // loop ตาม sixe_array
    for (int i = 0; i < size_array; i++) {
        scanf("%s", &alphabet[0]);
        for (int j = 0; j <= index; j++) {
            // ตัวอักษรเข้ามาครั้งแรก
            if (array_total[j] == 0) {
                array_total[j] = 1;
                array_alphabet[j] = tolower(alphabet[0]);
                index += 1;
                break;
            } else if (array_alphabet[j] == tolower(alphabet[0])) {
                array_total[j] += 1;
                break;
            }
        }
    }
    for (int k = 0; k < index; k++) {
        printf("%c: %d\n", array_alphabet[k], array_total[k]);
    }

    return 0;
}