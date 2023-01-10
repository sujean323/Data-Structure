#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    unsigned long hash_num;
    char org_val[1000]; // string before hashing
}node;

// hash function
unsigned long MurmurOAAT32(char *key){
    unsigned long h = 3323198485ul;
    for(;*key;++key){
        h ^= *key;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}
void DFS(int level, int y, int layers, int Strings, node tree[Strings][Strings], node incorrect_str[1000], int* incorrect_num) {
    unsigned long tmp;
    // end of the level
    if(tree[level][y].hash_num == 0)
        return;

    // query the merkle tree
    printf("1 %d %d\n", level, y);
    fflush(NULL);
    scanf("%lu", &tmp); // by judge

    // search and record incorrect string
    if(tree[level][y].hash_num != tmp){
        if(level < layers-1){
            // go left tree
            DFS(level+1, 2*y, layers, Strings, tree, incorrect_str, incorrect_num);
            // go right tree
            DFS(level+1, 2*y+1, layers, Strings, tree, incorrect_str, incorrect_num);
        }
        else{ // find incorrect string
            strcpy(incorrect_str[*incorrect_num].org_val, tree[level][y].org_val);
            (*incorrect_num)++;
        }
    }
    else
        return;
}
void create(int Strings, int StrMaxLen, char str[StrMaxLen], node tree[Strings][Strings], int layers){
    unsigned long tmp[Strings]; // add value
    char buffer[sizeof(unsigned long)*8+1]; // I2S
    int count = 0, level = layers-1;

    // input the data strings stored in the server
    for(int i=0; i<Strings; i++){
        scanf("%s", str);
        strcpy(tree[level][i].org_val, str);
        tree[level][i].hash_num = MurmurOAAT32(str);
    }

    // Get an unsigned long value by adding the two unsigned long hash values
    for(int i=0; i<Strings; i+=2){
        if((i+1) != Strings){ // even nodes
            tmp[count] = (tree[level][i].hash_num) + (tree[level][i+1].hash_num);
        }
        else{ // odd nodes
            tmp[count] = (tree[level][i].hash_num) + (tree[level][i].hash_num);
        }
        count++;
    }
    level--;
    Strings = count;

    while(level >= 0){
        count = 0;
        for(int i=0; i<Strings; i++){
            snprintf(buffer, sizeof(unsigned long)*8+1, "%lu", tmp[count]); //I2S
            tree[level][i].hash_num = MurmurOAAT32(buffer);
            count++;
        }

        count = 0;
        for(int i=0; i<Strings; i+=2){
            if((i+1) != Strings){
                tmp[count] = tree[level][i].hash_num + tree[level][i+1].hash_num;
            }
            else{
                tmp[count] = tree[level][i].hash_num + tree[level][i].hash_num;

            }
            count++;
        }
        level--;
        Strings = count;
    }
}
int main(){
    int Strings; // number of string
    int StrMaxLen; // string max length
    scanf("%d %d", &Strings, &StrMaxLen);

    int layers = Strings, cnt = 0;
    // count layers
    while(layers != 1){ // !root
        if(layers%2 != 0){ // odd
            layers++;
            layers = layers / 2;
        }
        else // even
            layers = layers / 2;
        cnt++;
    }
    cnt++;
    layers = cnt;

    char str[StrMaxLen];
    node tree[Strings][Strings];
    //initial merkle tree
    for(int i=0; i<Strings; i++){
        for(int j=0; j<Strings; j++){
            tree[i][j].hash_num = 0;
        }
    }
    // build merkle tree
    create(Strings, StrMaxLen, str, tree, layers);

    // find incorrect data string
    node incorrect_str[1000];
    int incorrect_num = 0;
    DFS(0, 0, layers, Strings, tree, incorrect_str, &incorrect_num);

    // print answer
    printf("2 %d\n", incorrect_num);
    for(int i=0; i<incorrect_num; i++){
        printf("%s\n", incorrect_str[i].org_val);
    }

    return 0;
}

