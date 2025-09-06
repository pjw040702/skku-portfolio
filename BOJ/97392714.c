#include <stdio.h>
#include <stdlib.h>

int main() {
    int width, height;
    int xVector[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int yVector[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while(1){
        scanf("%d %d", &width, &height);
        if(width==0 && height==0) break;
        int ** map = (int**) malloc(sizeof(int*) * height);
        for(int i=0; i<height; i++)
            map[i] = (int*) malloc(sizeof(int) * width);

        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                scanf("%d", &map[i][j]);
            }
        }

        int ans = 0;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(map[i][j]==1){
                    int * stackI = (int*) malloc(sizeof(int) * height*width);
                    int * stackJ = (int*) malloc(sizeof(int) * width*height);
                    int top = -1;

                    stackI[++top] = i;
                    stackJ[top] = j;
                    map[i][j] = 2;

                    while(top>=0){
                        int Ipos = stackI[top];
                        int Jpos = stackJ[top];
                        for(int k=0; k<8; k++){
                            int newIpos = Ipos+xVector[k];
                            int newJpos = Jpos+yVector[k];
                            stackI[top] = newIpos;
                            stackJ[top] = newJpos;
                            if(newIpos>=0 && newIpos<height && newJpos>=0 && newJpos<width && map[newIpos][newJpos]==1){
                                stackI[++top] = newIpos;
                                stackJ[top] = newJpos;
                                map[newIpos][newJpos] = 2;
                            }
                        }
                        top--;
                    }
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        
    }
    
    return 0;
}