#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    char lower_letter[26] = "abxypqrmncedkljoshtufvzgwi";
    char upper_letter[26] = "ABXYPQRMNCEDKLJOSHTUFVZGWI";
    char text[200];
    scanf("%[^\n]", text);

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '\0') {
            continue;
        }
        //check upper or lower
        bool is_lower = (text[i] == tolower(text[i]));
        bool is_upper = (text[i] == toupper(text[i]));
        // printf("islower : %d", is_lower);
        // printf("isupper : %d\n", is_upper);
        if (is_lower) {
            for (int j = 0; j < 26; j++){
                if (text[i] == lower_letter[j]){
                    int shift = j - 5;
                    if (shift >= 0){
                        text[i] = lower_letter[shift];
                    } else {
                        shift = 26 - abs(shift);
                        text[i] = lower_letter[shift];
                    }
                    break;
                }
            }
        } else if (is_upper) {
            for (int j = 0; j < 26; j++){
                if (text[i] == upper_letter[j]){
                    int shift = j - 5;
                    if (shift >= 0){
                        text[i] = upper_letter[shift];
                    } else {
                        shift = 26 - abs(shift);
                        text[i] = upper_letter[shift];
                    }
                    break;
                }
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
                if(j-5 < 0){
                    (islower(sentences[i])) ? printf("%c", tolower(circle[26+(j-5)])) : printf("%c", circle[26+(j-5)]);
                }
                else{
                    (islower(sentences[i])) ? printf("%c", tolower(circle[j-5])) : printf("%c", circle[j-5]);
                }
                break;
            }
        }
    }
    return 0;
}