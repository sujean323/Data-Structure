#include<stdio.h>

int main(){
    int in[6], out[6], k=5;
    for(int i=0; i<6; i++)
        scanf("%d", &in[i]);
    for(int i=0; i<6; i++){
        out[k] = in[i];
        k--;
    }
    for(int i=0; i<6; i++){
        if(i!=5) printf("%d ", out[i]);
        else printf("%d\n", out[i]);
    }

    return 0;
}
