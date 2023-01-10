#include<stdio.h>
#include<string.h> //strtok
#include<stdlib.h>

struct shape{
    int userID;
    int candidate[1000][2];
    int num; //#candidate
};
struct shape shapes[1000];

struct store{
    int userid;
    int x_long;
    int num_j;
};
struct store stores[1000];

//let min x be first
void sort_store(int sum){
    int tmp0, tmp1, tmp2;
    for(int i=0; i<sum; i++){
        for(int j=0; j<sum-i-1; j++){
            if(stores[j].x_long > stores[j+1].x_long){
                tmp0 = stores[j].userid;
                tmp1 = stores[j].x_long;
                tmp2 = stores[j].num_j;
                stores[j].userid = stores[j+1].userid;
                stores[j].x_long = stores[j+1].x_long;
                stores[j].num_j = stores[j+1].num_j;
                stores[j+1].userid = tmp0;
                stores[j+1].x_long = tmp1;
                stores[j+1].num_j = tmp2;
            }
        }
    }
}

void tetris(int x, int y, int users, int sum){
    int pos_y[sum], pos_x[sum]; //position
    int numAC=0; //#accepted users
    int id[sum];
    int tmp=0, k=0;
    int tmp_x[sum], tmp_y[sum];

    //initial judge condition variables
    for(int i=0; i<users; i++){
        for(int j=0; j<shapes[i].num; j++){
            stores[k].userid = shapes[i].userID;
            stores[k].x_long = shapes[i].candidate[j][1];
            stores[k].num_j = j;
            k++;
        }
    }

    //bobble sort
    sort_store(sum);

    //initial
    for(int i=0; i<sum; i++){
        pos_y[i] = 0;
        pos_x[i] = 0;
        tmp_x[i] = 0;
        tmp_y[i] = 0;
    }

    //put into the resource
    for(int i=0; i<k; i++){
        if((tmp + shapes[stores[i].userid].candidate[stores[i].num_j][1])>x || shapes[stores[i].userid].userID == -1)
            continue;
        else{
            pos_x[numAC] = tmp;
            tmp += shapes[stores[i].userid].candidate[stores[i].num_j][1];
            tmp_x[numAC] = shapes[stores[i].userid].candidate[stores[i].num_j][1];
            tmp_y[numAC] = shapes[stores[i].userid].candidate[stores[i].num_j][0];
            id[numAC] = shapes[stores[i].userid].userID;
            shapes[stores[i].userid].userID = -1;
            numAC++;
        }
    }

    //output
    printf("%d\n", numAC);
    for(int i=0; i<numAC; i++){
        printf("%d %dx%d %d %d\n", id[i], tmp_y[i], tmp_x[i], pos_y[i], pos_x[i]);
    }
}

int main(){
    int x, y; //resource
    int users; //number of users
    int sum=0;
    char str[1000];

     for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            //shapes[i].candidate[j][0] = 0x7FFFFFFF;
            //shapes[i].candidate[j][1] = 0x7FFFFFFF;
        }
     }

    //input
    scanf("%d %d %d", &y, &x, &users);
    for(int i=0; i<users; i++){
        scanf("%d", &shapes[i].userID);
        fgets(str, 1000, stdin);
        char* p = strtok(str, " ");
        //strtok
        int j = 0;
        while(p != NULL){
            sscanf(p, "%dx%d", &shapes[i].candidate[j][0], &shapes[i].candidate[j][1]);
            p = strtok(NULL, " ");
            if(shapes[i].candidate[j][0] <= y && shapes[i].candidate[j][1] <= x)
                j++;
            shapes[i].num = j;
            sum++;
        }
    }

    tetris(x, y, users, sum);

    return 0;
}



