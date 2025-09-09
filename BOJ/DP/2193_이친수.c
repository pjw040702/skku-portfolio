#include <stdio.h>
#include <stdlib.h>

int main() {
    int num=0;
    scanf("%d", &num);
    long long int * ans = (long long int*) malloc(sizeof(long long int)*(num+1));

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 1;
    for(int i=3; i<num+1; i++){
        ans[i] = ans[i-2]+ans[i-1];
    }
    printf("%lld", ans[num]);

    
    return 0;
}