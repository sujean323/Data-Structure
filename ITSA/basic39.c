#include<stdio.h>

int main(){
    int n, l, r, s, sum;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &l, &r, &s);
        sum = l+r+s;
        //method1
        if(l>=60 && r>=60 && s>=60) printf("P\n");
        //method2
        //1 fail & sum 220
        else if(l<60 && r>=60 && s>=60 && sum>=220) printf("P\n");
        else if(l>=60 && r<60 && s>=60 && sum>=220) printf("P\n");
        else if(l>=60 && r>=60 && s<60 && sum>=220) printf("P\n");
        //1 fail & sum 220
        else if(l<60 && r>=60 && s>=60 && sum<220) printf("M\n");
        else if(l>=60 && r<60 && s>=60 && sum<220) printf("M\n");
        else if(l>=60 && r>=60 && s<60 && sum<220) printf("M\n");
        //2 fail & 1 80
        else if(l>=80 && r<60 && s<60) printf("M\n");
        else if(l<60 && r>=80 && s<60) printf("M\n");
        else if(l<60 && r<60 && s>=80) printf("M\n");
        //else
        else printf("F\n");
    }

    return 0;
}
