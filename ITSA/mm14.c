#include<stdio.h>

int main(){
    int n, day, hour, min, sec;
    while(scanf("%d", &n) != EOF){
        day = n/86400;
        hour = (n%86400)/3600;
        min = (n%3600)/60;
        sec = n%60;
        printf("%d days\n%d hours\n%d minutes\n%d seconds\n", day, hour, min, sec);
    }

    return 0;
}

