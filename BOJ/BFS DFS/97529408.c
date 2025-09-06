#include <stdio.h>
#include <stdlib.h>

int square(int a, int b){
    int num = a;
    for(int i=1; i<b; i++)
        num*=a;
    return num;
}


int DFS(int N, int r, int c){
    if(N==1){
        if(r==0 && c==0) return 0;
        if(r==0 && c==1) return 1;
        if(r==1 && c==0) return 2;
        if(r==1 && c==1) return 3;
    }
    return square(4, N-1) * DFS(1, r/square(2,N-1), c/square(2,N-1)) + DFS(N-1, r%square(2,N-1), c%square(2,N-1));
}

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    
    printf("%d", DFS(N, r, c));
    return 0;
}