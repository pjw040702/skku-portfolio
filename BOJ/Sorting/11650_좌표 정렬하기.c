#include <stdio.h>
#include <stdlib.h>

void MergeSort(int * x, int * y, int num);

int main() {
    int num = 0;
    scanf("%d", &num);
    int * x = (int*) malloc(sizeof(int) * num);
    int * y = (int*) malloc(sizeof(int) * num);
    
    for(int i=0;i<num;i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    MergeSort(x, y, num);
    for(int i=0;i<num;i++){
        printf("%d %d\n", x[i], y[i]);
    }
    
    return 0;
}

void MergeSort(int * x, int * y, int num){
    if(num<=1) return;
    int m = num/2;
    MergeSort(x, y, m);
    MergeSort(x+m, y+m, num-m);

    int * mergedX = (int*) malloc(sizeof(int)*num);
    int * mergedY = (int*) malloc(sizeof(int)*num);

    int j=0, k=m;
    for(int i = 0; i<num; i++){
        if(j>=m){
            mergedX[i] = x[k];
            mergedY[i] = y[k++];
        }
        else if(k>=num){
            mergedX[i] = x[j];
            mergedY[i] = y[j++];
        }
        else{
            if(x[j]<x[k]){
                mergedX[i] = x[j];
                mergedY[i] = y[j++];
            }
            else if (x[k]<x[j]){
                mergedX[i] = x[k];
                mergedY[i] = y[k++];
            }
            else if (x[k] == x[j]){
                if(y[k] < y[j]){
                    mergedX[i] = x[k];
                    mergedY[i] = y[k++];
                }
                else{
                    mergedX[i] = x[j];
                    mergedY[i] = y[j++];
                }
            }
        }
    }
    for(int i=0;i<num;i++){
        x[i] = mergedX[i];
        y[i] = mergedY[i];
    }
}