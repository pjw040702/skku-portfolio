#include <stdio.h>
#include <stdlib.h>

int *** tomato;
int mVector[6] = {-1, 0, 0, 0, 0, 1};
int nVector[6] = {0, -1, 0, 0, 1, 0};
int hVector[6] = {0, 0, -1, 1, 0, 0};
int dayCount(int M, int N, int H);
int main() {
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);
    
    tomato = (int***) malloc(sizeof(int**) * H);
    for(int i=0; i<H; i++){
        tomato[i] = (int**) malloc(sizeof(int*) * N);
        for(int j=0; j<N; j++){
            tomato[i][j] = (int*) malloc(sizeof(int) * M);
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                scanf("%d", &tomato[i][j][k]);
            }
        }
    }
    printf("%d", dayCount(M,N,H));
    
    return 0;
}

int dayCount(int M, int N, int H){
    int mQueue[1000000];
    int nQueue[1000000];
    int hQueue[1000000];
    int rear = 0;
    int front = 0;

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(tomato[i][j][k]==1){
                    hQueue[front] = i;
                    nQueue[front] = j;
                    mQueue[front++] = k;
                }
            }
        }
    }
    while(rear<front){
        for(int i=0; i<6; i++){
            int newH = hQueue[rear] + hVector[i];
            int newM = mQueue[rear] + mVector[i];
            int newN = nQueue[rear] + nVector[i];
            if(newH>=0 && newH<H && newM>=0 && newM<M && newN>=0 && newN<N && tomato[newH][newN][newM] == 0){
                hQueue[front] = newH;
                mQueue[front] = newM;
                nQueue[front++] = newN;
                tomato[newH][newN][newM] = tomato[hQueue[rear]][nQueue[rear]][mQueue[rear]]+1;
            }
        }
        rear++;
    }
    int ans = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(tomato[i][j][k]==0){
                    return -1;
                }
                if(tomato[i][j][k] != -1 && tomato[i][j][k]>ans){
                    ans = tomato[i][j][k];
                }
            }
        }
    }
    return ans-1;
}