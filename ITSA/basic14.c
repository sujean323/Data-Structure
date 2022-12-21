#include<stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int a, b=0, r;
        a = n;
        while(n){
            r = n%10;
            b = b*10+r;
            n /= 10;
        }
        if(a==b) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
