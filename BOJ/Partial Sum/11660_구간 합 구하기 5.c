#include <stdio.h>
#include <stdlib.h>

int ** arr;
int ** sumArr;
int N, M;

int get(int r, int c){
    if(r<0 || c<0) return 0;
    return sumArr[r][c];
}

int getSum(int r1, int c1, int r2, int c2){
    return (get(r2, c2) + get(r1-1,c1-1) - get(r1-1, c2) - get(r2, c1-1));
}

int main() {
    scanf("%d %d", &N, &M);
    arr = (int**) malloc(sizeof(int*) * N);
    sumArr = (int**) malloc(sizeof(int*) * N);
    for(int i=0; i<N; i++){
        arr[i] = (int*) malloc(sizeof(int) * N);
        sumArr[i] = (int*) malloc(sizeof(int) * N);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
            sumArr[i][j] = arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=0 && j!=0) sumArr[i][j] += (sumArr[i-1][j]+sumArr[i][j-1]-sumArr[i-1][j-1]);
            else if(j==0 && i!=0) sumArr[i][j] += sumArr[i-1][j];
            else if(i==0 && j!=0) sumArr[i][j] += sumArr[i][j-1];
        }
    }
    

    for(int i=0; i<M; i++){
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        printf("%d\n", getSum(r1-1,c1-1,r2-1,c2-1));
    }
    
    return 0;
}