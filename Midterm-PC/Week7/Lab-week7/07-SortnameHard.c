#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(char *str1, char *str2) {
    char temp[60];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void bubbleSort(char arr[][60], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char name_arr[n][60];
    char name[60];
    for (int i = 0; i < n; i++){
        if (i == 0){
            scanf("\n%[^\n]", name);
        } else {
            scanf("\n%[^\n]", name);
        }
        for (int j = 0; j < strlen(name); j++){
            if (j == 0){
                name[j] = toupper(name[j]);
            } else if (name[j] == ' '){
                name[j+1] = toupper(name[j+1]);
            } else if (name[j-1] == ' '){
                continue;
            } else {
                name[j] = tolower(name[j]);
            }
        }
        strcpy(name_arr[i], name);
    }

    bubbleSort(name_arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", name_arr[i]);
    }
    return 0;
}