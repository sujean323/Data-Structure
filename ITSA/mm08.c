#include<stdio.h>
#include<math.h>

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        int ans = pow(a+b, 2);
        printf("%d\n", ans);
    }

    return 0;
}


