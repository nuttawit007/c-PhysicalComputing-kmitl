#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    char circle[26] = "ABXYPQRMNCEDKLJOSHTUFVZGWI";
    char text[200];
    scanf("%[^\n]", text);

    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < 26; j++){
            if (text[i] == '\0') {
                break;
            }
            if (toupper(text[i]) == circle[j]) {
                if (j + 5 < 26) {
                    if (islower(text[i])) {
                        text[i] = tolower(circle[j + 5]);
                    } else {
                        text[i] = circle[j+5];
                    };
                } else {
                    if (islower(text[i])) {
                        text[i] = tolower(circle[(j + 5) - 26]);
                    } else {
                        text[i] = circle[(j + 5) - 26];
                    }
                }
                break;
            }
        }
    }
    printf("%s", text);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char circle[27] = {'A', 'B', 'X', 'Y', 'P', 'Q', 'R', 'M', 'N', 'C', 'E', 'D', 'K', 'L', 'J', 'O', 'S', 'H', 'T', 'U', 'F', 'V', 'Z', 'G', 'W', 'I'}, sentences[200] = {};
    int position = 0;
    scanf("%[^\n]s", sentences);
    for(int i = 0; i <= strlen(sentences); i++){
        for(int j = 0; j < 26; j++){
            if (isspace(sentences[i])){
                printf(" ");
                break;
            }
            else if(toupper(sentences[i]) == circle[j]){
                if(j+5 > 25){
                    (islower(sentences[i])) ? printf("%c", tolower(circle[(j+5)-26])) : printf("%c", circle[(j+5)-26]);
                }
                else{
                    (islower(sentences[i])) ? printf("%c", tolower(circle[j+5])) : printf("%c", circle[j+5]);
                }
                break;
            }
        }
    }
    return 0;
}