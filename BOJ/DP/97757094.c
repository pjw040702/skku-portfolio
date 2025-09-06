#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[2000];
char str2[2000];
int ** arr;

int max(int a, int b){
    return a>b?a:b;
}

int main() {
    scanf("\n%s", str1);
    scanf("\n%s", str2);
    arr = (int**) malloc(sizeof(int*) * (strlen(str1)+1));
    for(int i=0; i<strlen(str1)+1; i++){
        arr[i] = (int*) malloc(sizeof(int) * (strlen(str2)+1));
    }
    for(int i=0; i<strlen(str1)+1; i++){
        for(int j=0; j<strlen(str2)+1; j++){
            if(i==0 || j==0) arr[i][j] = 0;
            else{
                if(str1[i-1] == str2[j-1]) arr[i][j] = arr[i-1][j-1]+1;
                else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    printf("%d", arr[strlen(str1)][strlen(str2)]);


    
    return 0;
}