#include<stdio.h>

int main(){
    int input;
    double ans;
    while(scanf("%d", &input) != EOF){
        ans = input*1.6;
        printf("%.1f\n", ans);
    }

    return 0;
}
