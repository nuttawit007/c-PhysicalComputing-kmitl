#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentense[301], focus;
    int count = 0, position[301];

    scanf("%[^\n]", sentense);
    scanf("\n%c", &focus);

    for (int i = 0; i < strlen(sentense); i++) {
        if (sentense[i] == tolower(focus) || sentense[i] == toupper(focus)) {
            count++;
            position[count-1] = i+1; 
        }
    }

    if (count == 0){
        printf("Not found.");
    } else {
        printf("There is/are %d \"%c\" in the above sentences.\nPosition: ", count, focus);
        for (int j = 0; j < count-1; j++){
            printf("%d, ", position[j]);
        };
        printf("%d", position[count-1]);
    };
}