#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b ? a:b;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    int * stair = (int*) malloc(sizeof(int) * num);
    int * dp = (int*) malloc(sizeof(int) * num);
    for(int i=0; i<num; i++){
        scanf("%d", &stair[i]);
    }
    dp[0] = stair[0];
    dp[1] = stair[0]+stair[1];
    dp[2] = max(stair[0]+stair[2], stair[1]+stair[2]);
    for(int i=3; i<num; i++){
        dp[i] = max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }
    printf("%d", dp[num-1]);
    
    return 0;
}