#include <stdio.h>
#include <stdlib.h>

int * time;

int BFS(int N, int K, int memory){
    int * Queue = (int *) malloc(sizeof(int) * memory);
    int front = 0;
    int rear = 0;

    time[N] = 0;
    Queue[front++] = N;
    
    while(rear<front){
        if(Queue[rear] == K) break;
        if(Queue[rear]!=memory-1 && (time[Queue[rear]+1]==-1 || time[Queue[rear]+1] > time[Queue[rear]]+1)){
            Queue[front++] = Queue[rear]+1;
            time[Queue[rear]+1] = time[Queue[rear]]+1;
        }
        if(Queue[rear]!=0 && (time[Queue[rear]-1]==-1 || time[Queue[rear]-1]>time[Queue[rear]]+1)){
            Queue[front++] = Queue[rear]-1;
            time[Queue[rear]-1] = time[Queue[rear]]+1;
        }
        if(Queue[rear]!=0 && Queue[rear]*2<memory && (time[Queue[rear]*2]==-1 || time[Queue[rear]*2] > time[Queue[rear]])){
            time[Queue[rear]*2] = time[Queue[rear]];
            Queue[rear] = Queue[rear]*2;
            continue;
        }
        rear++;
    }
    return time[K];
}


int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int memory = N>K ? 2*N : 2*K;
    time = (int*) malloc(memory * sizeof(int));
    for(int i=0; i<memory; i++)
        time[i] = -1;

    printf("%d", BFS(N, K, memory));
    
    return 0;
}