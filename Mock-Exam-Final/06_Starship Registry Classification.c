#include <stdio.h>
#include <string.h>

int main() {
    int regis_id;
    scanf("%d", &regis_id);

    if (regis_id < 1000) {
        int last_digit = regis_id % 10;
        if (last_digit == 0) {
            printf("Command-class starship");
        } else if (last_digit == 5) {
            printf("Exploration-class starship");
        } else {
            printf("General-class starship");
        }
    } else if (regis_id >= 1000) {
        char regis_str[20];
        sprintf(regis_str, "%d", regis_id);
        int font_regis = regis_str[0] - '0';
        int last2_digit = regis_id % 100;
        char yarn[100] = "";
        if (font_regis % 2 == 0) {
            strcat(yarn, "Activity");
        } else if (font_regis % 2 != 0) {
            strcat(yarn, "Reserve");
        }
        if (last2_digit == 50 || last2_digit == 75) {
            strcat(yarn, " Starfleet Flagship");
        } else {
            strcat(yarn, " Standard-class starship");
        }
        printf("%s", yarn);
    }
}