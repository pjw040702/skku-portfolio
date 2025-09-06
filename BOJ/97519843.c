#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;
    scanf("%d", &num);

    int * dp = (int*) malloc(sizeof(int) * (num+1));
    dp[0] = -1;
    dp[1] = -1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;
    for(int i = 6; i<num+1; i++){
        if(dp[i-3] !=-1 && dp[i-5] == -1) dp[i] = dp[i-3]+1;
        else if(dp[i-3] == -1 && dp[i-5] != -1) dp[i] = dp[i-5] +1;
        else if(dp[i-3] != -1 && dp[i-5] != -1) dp[i] = (dp[i-5]<dp[i-3]) ? dp[i-5]+1 : dp[i-3]+1;
        else dp[i] = -1;
    }
    printf("%d", dp[num]);
    
    return 0;
}