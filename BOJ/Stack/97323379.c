#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stack{
int items[10000];
int top;
} Stack;

void push(Stack * stack, int n){
    stack->items[++stack->top] = n;
}
void pop(Stack * stack){
    if(stack->top==-1) printf("%d\n", -1);
    else printf("%d\n",stack->items[stack->top--]);
}
void size(Stack * stack){
    printf("%d\n", stack->top+1);
}
void empty(Stack * stack){
    printf("%d\n", stack->top==-1);
}
void top(Stack * stack){
    if(stack->top==-1) printf("%d\n", -1);
    else{
        printf("%d\n", stack->items[stack->top]);
    }
    
}
int main() {

    Stack stack;
    stack.top = -1;
    int n = 0;
    scanf("%d", &n);
    char str[10];
    int num = 0;
    for(int i=0; i<n; i++){
        scanf(" %s", str);
        if(strcmp(str, "push")==0){
            scanf("%d", &num);
            push(&stack, num);
        }
        else if(strcmp(str, "pop") == 0) pop(&stack);
        else if(strcmp(str, "size") == 0) size(&stack);
        else if(strcmp(str, "empty") == 0) empty(&stack);
        else if(strcmp(str, "top") == 0) top(&stack);
    }
    
    return 0;
}