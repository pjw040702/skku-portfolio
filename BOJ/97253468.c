#include <stdio.h>
#include <stdlib.h>

void MergeSort(int * items, int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int * items = (int *) malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &items[i]);
    }

    MergeSort(items, n);

    for(int i=0; i<n; i++){
        printf("%d\n", items[i]);
    }
    
    
    return 0;
}

void MergeSort(int * items, int n){
    if(n<=1) return;
    int m = n/2;
    MergeSort(items, m);
    MergeSort(items+m, n-m);

    int * merged = (int*) malloc(sizeof(int) * n);
    int j=0, k=m;
    for(int i = 0; i<n; i++){
        if(j>=m) merged[i] = items[k++];
        else if(k>=n) merged[i] = items[j++];
        else{
            if(items[j] > items[k]) merged[i] = items[k++];
            else merged[i] = items[j++];
        }
    }
    for(int i = 0; i<n; i++){
        items[i] = merged[i];
    }
}