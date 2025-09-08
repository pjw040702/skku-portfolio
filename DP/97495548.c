#include <stdio.h>
#include <stdlib.h>

int intmax(int a, int b, int c);
int main() {
    int num = 0;
    scanf("%d", &num);
    int * wine = (int*) malloc(sizeof(int) * num);
    int * dp = (int*) malloc(sizeof(int) * num);
    
    for(int i=0; i<num; i++)
        scanf("%d", &wine[i]);

    dp[0] = wine[0];
    dp[1] = wine[0]+wine[1];
    dp[2] = intmax(wine[0]+wine[1], wine[1]+wine[2], wine[0]+wine[2]);
    for(int i=3; i<num; i++){
        dp[i] = intmax(wine[i]+dp[i-2], dp[i-1], wine[i]+dp[i-3]+wine[i-1]);
    }
    printf("%d", dp[num-1]);

    return 0;
}
int intmax(int a, int b, int c){
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}