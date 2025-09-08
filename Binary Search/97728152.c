#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
    int x = *(const int*)a;
    int y = *(const int*)b;
    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}

int binarySearch(int * arr, int size, int target){
    int left = 0, right = size-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) right = mid-1;
        else if(arr[mid] < target) left = mid+1;
    }
    return -1;
}

int main() {
    int num;
    scanf("%d", &num);
    int * A = (int *) malloc(sizeof(int) * num);
    int * B = (int *) malloc(sizeof(int) * num);
    int * C = (int *) malloc(sizeof(int) * num);
    for(int i=0; i<num; i++){
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    qsort(B, num, sizeof(int), cmp);
    int numOfDif = 1;
    C[0] = B[0];
    for(int i=1; i<num; i++){
        if(C[numOfDif-1] != B[i])
            C[numOfDif++] = B[i];
    }
    for(int i=0; i<num; i++){
        printf("%d ", binarySearch(C, numOfDif, A[i]));
    }
    return 0;
}