#include<stdio.h>
#include<math.h>

int main(){
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF){
        if((x*x+y*y) < 10000) printf("inside\n");
        else printf("outside\n");
    }

    return 0;
}
