#include <stdio.h> 
#include <stdlib.h>

typedef struct _conf{
int start;
int end;
} Conf;

typedef struct _heap{
int items[1000000];
int size;
} Heap;

Heap heap;

void swap(int * a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pop(){
    swap(&heap.items[1], &heap.items[heap.size--]);
    int i=1, j;
    while(i*2<=heap.size){
        if(i*2+1>heap.size || heap.items[i*2]<heap.items[i*2+1]) j = i*2;
        else j = i*2+1;
        if(heap.items[j]>heap.items[i]) break;
        swap(&heap.items[i],&heap.items[j]);
        i = j;
    }
}

void insert(int n){
    heap.items[++heap.size] = n;
    int i = heap.size;
    while(i>1){
        if(heap.items[i]>heap.items[i/2]) break;
        swap(&heap.items[i],&heap.items[i/2]);
        i/=2;
    }
}

int cmp(const void * a, const void * b){
    const Conf * x = (const Conf *) a;
    const Conf * y = (const Conf *) b;
    if(x->start != y->start) return x->start-y->start;
    return x->end - y->end;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    Conf * conf = (Conf *) malloc(sizeof(Conf) * num);
    for(int i=0; i<num; i++)
        scanf("%d %d", &conf[i].start, &conf[i].end);

    qsort(conf, num, sizeof(Conf), cmp);
    heap.size = 0;

    insert(conf[0].end);
    for(int i=1; i<num; i++){
        
        if(conf[i].start<heap.items[1]){
            insert(conf[i].end);
        }
        else{
            pop();
            insert(conf[i].end);
        }
    }
    printf("%d", heap.size);
    
    return 0;
}