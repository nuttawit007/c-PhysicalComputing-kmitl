#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * toCapitalize (char name[]) {
    int whiteSpace = 61;
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == ' ') {
            whiteSpace = i + 1;
        }
        if (i == 0 || i == whiteSpace) {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }
    return name;
}

int main () {
    char name[21][61] = {};
    for (int i = 0; i < 20; i++) {
        char student[61];
        scanf("%[^\n]%*c", student);

        strcpy(name[i], toCapitalize(student));
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20 - i; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }

    for (int i = 1; i < 21; i++) {
        printf("%s\n", name[i]);
    }
}