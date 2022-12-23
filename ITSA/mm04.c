#include<stdio.h>

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        if(b==0) break;
        printf("%d+%d=%d\n", a, b, a+b);
        printf("%d*%d=%d\n", a, b, a*b);
        printf("%d-%d=%d\n", a, b, a-b);
        int r = a%b;
        if(r>=0)
            printf("%d/%d=%d...%d\n", a, b, a/b, r);
        else{
            int tmp = a/b;
            if(tmp<0) tmp--;
            else tmp++;
            r = a-b*tmp;
            printf("%d/%d=%d...%d\n", a, b, tmp, r);
        }
    }

    return 0;
}

