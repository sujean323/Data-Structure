//求最大公因數
#include<stdio.h>

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        if(a>b){
            for(int i=b; i>=0; i--){
                if(b%i==0 && a%i==0){
                    printf("%d\n", i);
                    break;
                }
            }
        }
        else if(a<b){
            for(int i=0; i>=0; i--){
                if(a%i==0 && b%i==0){
                    printf("%d\n", i);
                    break;
                }
            }
        }
        else
            printf("%d\n", a);
    }


    return 0;
}
