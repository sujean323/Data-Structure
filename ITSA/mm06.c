#include<stdio.h>
#include<math.h>

int main(){
    int d;
    while(scanf("%d", &d) != EOF){
        double ans = d*1.6;
        printf("%.1lf\n", ans);
    }

    return 0;
}

