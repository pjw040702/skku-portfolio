#include <stdio.h>
#include <stdlib.h>

int countW(int r, int c, char ** board);
int countB(int r, int c, char ** board);

int main()
{
    int row = 0, column = 0;
    scanf("%d %d", &row, &column);
    
    char ** board = (char **) malloc(sizeof(char*) * row);
    for(int i = 0; i<row; i++){
        board[i] = (char*) malloc(sizeof(char) * (column));
    }
    for(int i = 0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("\n%c", &board[i][j]);
        }
    }
    int count = 2500;
    for(int i=1; i<=row-7; i++){
        for(int j=1; j<=column-7; j++){
            int Wcount = countW(i,j,board);
            int Bcount = countB(i,j,board);
            int compare = (Wcount > Bcount) ? Bcount : Wcount;
            if(count>compare) count = compare;
        }
    }
    
    printf("%d ", count);
    
    return 0;
}

int countW(int r, int c, char ** board){
    int count = 0;
    for(int i=r; i<r+8; i++){
        for(int j=c; j<c+8; j++){
            if((i+j)%2==0 && board[i-1][j-1] == 'B') count++;
            if((i+j)%2==1 && board[i-1][j-1] == 'W') count++;
        }
    }
    return count;
}
int countB(int r, int c, char ** board){
    int count = 0;
    for(int i=r; i<r+8; i++){
        for(int j=c; j<c+8; j++){
            if((i+j)%2==0 && board[i-1][j-1] == 'W') count++;
            if((i+j)%2==1 && board[i-1][j-1] == 'B') count++;
        }
    }
    return count;
}


