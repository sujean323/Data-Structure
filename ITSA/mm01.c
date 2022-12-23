#include<stdio.h>

int main(){
    float upper, lower, height;
    while(scanf("%f%f%f", &upper, &lower, &height) != EOF){
        float ans = (upper+lower)*height/2;
        printf("Trapezoid area:%.1f\n", ans);
    }

    return 0;
}
