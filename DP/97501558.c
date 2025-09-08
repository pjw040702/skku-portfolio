#include <stdio.h>
#include <stdlib.h>



int main() {
    int testcase = 0;
    int num = 0;
    scanf("%d", &testcase);

    for(int a=0; a<testcase; a++){
        scanf("%d", &num);
        int * zero = (int*) malloc(sizeof(int) * (num+1));
        int * one = (int*) malloc(sizeof(int) * (num+1));
        zero[0] = 1;
        zero[1] = 0;
        one[0] = 0;
        one[1] = 1;
        for(int i=2; i<num+1; i++){
            zero[i] = zero[i-1] + zero[i-2];
            one[i] = one[i-1] + one[i-2];
        }
        printf("%d %d\n", zero[num], one[num]);
        free(zero);
        free(one);
    }

    
    
    return 0;
}