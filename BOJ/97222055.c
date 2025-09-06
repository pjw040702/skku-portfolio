#include <stdio.h>
#include <stdlib.h>

int getTime(int r, int c, char ** matrix);

int main()
{
    int h = 0, w = 0;
    scanf("%d %d", &h, &w);
    char ** matrix = (char**) malloc(sizeof(char*) * h);
    for(int i = 0; i<h; i++)
        matrix[i] = (char *) malloc(sizeof(char) * w);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("\n%c", &matrix[i][j]);
        }
    }
    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            printf("%d ", getTime(i,j,matrix));
        }
        printf("\n");
    }
}

int getTime(int r, int c, char ** matrix){
    int count = 0;
    for(int k = c; k>0; k--){
        
        if(matrix[r-1][k-1] == 'c') return count;
        count ++;
    }
    return -1;
}