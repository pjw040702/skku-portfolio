#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * house;
int N, C;

bool possible(int n){
    int count = 1;
    int last = house[0];
    for (int i = 1; i < N; i++) {
        if (house[i] - last >= n) {
            count++;
            last = house[i];
        }
    }
    return count >= C;
}

int parSearch(){
    int left = 0, right = house[N-1]-house[0], ans;
    while(left<=right){
        int mid = (left+right)/2;
        if(possible(mid)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return ans;
}

int cmp(const void * a, const void * b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x-y;
}

int main() {
    scanf("%d %d", &N, &C);
    house = (int*) malloc(sizeof(int) * N);
    for(int i=0; i<N; i++)
        scanf("%d", &house[i]);
    qsort(house, N, sizeof(int), cmp);
    printf("%d", parSearch());

    
    return 0;
}