#include<stdio.h>

int main(){
    int n, a1, a2, a3, coin_1=0, coin_5=0, coin_50=0, mod;
    scanf("%d,%d,%d,%d", &n, &a1, &a2, &a3);
    int total = a1*15+ a2*20+ a3*30;
    int change = n-total;
    if(change<0) printf("0\n");
    else{
        while(change){
            if(change>=50){
                change -= 50;
                coin_50++;
            }
            else if(change>=5 && change<50){
                change -= 5;
                coin_5++;
            }
            else if(change<5){
                coin_1 = change;
                change = 0;
            }
        }
        printf("%d,%d,%d\n", coin_1, coin_5, coin_50);
    }

    return 0;
}
