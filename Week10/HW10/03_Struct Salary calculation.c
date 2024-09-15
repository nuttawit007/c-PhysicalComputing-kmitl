#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};
int main(){
    int n=0;
    char target[10];
    scanf("%d", &n);
    struct Record list[n];
    for(int i=0; i<n; i++) scanf("%s %s %ld %ld", list[i].id, list[i].name, &list[i].salary, &list[i].sales);
    scanf("%s", target);
    for(int i=0; i<=n; i++){
        if(i == n){
            printf("ID not found !!!");
        }
        if(strcmp(list[i].id, target) == 0){
            printf("%s\n%s\n%ld\n%.2lf\n%ld\n%.2lf", list[i].id, list[i].name, list[i].sales, list[i].sales * 0.02, list[i].salary, list[i].salary + (list[i].sales*0.02));
            break;
        }
    }
    return 0;
}