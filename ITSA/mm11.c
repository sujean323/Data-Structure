#include<stdio.h>

int main(){
    int price, coin_10=0, coin_5=0, coin_1=0;
    while(scanf("%d", &price) != EOF){
        coin_10 = price/10;
        coin_5 = price%10/5;
        coin_1 = price%10%5;

        printf("NT10=%d\nNT5=%d\nNT1=%d\n", coin_10, coin_5, coin_1);
    }

    return 0;
}
