#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
    const int * x = (const int *) a;
    const int * y = (const int *) b;
    return *x-*y;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    int * arr = (int*) malloc(sizeof(int) * num);
    for(int i=0; i<num; i++)
        scanf("%d", &arr[i]);
    qsort(arr, num, sizeof(int), cmp);
    int ans=0;
    for(int i=0; i<num; i++){
        ans+=arr[i] * (num-i);
    }
    printf("%d", ans);
    
    return 0;
}