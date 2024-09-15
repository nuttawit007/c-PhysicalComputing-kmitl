#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char *str = (char *)malloc(100 * sizeof(char));
    char check;
    scanf("%[^\n]s", str);
    char *ptr = str;
    int lower = 0, upper = 0, digit = 0;
    while (*ptr){
        check = *(ptr);
        if (isdigit(check)){
            digit += 1;
        } else if (islower(check)){
            lower += 1;
        } else if (isupper(check)){
            upper += 1;
        }
        ptr++;
    }
    printf("Lowercase letters: %d\nUppercase letters: %d\nDigits: %d", lower, upper, digit);
    free(str);
    return 0;
}
