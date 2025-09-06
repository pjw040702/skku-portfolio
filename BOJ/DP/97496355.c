#include <stdio.h>
#include <stdlib.h>

int main() {
    int testcase = 0;
    scanf("%d", &testcase);
    for(int j=0; j<testcase; j++){
        int num=0;
        scanf("%d", &num);
        int * ans = (int*) malloc(sizeof(int) * (num+1));
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 4;
        for(int i=4; i<num+1; i++){
            ans[i] = ans[i-1]+ans[i-2]+ans[i-3];
    
        }
        printf("%d\n", ans[num]);
    }
    
    return 0;
}