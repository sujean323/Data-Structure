#include<stdio.h>

int main(){
    int month, season;
    while(scanf("%d", &month) != EOF){
        if(month<=0 || month>12) continue;
        if(month>=3 && month<=5) printf("Spring\n");
        else if(month>=6 && month<=8) printf("Summer\n");
        else if(month>=9 && month<=11) printf("Autumn\n");
        else printf("Winter\n");
    }

    return 0;
}
