#include <stdio.h>
int main()
{
    int time, day, hour, minute, sec;
    scanf("%d", &time);
    day = time/86400;
    hour = (time%86400)/3600;
    minute = (time%3600)/60;
    sec = time%60;
    printf("%d s = %d d %d h %d m %d s", time, day, hour, minute, sec);
    return 0;
}