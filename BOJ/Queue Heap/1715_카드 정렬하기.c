#include <stdio.h>
#include <stdlib.h>

int heap[200000];
int size;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int _remove(){
    swap(&heap[1], &heap[size]);
    int number = heap[size--];
    int i = 1, child;
    while(i *2 <= size){
        if(i*2+1>size || heap[i*2]<heap[i*2+1]) child = i*2;
        else child = i*2+1;
        if(heap[i]<heap[child]) break;
        swap(&heap[i], &heap[child]);
        i = child;
    }
    return number;
}

int insert(int n){
    heap[++size] = n;
    int i = size;
    while(i>1 && heap[i]<heap[i/2]){
        swap(&heap[i], &heap[i/2]);
        i/=2;
    }
}

int main() {
    int num;
    size = 0;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int n;
        scanf("%d", &n);
        insert(n);
    }
    int answer = 0;
    while(size>1){
        int temp1 = _remove();
        int temp2 = _remove();
        insert(temp1+temp2);
        answer += (temp1+temp2);
    }
    printf("%d", answer);
    
    return 0;
}