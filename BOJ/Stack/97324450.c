#include <stdio.h>
#include <string.h>

typedef struct _stack{
char items[50];
int top;
} Stack;

int answer(char str[]);

int main() {
    int n = 0;
    scanf("%d", &n);
    char str[50];
    for(int i = 0; i<n; i++){
        scanf("%s", str);
        int ans = answer(str);
        if(ans == 1) printf("YES\n");
        else if(ans == 0) printf("NO\n");
    }
    return 0;
}

int answer(char str[]){
    Stack stack;
    stack.top = -1;
    int len = strlen(str);

    for(int i = 0; i<len; i++){
        if(stack.top!=-1 && stack.items[stack.top] == '(' && str[i] == ')')
            stack.top--;
        else stack.items[++stack.top] = str[i];
    }
    if(stack.top == -1) return 1;
    else return 0;
}