#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeSort(int * items, char * names[], int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int * items = (int *) malloc(n * sizeof(int));
    char ** names = (char**) malloc(n * sizeof(char*));
    for(int i=0; i<n; i++)
        names[i] = (char *) malloc(100 * sizeof(char));

    for(int i=0; i<n; i++){
        scanf("\n%d %s", &items[i], names[i]);
    }

    MergeSort(items, names, n);

    for(int i=0; i<n; i++){
        printf("%d %s\n", items[i], names[i]);
    }
    
    
    return 0;
}

void MergeSort(int * items, char * names[], int n){
    if(n<=1) return;
    int m = n/2;
    MergeSort(items, names, m);
    MergeSort(items+m, names+m, n-m);

    int * merged = (int*) malloc(sizeof(int) * n);
    char ** mergedN = (char**) malloc(n * sizeof(char*));
    for(int i=0; i<n; i++)
        mergedN[i] = (char *) malloc(100 * sizeof(char));
    int j=0, k=m;
    for(int i = 0; i<n; i++){
        if(j>=m){ 
            merged[i] = items[k];
            mergedN[i] = names[k++];
        }
        else if(k>=n){ 
            merged[i] = items[j];
            mergedN[i] = names[j++];
        }
        else{
            if(items[j] > items[k]){
                merged[i] = items[k];
                mergedN[i] = names[k++];
            }
            else {
                merged[i] = items[j];
                mergedN[i] = names[j++];
            }
        }
    }
    for(int i = 0; i<n; i++){
        items[i] = merged[i];
        names[i] = mergedN[i];
    }
}