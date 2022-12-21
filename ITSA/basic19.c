#include<stdio.h>

int main(){
    int n, s, d, ans=0;
    scanf("%d", &n);
    int time[30]={0};
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &d);
        while(s<d){
            time[s] += 1;
            s++;
        }
    }
    for(int i=0; i<30; i++){
        if(time[i]>ans)
            ans = time[i];
    }
    printf("%d\n", ans);

    return 0;
}
