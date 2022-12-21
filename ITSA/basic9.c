#include<stdio.h>

int main(){
    int n, sum=0;
    while(scanf("%d", &n) !=EOF){
        for(int i=1; i<=n; i++){
            if(i%3 == 0){
                sum += i;
            }
        }
        printf("%d\n", sum);
        sum=0;
    }
    return 0;
}
