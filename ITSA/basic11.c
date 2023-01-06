//矩陣反轉
#include<stdio.h>

int main(){
    int row, col;
    scanf("%d %d", &row, &col);
    int array[row][col];
    int ans[col][row];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &array[i][j]);
            ans[j][i] = array[i][j];
        }
    }
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            printf("%d", ans[i][j]);
            if(j != row-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

