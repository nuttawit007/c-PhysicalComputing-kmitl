#include <stdio.h>
#include <stdlib.h>
int main(){
    int num, m;
    scanf("%d\n%d\n", &num, &m);
    char *str = (char *)malloc(num * sizeof(char));
    scanf("%[^\n]s", str);
    char *ptr = str;
    while (*ptr){
        printf("%c", *ptr);
        ptr += m;
    }
    free(str);
    return 0;
}