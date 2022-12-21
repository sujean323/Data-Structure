#include<stdio.h>

int main(){
    float r;
    int n, p;
    while(scanf("%f%d%d", &r, &n, &p) != EOF){
        int ans=0;
        for(int i=0; i<n; i++){
            ans = (ans+p)*(1.0+r);
        }
        printf("%d\n", ans);
    }

    return 0;
}
