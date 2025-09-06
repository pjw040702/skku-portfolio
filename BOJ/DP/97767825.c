#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    int * arr = (int*) malloc(sizeof(int) * num);
    int * dp = (int*) malloc(sizeof(int) * num);
    int * dp2 = (int*) malloc(sizeof(int) * num);
  
    for(int i=0; i<num; i++)
        scanf("%d", &arr[i]);

    dp[0] = 1;
    dp2[0] = 1;
    for(int i=1; i<num; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && dp[j]+1>dp[i]) dp[i] = dp[j]+1;
        }
        dp2[i] = dp2[i-1] > dp[i] ? dp2[i-1] : dp[i];
    }

    printf("%d", dp2[num-1]);

    
    return 0;
}