//最大值與最小值
#include<stdio.h>

int main(){
    double input[10], max, min;
    for(int i=0; i<10; i++){
        scanf("%lf", &input[i]);
    }
    max = min = input[0];
    for(int i=0; i<10; i++){
        if(input[i]>max) max = input[i];
        if(input[i]<min) min = input[i];
    }
    printf("maximum:%.2lf\n", max);
    printf("minimum:%.2lf\n", min);

    return 0;
}
