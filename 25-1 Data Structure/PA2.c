#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct _Stack {
int top;
int items[MAX_SIZE];
} Stack;

int pop(Stack * stack);
void push(Stack * stack, int num);
int findAns(int * arr);
int bar_num;
int * bars;

int main() {
  
  scanf("%d", &bar_num);
  bars = (int *) malloc(sizeof(int)*(bar_num+1));
  for(int i=0; i<bar_num; i++)
    scanf("%d", (bars+i));
  *(bars+bar_num) = 0;

  printf("%d", findAns(bars));
  free(bars);
  return 0;
}

int pop(Stack * stack){
  if(stack -> top == -1)
    return -1;
  return stack->items[(stack -> top) --];
}

void push(Stack * stack, int num){
  stack -> items[++(stack -> top)] = num;
}

int findAns(int * arr){
  Stack * stack = (Stack *) malloc(sizeof(Stack));
  stack -> top = -1;
  int i = 0, h = 0, w = 0, S = 0;
  
  
  while (i<=bar_num){
    if (stack -> top == -1 || arr[stack->items[stack->top]] <= arr[i]){
      push(stack,i++);
    }
    else if(arr[stack->items[stack->top]] > arr[i]){
      int n = pop(stack);
      h = arr[n];
      w = (stack->top==-1) ? i : i - stack->items[stack->top] - 1;
      
      S = (h*w > S) ? h*w : S;
    }
    
  }
  free(stack);
  return S;
}
