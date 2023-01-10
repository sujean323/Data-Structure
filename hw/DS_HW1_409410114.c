#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITE 0x3f3f3f3f //10^9
#define n 600

int channel[n][n]; //°Ê
int graph[n][n]; //¤£°Ê
int tmp1[n][n]; //ans(final output)
int tmp2[n][n]; //dst->src(dijsktra's output)

void Dijkstra(int src, int dst, int qm[n], int chqme[n][n], int *Reqtmp, int ans[n][n], int Reqnum[], int num1){
	int dist[n];
	int parent[n], visit[n];
	int k, pre;
	int min, inf = 1000;
	int tmp[n];
	int count = 0;
	memset(tmp, 0, sizeof(tmp));

	//inital
	for(int i=0; i<n; i++){
        dist[i] = INFINITE;
        parent[i]=-1;
        visit[i] = 0;
    }
	dist[src] = 0;
	//DIJ
	for(int i=0; i<n; i++){
        //choose min
        min = inf;
		for(int j=0; j<n; j++){
			if((!visit[j]) && (dist[j]<min)){
				min = dist[j];
				k = j;
			}
		}
        visit[k] = 1;
        for(int j=0; j<n; j++){
            if((!visit[j]) && (graph[k][j]!=INFINITE) && (dist[j] >= dist[k]+1)){
                if(dist[j]==dist[k]+1){
                    if(parent[j] > k)
                        parent[j] = k;
                }
                else{
                    dist[j] = dist[k]+1;
                    parent[j] = k;
                }
            }
        }
	}

    pre = parent[dst];
    tmp[count] = dst;
    count++;
    while(pre!=-1){
        tmp[count] = pre;
        pre = parent[pre];
        count++;
    }
    count--;

    //cost
    //memory check
    for(int i=count; i>=0; i--){
        if(i==count || i==0){
            if(qm[tmp[i]]<1){
                (*Reqtmp)--;
                Reqnum[num1] = -1;
                return;
            }
        }
        else{
            if(qm[tmp[i]]<2){
                (*Reqtmp)--;
                Reqnum[num1] = -1;
                return;
            }
        }
    }
    //channel check
    for(int i=count; i>0; i--){
        if(chqme[tmp[i]][tmp[i-1]]<1 || chqme[tmp[i-1]][tmp[i]]<1){
            (*Reqtmp)--;
            Reqnum[num1] = -1;
            return;
        }
    }
    //minus
	for(int i=count; i>=0; i--){
	    if(i==0 || i==count)
            qm[tmp[i]]--;
        else
            qm[tmp[i]]-=2;
	}
    for(int i=count; i>0; i--){
        chqme[tmp[i]][tmp[i-1]]--;
        chqme[tmp[i-1]][tmp[i]]--;
    }
    //reverse to ans
    for(int i=count; i>=0; i--)
        ans[num1][count-i] = tmp[i];
}

int main(){
    int Nodes; //number of nodes
    int Links; //number of links
    int Req; //number of requests
    int NodeID;
    int qm[n]; //number of QuantumMemory
    int LinkID, end1, end2;
    int channel_num; //number of channels
    int ReqSrc;
    int ReqDst;
    int checknum[n]; //count nodes' number

	//initial array
    memset(qm, 0, sizeof(qm));
    memset(graph, INFINITE, sizeof(graph));
	memset(channel, INFINITE, sizeof(channel));
	memset(tmp1, INFINITE, sizeof(tmp1));
	memset(tmp2, INFINITE, sizeof(tmp2));
	memset(checknum, 0, sizeof(checknum));

	//input
    scanf("%d %d %d", &Nodes, &Links, &Req);
    int ReqID[Req];
    int SD[Req][2];
	int AccReq = Req;

    for(int i=0; i<Nodes; i++){
        scanf("%d %d", &NodeID, &qm[i]);
    }
    for(int i=0; i<Links; i++){
        scanf("%d %d %d %d", &LinkID, &end1, &end2, &channel_num);
        graph[end1][end2] = channel_num;
        graph[end2][end1] = channel_num;
        channel[end1][end2] = channel_num;
        channel[end2][end1] = channel_num;
    }
    for(int i=0; i<Req; i++){
        scanf("%d %d %d", &ReqID[i], &ReqSrc, &ReqDst);
        SD[i][0] = ReqSrc;
        SD[i][1] = ReqDst;
    }

    //shortest path
	for(int num=0; num<Req; num++)
        Dijkstra(SD[num][1], SD[num][0], qm, channel, &AccReq, tmp2, ReqID, num);
    //count nodes
    for(int i=0; i<Req; i++){
        for(int j=0; j<n; j++){
            if(tmp2[i][j]!=INFINITE){
                checknum[i]++;
            }
        }
	}
    //reverse ans
    for(int i=0; i<Req; i++){
        for(int j=0; j<checknum[i]; j++){
            tmp1[i][j] = tmp2[i][checknum[i]-1-j];
        }
    }
    //print ans
    printf("%d\n", AccReq);
    for(int i=0; i<Req; i++){
        if(ReqID[i] == -1)
            continue;
        printf("%d ", ReqID[i]);
        for(int j=0; j<checknum[i]; j++){
            if(tmp1[i][j+1]==INFINITE){ //last node
                printf("%d", tmp1[i][j]);
                break;
            }
            else
                printf("%d ", tmp1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
3 3 2
0 6
1 4
2 5
0 0 1 2
1 0 2 3
2 1 2 5
1 0 2
2 1 2
*/

/*
8 9 6
0 2
1 5
2 7
3 4
4 5
5 6
6 5
7 3
0 6 5 3
1 6 3 2
2 3 2 4
3 5 2 9
4 4 5 6
5 6 7 9
6 1 0 5
7 0 4 5
8 1 7 6
0 0 6
1 6 0
5 3 4
3 0 6
100 2 7
5 1 6
*/

/*
7 7 1
0 5
1 5
2 5
3 5
4 5
5 5
6 5
0 0 1 2
1 1 2 2
2 2 4 2
3 4 6 2
4 3 6 2
5 3 5 2
6 0 5 2
0 0 6
*/

/*
7 7 2
0 1
1 2
2 2
3 2
4 2
5 2
6 2
0 0 1 1
1 1 2 1
2 2 4 1
3 4 6 1
4 3 6 1
5 3 5 1
6 0 5 1
0 0 6
1 0 3
*/

/*
5 7 2
0 3
1 3
2 3
3 3
4 3
0 0 1 3
1 0 3 3
2 0 4 3
3 3 4 3
4 3 1 3
5 2 3 3
6 2 4 3
0 0 2
1 4 1
*/

/*
8 9 5
0 2
1 5
2 7
3 4
4 5
5 6
6 5
7 3
0 6 5 3
1 6 3 2
2 3 2 4
3 5 2 9
4 4 5 6
5 6 7 9
6 1 0 5
7 0 4 5
8 1 7 6
0 3 5
1 3 5
2 3 5
3 3 5
4 1 6
*/

/*
7 6 1
0 2
1 2
2 2
3 2
4 2
5 2
6 2
0 0 1 2
1 1 2 2
2 2 3 2
3 3 4 2
4 4 5 2
5 5 6 2
0 0 6
*/
