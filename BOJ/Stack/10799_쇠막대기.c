#include <stdio.h>
#include <string.h>

typedef struct _stack{
char items[100000];
int top;
} Stack;

int count(char str[]);

int main() {
    char str[100000];
    scanf("%s", str);

    printf("%d", count(str));

    
    return 0;
}

int count(char str[]){
    Stack stack;
    stack.top = -1;
    int count = 0;
    int ncount = 0;
    int len = strlen(str);

    for(int i = 0; i<len; i++){
        if(str[i] == ')' && str[i-1] == '(')
            ncount += 1;
    }
    count += ((len/2)-ncount);
    
    for(int i = 0; i<len; i++){
        
        if(str[i] == '('){
            stack.items[++stack.top] = str[i];
        }
        else if(str[i] == ')' && str[i-1] == '('){
            count += stack.top;
            stack.top--;
        }
        else if(str[i] == ')' && str[i-1] != '('){
            stack.top--;
        }
        
    }
    
    return count;
}