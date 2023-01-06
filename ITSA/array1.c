//一維陣列反轉
#include<stdio.h>

int main(){
    int array[100];
    int k=0;

    while(scanf("%d", &array[k]) != EOF) k++;
    for(int i=k-1; i>=0; i--){
        if(i==0)
            printf("%d\n", array[i]);
        else
            printf("%d ", array[i]);
    }

    return 0;
}
