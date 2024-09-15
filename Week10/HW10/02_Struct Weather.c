#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Weather {
    char outlook[9]; //outlook{overcast,sunny,rain}
    int temperature;
    int humidity;
    char wind; //wind{T,F}
}weather;
void playing_decision(struct Weather x);
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s %d %d %c", weather.outlook, &weather.temperature, &weather.humidity, &weather.wind);
        playing_decision(weather);
    }
    return 0;
}
void playing_decision(struct Weather x){
    if(strcmp(x.outlook,"overcast") == 0){
        printf("yes");
    }
    else if(strcmp(x.outlook,"rain") == 0){
        printf((x.wind == 'F') ? "yes" : "no");
    }
    else if(strcmp(x.outlook,"sunny") == 0){
        printf((x.humidity > 77.5) ? "no" : "yes");
    }
    else{
        printf("no");
    }
    printf("\n");
}