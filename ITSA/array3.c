#include<stdio.h>
#include<math.h>

int main(){
    int a[6], sum=0;
    for(int i=0; i<6; i++){
        scanf("%d", &a[i]);
        sum += a[i]*a[i]*a[i];
    }
    printf("%d\n", sum);

    return 0;
}
