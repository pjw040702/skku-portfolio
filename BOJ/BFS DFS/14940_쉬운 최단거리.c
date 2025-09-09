#include <stdio.h>
#include <stdlib.h>

int ** map;
int nVector[4] = {-1, 0, 0, 1};
int mVector[4] = {0, -1, 1, 0};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    map = (int**) malloc(sizeof(int*) * n);
    for(int i=0; i<n; i++)
        map[i] = (int*) malloc(sizeof(int) * m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int nQueue[1000000];
    int mQueue[1000000];
    int front = 0;
    int rear = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 2){
                map[i][j] = 0;
                nQueue[front] = i;
                mQueue[front++] = j;
            }
            if(map[i][j] == 1){
                map[i][j] = -1;
            }
        }
    }
    while(rear < front){
        for(int i=0; i<4; i++){
            int newN = nQueue[rear] + nVector[i];
            int newM = mQueue[rear] + mVector[i];
            if(newN>=0 && newN<n && newM>=0 && newM<m && map[newN][newM] == -1){
                map[newN][newM] = map[nQueue[rear]][mQueue[rear]] + 1;
                nQueue[front] = newN;
                mQueue[front++] = newM;
            }
        }
        rear++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}