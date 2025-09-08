#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    char math = '0';
    int hasMinus = 0;
    scanf("%d", &num);
    int ans = num;
    while(1){
        scanf(" %c %d", &math, &num);
        if(math == '0') break;
        if(math == '-') hasMinus = 1;
        if(hasMinus == 0) ans+=num;
        else if(hasMinus == 1){
            ans-=num;
        }
        math = '0';
    }
    printf("%d", ans);
    
    return 0;
}