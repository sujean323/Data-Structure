#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 99999

//find parent
int find(int Nodes, int parent[Nodes], int i){
    if(parent[i] == -1) return i;
    return parent[i]=find(Nodes, parent, parent[i]);
}
//check no cycle than union
int uni(int Nodes, int parent[Nodes], int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}
//traverse MST using DFS
void DFS(int Nodes, int v, double MST[Nodes][Nodes], int visited[Nodes], int tour[Nodes], int *j){
    tour[*j] = v; //record node traversed by DFS
    visited[v] = 1; //mark the node as visited
    for(int i=0; i<Nodes; i++){
        //check if the nodes are connected by MST
        if(!visited[i] && MST[v][i]!=0){
            (*j)++;
            DFS(Nodes, i, MST, visited, tour, j);
        }
    }
}
//store the length of the edges in the tour
void store_edge(int Nodes, int tour[Nodes], double cost[Nodes][Nodes], double edge[Nodes], double x[Nodes], double y[Nodes]){
    double dx, dy, d;
    for(int i=0; i<Nodes-1; i++){
        dx = x[tour[i]]-x[tour[i+1]];
        dy = y[tour[i]]-y[tour[i+1]];
        d = sqrt(dx*dx + dy*dy);
        edge[i] = d;
    }
//    int i=0;
//    while(i+1 < Nodes){
//        tmpx = (x[tour[i]]-x[tour[i+1]])*(x[tour[i]]-x[tour[i+1]]);
//        tmpy = (y[tour[i]]-y[tour[i+1]])*(y[tour[i]]-y[tour[i+1]]);
//        d = sqrt(tmpx+tmpy);
//        edge[i] = d;
//        i++;
//    }
}
//Divide the tour when the path length is greater than B/2
void uavs(int B, int Nodes, int tour[Nodes], double edge[Nodes], double cost[Nodes][Nodes]){
    int uav = 1, flag[Nodes], uavID=0;
    double len = 0; //current path length
    memset(flag, 0, sizeof(flag));
    //for(int i=0; i<Nodes; i++) flag[i]=0;
    for(int i=0; i<Nodes; i++){
        len += edge[i];
        if(len > B/2){
            uav++;
            len = 0;
            flag[i] = 1; //divide point
        }
    }
    //print ans
    printf("%d\n", uav);
    int j=0;
    for(int i=0; i<Nodes; i++){
        if(j==i){
            printf("%d ", uavID);
            uavID++;
        }
        printf("%d ", tour[i]);
        if(flag[i]==1){
            j = i+1;
            printf("\n");
        }
    }
}

//use kruskal's algorithm to construct a MST
void kruskal(int B, int Nodes, double cost[Nodes][Nodes], int parent[Nodes], double x[Nodes], double y[Nodes]){
    double mincost=0, min, MST[Nodes][Nodes];
    int ne=0, u=0, v=0, tmpU=0, tmpV=0;
    //set MST null
    for(int i=0; i<Nodes; i++){
        for(int j=0; j<Nodes; j++){
            MST[i][j] = 0;
        }
    }

    while(ne < Nodes-1){
        min = MAX;
        //find minimum edge
        for(int i=0; i<Nodes; i++){
            for(int j=0; j<Nodes; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    tmpU = u = i;
                    tmpV = v = j;
                }
            }
        }
        u = find(Nodes, parent, u);
        v = find(Nodes, parent, v);
        if(uni(Nodes, parent, u, v)){
            ne++;
            //add to MST
            mincost += min;
            MST[tmpU][tmpV] = MST[tmpV][tmpU] = min;
        }
        cost[tmpU][tmpV] = cost[tmpV][tmpU]= MAX;
    }

    //traverse by DFS
    int visited[Nodes], tour[Nodes], j=0;
    double edge[Nodes];
    //initial
    for(int i=0; i<Nodes; i++){
        visited[i] = 0;
        tour[i] = 0;
        edge[i] = 0;
    }
    DFS(Nodes, 0, MST, visited, tour, &j);
    store_edge(Nodes, tour, cost, edge, x, y);
    uavs(B, Nodes, tour, edge, cost);
}

int main(){
    //input & declaration
    int Nodes, B, NodeID;
    scanf("%d%d", &Nodes, &B);
    double x[Nodes], y[Nodes]; //coordinate
    double cost[Nodes][Nodes], d, tmpX, tmpY;
    int parent[Nodes]; //link between nodes
    for(int i=0; i<Nodes; i++)
        scanf("%d %lf %lf", &NodeID, &x[i], &y[i]);

    //initial
    for(int i=0; i<Nodes; i++){
        for(int j=0; j<Nodes; j++) cost[i][j] = MAX;
    }
    for(int i=0; i<Nodes; i++)
        parent[i] = -1;

    //cost matrix
    for(int i=0; i<Nodes; i++){
        for(int j=0; j<Nodes; j++){
            if(i==j) continue;
            else{
                tmpX = (x[i]-x[j])*(x[i]-x[j]);
                tmpY = (y[i]-y[j])*(y[i]-y[j]);
                //path length between x&y
                d = sqrt(tmpX+tmpY);
                cost[i][j] = d;
                cost[j][i] = d;
            }
        }
    }
    //baseline algorithm
    kruskal(B, Nodes, cost, parent, x, y);

    return 0;
}


/*
10 10
0 0.31943890 2.29615086
1 1.22727638 2.82131700
2 3.11475237 0.10137054
3 3.33213435 0.71334089
4 6.85464191 0.62696129
5 7.36465772 2.01343701
6 8.14020191 2.09479811
7 8.93059113 1.88562411
8 9.20708976 3.03945723
9 9.55529399 8.33022108
*/

/*
10 10
0 3.81533266 2.46536132
1 4.23540479 2.01986895
2 4.41845563 5.53982301
3 4.70278850 2.65684219
4 4.98295144 7.29632965
5 5.03708488 7.24442443
6 5.31672492 4.15547228
7 6.10301105 5.03363240
8 8.38578546 5.53203228
9 8.42620680 2.74005778
*/

/*
10 10
0 0.34 5.42
1 0.91 1.03
2 2.67 1.42
3 2.69 5.06
4 4.25 5.72
5 4.55 4.20
6 5.19 5.04
7 6.27 8.22
8 6.98 0.41
9 8.93 7.43
*/

