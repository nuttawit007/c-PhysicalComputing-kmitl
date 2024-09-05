#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char * toConvert(char *fullname);
void printfCompareFullname(char *fullname1, char *fullname2);


int main() {
    char fullname1[101], fullname2[101];
    scanf("%[^\n]\n%[^\n]", fullname1, fullname2);

    printf("*** Results ***\n");
    printf("%s\n",toConvert(fullname1));
    printf("%s\n", toConvert(fullname2));
    printf("***************\n");
    printfCompareFullname(fullname1, fullname2);
}

char * toConvert(char *fullname){
    for (int i = 0; i < strlen(fullname) ; i++) {
        if (islower(fullname[i])) {
            fullname[i] = toupper(fullname[i]);
        } else {
            fullname[i] = tolower(fullname[i]);
        }
    }
    return fullname;
}

void printfCompareFullname(char *fullname1, char *fullname2) {
    bool issame = true;
    for (int i = 0; i < strlen(fullname1); i++) {
        if (tolower(fullname1[i]) != tolower(fullname2[i])) {
            issame = false;
            break;
        }
    }
    (issame) ? printf("Both strings are the same.") : printf("Both strings are not the same.");
}