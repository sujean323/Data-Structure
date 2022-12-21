#include<stdio.h>

int main(){
    int a;
    float s=0, ns=0;
    scanf("%d", &a);
    if(a>700){
        s += (a-700)*5.63;
        ns += (a-700)*4.5;
        a = 700;
    }
    if(a>500){
        s += (a-500)*4.97;
        ns += (a-500)*4.01;
        a = 500;
    }
    if(a>330){
        s += (a-330)*4.39;
        ns += (a-330)*3.61;
        a = 330;
    }
    if(a>120){
        s += (a-120)*3.02;
        ns += (a-120)*2.68;
        a = 120;
    }
    s += a*2.1;
    ns += a*2.1;
    printf("Summer months:%.2lf\n", s);
    printf("Non-Summer months:%.2lf\n", ns);


    return 0;
}
