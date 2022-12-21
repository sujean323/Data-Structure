#include<stdio.h>

int main(){
    int gender;
    float height, weight;
    while(scanf("%f%d", &height, &gender) != EOF){
        if(gender==1)
            weight = (height-80)*0.7;
        else if(gender==2)
            weight = (height-70)*0.6;
        printf("%.1f\n", weight);
    }

    return 0;
}
