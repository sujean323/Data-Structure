#include<stdio.h>

int main(){
    int in_hr, in_min, out_hr, out_min, hr, min;
    scanf("%d %d\n%d %d", &in_hr, &in_min, &out_hr, &out_min);
    if(out_min-in_min<0){
        min = 60-in_min+out_min;
        hr = out_hr-in_hr-1;
    }
    else{
        min = out_min-in_min;
        hr = out_hr-in_hr;
    }
    int time;
    time = hr*60 + min;
    int cost =0;
    if(time<120) cost = (time/30)*30;
    else if(time>=120 && time<240){
        time -= 120;
        cost = 120+(time/30)*40;
    }
    else{
        time -= 240;
        cost = 120+160+(time/30)*60;
    }

    printf("%d\n", cost);


    return 0;
}
