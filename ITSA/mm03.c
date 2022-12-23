#include<stdio.h>

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int ans = a+b;
        printf("%d\n", ans);
    }

    return 0;
}

