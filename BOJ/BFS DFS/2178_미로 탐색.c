#include <stdio.h>
#include <stdlib.h>

int ** miro;
int nVector[4] = {-1, 0, 0, 1};
int mVector[4] = {0, -1, 1, 0};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    miro = (int **) malloc(sizeof(int*) * N);
    for(int i=0; i<N; i++){
        miro[i] = (int*) malloc(sizeof(int) * M);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &miro[i][j]);
            if(miro[i][j] == 1) miro[i][j] = -1;
        }
    }
    int * nQueue = (int *) malloc(sizeof(int) * N * M);
    int * mQueue = (int *) malloc(sizeof(int) * N * M);
    int rear = 0;
    int front = 0;
    nQueue[front] = 0;
    mQueue[front++] = 0;
    miro[0][0] = 1;
    while(rear<front){
        for(int i=0; i<4; i++){
            int newN = nQueue[rear] + nVector[i];
            int newM = mQueue[rear] + mVector[i];
            if(newN>=0 && newN<N && newM>=0 && newM<M && miro[newN][newM] == -1){
                nQueue[front] = newN;
                mQueue[front++] = newM;
                miro[newN][newM] = miro[nQueue[rear]][mQueue[rear]]+1;
            }
        }
        rear++;
    }
    printf("%d", miro[N-1][M-1]);

    
    return 0;
}