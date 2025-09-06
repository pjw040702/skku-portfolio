#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return a<b ? a : b;
}

int ** cost;
int ** memo;

int DP(int level, int color){
    if(memo[level][color]!=-1) return memo[level][color];
    memo[level][color] = cost[level][color];
    if(level==0) return cost[0][color];
    return memo[level][color] += min(DP(level-1, (color+1)%3), DP(level-1, (color+2)%3));
}

int main() {
    int num = 0;
    scanf("%d", &num);
    cost = (int**) malloc(sizeof(int*) * num);
    for(int i=0; i<num; i++)
        cost[i] = (int*) malloc(sizeof(int) * 3);
    for(int i=0; i<num; i++)
        for(int j=0; j<3; j++)
            scanf("%d", &cost[i][j]);

    memo = (int**) malloc(sizeof(int*) * num);
    for(int i=0; i<num; i++)
        memo[i] = (int*) malloc(sizeof(int) * 3);
    for(int i=0; i<num; i++)
        for(int j=0; j<3; j++)
            memo[i][j] = -1;
    
    int DP0 = DP(num-1, 0);
    int DP1 = DP(num-1, 1);
    int DP2 = DP(num-1, 2);
    printf("%d", min(DP0, min(DP1, DP2)));
    
    return 0;
}