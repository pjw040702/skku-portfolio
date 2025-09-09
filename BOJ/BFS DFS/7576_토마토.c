#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int BFS(int ** tomato, int row, int column);

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    int ** tomato = (int**) malloc(sizeof(int*) * N);
    for(int i=0; i<N; i++)
        tomato[i] = (int*) malloc(sizeof(int) * M);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &tomato[i][j]);

    printf("%d", BFS(tomato, N, M));
    free(tomato);
    
    return 0;
}

int BFS(int ** tomato, int row, int column){
    int * Xqueue = (int*) malloc(sizeof(int) * row * column);
    int * Yqueue = (int*) malloc(sizeof(int) * row * column);
    
    int Xvector[4] = {-1, 0, 0, 1};
    int Yvector[4] = {0, -1, 1, 0};
  
    int ** time = (int**) malloc(sizeof(int*) * row);
    for(int i=0; i<row; i++)
        time[i] = (int*) malloc(sizeof(int)*column);
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            time[i][j] = -1;

    int front = 0;
    int rear = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){

            if(tomato[i][j]==1){
                time[i][j] = 0;

                Xqueue[front] = i;
                Yqueue[front++] = j;
            }
        }
    }
    while(rear<front){
        for(int k=0; k<4; k++){
            int newX = Xqueue[rear]+Xvector[k];
            int newY = Yqueue[rear]+Yvector[k];
            if(newX>=0 && newX<row && newY>=0 && newY<column && tomato[newX][newY]==0 && time[newX][newY] == -1){
                Xqueue[front] = newX;
                Yqueue[front++] = newY;
                        
                time[newX][newY] = time[Xqueue[rear]][Yqueue[rear]]+1;
            }
        }
        rear++;
    }
    int maximum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(tomato[i][j]==0 && time[i][j]==-1){
                return -1;
            }
            if(time[i][j] > maximum)
                maximum = time[i][j];
        }
    }

    return maximum;
}