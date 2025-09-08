#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * arr;
int N, M;

bool possible(int n){
    int idx = 0;
    for(int i=0; i<M; i++){
        int sum = 0;
        for(idx; idx<N; idx++){
            if(sum+arr[idx] <= n) sum += arr[idx];
            else break;
        }
    }
    if(idx == N) return true;
    else return false;
}

int parSearch(){
    int left = 0, right = (N * 10000) / M, result;
    while(left<=right){
        int mid = (left+right)/2;
        if(possible(mid)){
            result = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return result;
}

int main() {
    scanf("%d %d", &N, &M);
    arr = (int*) malloc(sizeof(int) * N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    printf("%d", parSearch());
    
    return 0;
}