#include<stdio.h>

int main(){
    float bottom, height;
    while(scanf("%f%f", &bottom, &height) != EOF){
        float ans = bottom*height/2;
        printf("%.1f\n", ans);
    }

    return 0;
}

