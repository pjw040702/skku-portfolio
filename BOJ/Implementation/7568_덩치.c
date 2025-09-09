#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    int * height = (int*) malloc(num * sizeof(int));
    int * weight = (int*) malloc(num * sizeof(int));
    
    for(int i = 0; i<num; i++){
        scanf("%d %d", &weight[i], &height[i]);
    }    
    for(int i = 0; i<num; i++){
        int score = 1;
        for(int j = 0; j<num; j++){
            if(height[j]>height[i] && weight[j] > weight[i]) score++;
        }
        printf("%d ", score);
    }    
}
