#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _queue{
int items[10000];
int front;
int back;
} Queue;

void push(Queue * queue, int n){
    queue->items[queue->back++] = n;
}
void pop(Queue * queue){
    if(queue->front==queue->back) printf("%d\n", -1);
    else printf("%d\n",queue->items[queue->front++]);
}
void size(Queue * queue){
    printf("%d\n", queue->back-queue->front);
}
void empty(Queue * queue){
    printf("%d\n", queue->back==queue->front);
}
void front(Queue * queue){
    if(queue->front==queue->back) printf("%d\n", -1);
    else{
        printf("%d\n", queue->items[queue->front]);
    }
}
void back(Queue * queue){
    if(queue->front==queue->back) printf("%d\n", -1);
    else{
        printf("%d\n", queue->items[queue->back-1]);
    }
}
int main() {

    Queue queue;
    queue.front = 0;
    queue.back = 0;
    int n = 0;
    scanf("%d", &n);
    char str[10];
    int num = 0;
    for(int i=0; i<n; i++){
        scanf(" %s", str);
        if(strcmp(str, "push")==0){
            scanf("%d", &num);
            push(&queue, num);
        }
        else if(strcmp(str, "pop") == 0) pop(&queue);
        else if(strcmp(str, "size") == 0) size(&queue);
        else if(strcmp(str, "empty") == 0) empty(&queue);
        else if(strcmp(str, "front") == 0) front(&queue);
        else if(strcmp(str, "back") == 0) back(&queue);
    }
    
    return 0;
}