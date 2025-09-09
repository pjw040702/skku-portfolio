#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char ** map;
int n;
bool ** visited;
int rVector[4] = {-1,0,0,1};
int cVector[4] = {0,-1,1,0};

void DFS(int r, int c, char color){
    visited[r][c] = true;
    for(int i=0; i<4; i++){
        int newR = r+rVector[i];
        int newC = c+cVector[i];
        if(newR>=0 && newR<n && newC>=0 && newC<n && map[newR][newC] == color && visited[newR][newC] == false) DFS(newR, newC, color);
    }
    return;
}

int main() {
    scanf("%d", &n);
    map = (char **) malloc(sizeof(char*) * n);
    visited = (bool **) malloc(sizeof(bool*) * n);
    for(int i=0; i<n; i++){
        map[i] = (char*) malloc(sizeof(char) * n);
        visited[i] = (bool*) malloc(sizeof(bool)*n);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("\n%c", &map[i][j]);
            visited[i][j] = false;
        }
    }
    int count1 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                DFS(i, j, map[i][j]);
                count1 ++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'G') map[i][j] = 'R';
            visited[i][j] = false;
        }
    }
    int count2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                DFS(i, j, map[i][j]);
                count2 ++;
            }
        }
    }
    
    printf("%d %d", count1, count2);


    
    return 0;
}