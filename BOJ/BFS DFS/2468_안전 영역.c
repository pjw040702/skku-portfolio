#include <stdio.h>
#include <stdlib.h>
int BFS(int ** map, int num, int rain);
void swap(int * a, int * b);
int main() {
    int num = 0;
    scanf("%d", &num);

    int ** map = (int**) malloc(sizeof(int*) * num);
    for(int i=0; i<num; i++)
        map[i] = (int*) malloc(sizeof(int) * num);

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int ans[100];

    for(int i=0; i<100; i++){
        ans[i] = BFS(map, num, i);
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<99-i; j++){
            if(ans[j]<ans[j+1]) swap(&ans[j], &ans[j+1]);
        }
    }
    printf("%d", ans[0]);
    free(map);
    
    return 0;
}

void swap(int * a, int * b){
    int dummy = *a;
    *a = *b;
    *b = dummy;
}

int BFS(int ** map, int num, int rain){
    int ** visited = (int**) malloc(sizeof(int*) * num);
    int xVector[4] = {-1, 0, 0, 1};
    int yVector[4] = {0, 1, -1, 0};
    int ans=0;
    
    for(int i=0; i<num; i++)
        visited[i] = (int*) malloc(sizeof(int) * num);
    for(int i=0; i<num; i++)
        for(int j=0; j<num; j++)
            visited[i][j] = 0;

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(map[i][j]>rain && visited[i][j] == 0){
                int * xQueue = (int*) malloc(sizeof(int) * num * num);
                int * yQueue = (int*) malloc(sizeof(int) * num * num);
                int front = 0;
                int rear = 0;
                
                visited[i][j] = 1;
                xQueue[front] = i;
                yQueue[front++] = j;
                while(front>rear){
                    for(int k=0; k<4; k++){
                        int newI = xQueue[rear]+xVector[k];
                        int newJ = yQueue[rear]+yVector[k];
                        if(newI>=0 && newI<num && newJ>=0 && newJ<num && map[newI][newJ]>rain && visited[newI][newJ]==0){
                            visited[newI][newJ] = 1;
                            xQueue[front] = newI;
                            yQueue[front++] = newJ;
                        }
                    }
                    rear++;
                }
                ans++;
                free(xQueue);
                free(yQueue);
            }
        }
    }
    free(visited);
    return ans;
}