#include<stdio.h>

int main(){
    int n, flag = 0;
    while(scanf("%d", &n) != EOF){
        for(int i=2; i<n; i++){
            if(n%i == 0){
                flag=1;
                printf("NO\n");
                break;
            }
        }
        if(flag==0) printf("YES\n");
    }

    return 0;
}
