#include<stdio.h>

int main(){
    int m, d;
    scanf("%d %d", &m, &d);
    if((m==1 && d>=21) || (m==2 && d<=18)) printf("Aquarius\n");
    else if((m==2 && d>=19) || (m==3 && d<=20)) printf("Pisces\n");
    else if((m==3 && d>=21) || (m==4 && d<=20)) printf("Aries\n");
    else if((m==4 && d>=21) || (m==5 && d<=21)) printf("Taurus\n");
    else if((m==5 && d>=22) || (m==6 && d<=21)) printf("Gemini\n");
    else if((m==6 && d>=22) || (m==7 && d<=22)) printf("Cancer\n");
    else if((m==7 && d>=23) || (m==8 && d<=23)) printf("Leo\n");
    else if((m==8 && d>=24) || (m==9 && d<=23)) printf("Virgo\n");
    else if((m==9 && d>=24) || (m==10 && d<=23)) printf("Libra\n");
    else if((m==10 && d>=24) || (m==11 && d<=22)) printf("Scorpio\n");
    else if((m==11 && d>=23) || (m==12 && d<=21)) printf("Sagittarius\n");
    else if((m==12 && d>=22) || (m==1 && d<=20)) printf("Capricorn\n");

    return 0;
}
