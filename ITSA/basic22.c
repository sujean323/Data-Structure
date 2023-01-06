//圈圈叉叉
#include<stdio.h>

int main(){
    int table[3][3], ans=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &table[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            //vertical
            if(table[0][j]==table[1][j] && table[1][j]==table[2][j])
                ans++;
            //horizontal
            else if(table[i][0]==table[i][1] && table[i][1]==table[i][2])
                ans++;
            //cross
            else if(table[0][0]==table[1][1] && table[1][1]==table[2][2])
                ans++;
            else if(table[2][0]==table[1][1] && table[1][1]==table[0][2])
                ans++;
        }
    }
    if(ans!=0) printf("True\n");
    else printf("False\n");

    return 0;
}
