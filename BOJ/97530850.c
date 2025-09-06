#include <stdio.h>
#include <stdlib.h>

int swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int abs(int a){
    if(a<0) return (-1) * a;
    else return a;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    int * heap = (int*) malloc(sizeof(int) * (num+1));
    int size = 0;
    int com = 0;
    for(int i=0; i<num; i++){
        scanf("%d", &com);
        if(com==0){
            if(size==0) printf("%d\n", 0);
            else{
                printf("%d\n", heap[1]);
                swap(&heap[1], &heap[size--]);
                int i=1, j;
                while(i*2<=size){
                    if(i*2+1>size || abs(heap[i*2]) < abs(heap[i*2+1])) j = i*2;
                    else if(abs(heap[i*2]) == abs(heap[i*2+1]) && heap[i*2] < heap[i*2+1]) j = i*2;
                    else j = i*2+1;
                    if(abs(heap[i])<abs(heap[j])) break;
                    if(abs(heap[i])==abs(heap[j]) && heap[i]<heap[j]) break;
                    swap(&heap[i],&heap[j]);
                    i=j;
                }
            }
        }
        else{
            heap[++size] = com;
            int i=size;
            while(i>1 && abs(heap[i]) <= abs(heap[i/2])){
                if(abs(heap[i]) == abs(heap[i/2]) && heap[i]>heap[i/2]) break;
                swap(&heap[i], &heap[i/2]);
                i/=2;
            }
        }
    }

    
    return 0;
}