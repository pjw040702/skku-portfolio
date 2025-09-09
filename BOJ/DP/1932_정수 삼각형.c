#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b? a:b;
}

int main() {
    int num;
    scanf("%d", &num);
    int ** tri = (int**) malloc(sizeof(int*) * num);
    for(int i=0; i<num; i++)
        tri[i] = (int*) malloc(sizeof(int) * (i+1));
    for(int i=0; i<num; i++)
        for(int j=0; j<i+1; j++)
            scanf("%d", &tri[i][j]);

    for(int i=1; i<num; i++){
        for(int j=0; j<i+1; j++){
            if(j==0) tri[i][j] = tri[i][j] + tri[i-1][j];
            else if(j==i) tri[i][j] = tri[i][j] + tri[i-1][j-1];
            else tri[i][j] = max(tri[i][j]+tri[i-1][j-1], tri[i][j]+tri[i-1][j]);
        }
    }
    int ans = 0;
    for(int i=0; i<num; i++){
        if(ans<tri[num-1][i]) ans = tri[num-1][i];
    }
    printf("%d", ans);
    
    return 0;
}