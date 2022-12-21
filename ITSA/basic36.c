#include<stdio.h>

int main(){
    int year;
    while(scanf("%d", &year) != EOF){
        if(year%400==0)
            printf("Bissextile Year\n");
        else if(year%100==0)
            printf("Common Year\n");
        else if(year%4==0)
            printf("Bissextile Year\n");
        else
            printf("Common Year\n");
    }

    return 0;
}
