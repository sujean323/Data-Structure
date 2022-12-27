#include<stdio.h>

int main(){
    float c, f;
    while(scanf("%f", &c) != EOF){
        f = c*9/5+32;
        printf("%.1f\n", f);
    }

    return 0;
}
