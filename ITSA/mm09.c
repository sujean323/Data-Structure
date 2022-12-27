#include<stdio.h>
#include<math.h>

int main(){
    int i;
    while(scanf("%d", &i) != EOF){
        if(i>31)
            printf("Value of more than 31\n");
        else
            printf("%.0lf\n", pow(2,i));
    }

    return 0;
}


