#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;

    scanf("%d %d", &N, &K);
    int * coin = (int *) malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d",&coin[N-1-i]);
    }
    int ans=0;
    
    for(int i=0; i<N; i++){
        if(K==0) break;
        if(K/coin[i]!=0){
            ans+=K/coin[i];
            K=K%coin[i];
        }
    }
    printf("%d", ans);
    
    return 0;
}