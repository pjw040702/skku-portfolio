#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, M, treeSize=1;
    scanf("%d %d", &N, &M);
    for(treeSize; treeSize<N; treeSize*=2);
    
    int * segmentTree = (int*) malloc(sizeof(int) * treeSize*2);

    for(int i=treeSize; i<treeSize+N; i++)
        scanf("%d", &segmentTree[i]);
    for(int i=treeSize+N; i<treeSize*2; i++)
        segmentTree[i] = 0;
    for(int i=treeSize-1; i>0; i--){
        segmentTree[i] = segmentTree[i*2] + segmentTree[i*2+1];
    }
    for(int i=0; i<M; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        int ldx = treeSize+l-1;
        int rdx = treeSize+r-1;
        int ans = 0;
        while(ldx<=rdx){
            if(ldx%2==1) ans += segmentTree[ldx];
            if(rdx%2==0) ans += segmentTree[rdx];
            ldx = (ldx+1)/2;
            rdx = (rdx-1)/2;
        }
        printf("%d\n", ans);
    }
    
    
    return 0;
}