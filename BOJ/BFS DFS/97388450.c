#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int * queue = (int*) malloc(sizeof(int) * 100001);
    int front = 0;
    int rear = 0;
    int * time = (int *) malloc(sizeof(int) * 100001);
    for(int i = 0; i<100001; i++)
        time[i] = -1;

    int neighbor[3];

    queue[front++] = N;
    time[N] = 0;
    while(rear<front){
        neighbor[0] = queue[rear]+1;
        neighbor[1] = queue[rear]-1;
        neighbor[2] = queue[rear]*2;
        if(queue[rear] == K) break;
        for(int i=0; i<3; i++){
            if(neighbor[i]>=0 && neighbor[i]<100001 && time[neighbor[i]] == -1){
                queue[front++] = neighbor[i];
                time[neighbor[i]] = time[queue[rear]]+1;
            }
        }
        rear++;
    }
    printf("%d", time[K]);
    
    return 0;
}