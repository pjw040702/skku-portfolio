#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100000

// you can modify any part of this code

typedef struct _Task {
  int id;
  int R, C, P;
} Task;

typedef struct _Heap {
  Task items[MAX_SIZE+1];
  int size;
} Heap;

void swap(Task *a, Task *b);
void insert(Heap *heap, Task task);
int delete(Heap *heap);

int N;
Task Tasks[MAX_SIZE+1];
Heap TaskBuffer; // use this heap structure

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i ++){
    Tasks[i].id = i;
    scanf("%d %d %d", &Tasks[i].R, &Tasks[i].C, &Tasks[i].P);
  }
  // you must implement priority-based task management system here
  int time = 0; // the time when the last task is completed
  int num = 1;
  int count=0;
  TaskBuffer.size = 0;
  while(num<=N || TaskBuffer.size>0){
    
    while(num<=N && Tasks[num].R<=time){
      insert(&TaskBuffer,Tasks[num]);
      num++;
    }
    if(TaskBuffer.size==0){
      if(num<N+1) time = Tasks[num].R;
      continue;
    }

    Task deleteNode = TaskBuffer.items[1];
    printf("%d",delete(&TaskBuffer));
    count+=1;
    if(count!=N) printf("\n");
    time+=deleteNode.C;
  }
  return 0;
}

void swap(Task *a, Task *b) {
  Task tmp = *a;
  *a = *b;
  *b = tmp;
}

void insert(Heap *heap, Task task) {
  // you must implement this function
  heap->items[++heap->size] = task;
  int i = heap->size;
  while(i>1 && heap->items[i].P > heap->items[i/2].P){
    swap(&heap->items[i],&heap->items[i/2]);
    i/=2;
  }
}

int delete(Heap *heap) {
  // you must implement this function
  int ans = heap->items[1].id;
  swap(&heap->items[1],&heap->items[heap->size--]);
  int i=1, child;
  while(i*2<=heap->size){
    if(i*2+1>heap->size || heap->items[i*2].P>heap->items[i*2+1].P) child=i*2;
    else child = i*2+1;
    if(heap->items[child].P<heap->items[i].P) break;
    swap(&heap->items[child],&heap->items[i]);
    i = child;
  }
  return ans;
}
