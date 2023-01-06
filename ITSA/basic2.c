//英哩轉公里
#include<stdio.h>

int main(){
    int input;
    double ans;
    while(scanf("%d", &input) != EOF){
        ans = input*1.6; //1 英哩= 1.6 公里
        printf("%.1f\n", ans);
    }

    return 0;
}
