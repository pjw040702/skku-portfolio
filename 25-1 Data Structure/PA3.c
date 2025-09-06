#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// You can declare any global variable, structure, etc.

int N;

typedef struct _Node{
  int isTerminal;
  char item;
  struct _Node *children[26];
} Node;

typedef struct _Stack{
  int top;
  Node * item[100];
} Stack;

Node* rootNode;

void insert(char str[]);
void deletion (char str[]);
void print(Stack* stack, Node* node);
int find(Stack* stack, Node* node, char str[], int *count, int num);


// Modify this main function
int main() {
  rootNode = (Node *) malloc(sizeof(Node));
  rootNode -> isTerminal = 0;
  for(int k=0; k<26; k++) rootNode -> children[k] = NULL;
  
  char op[10];
  char word[100];
  scanf("%d", &N);
  while (N --) {
    scanf("%s", op);
    if (strcmp(op, "insert") == 0) {
      scanf("%s", word);
      insert(word);
    }
    else if (strcmp(op, "delete") == 0) {
      scanf("%s", word);
      deletion(word);
    }
    else if (strcmp(op, "find") == 0) {
      scanf("%s", word);
      Stack stack;
      stack.top = -1;
      int c = 0;
      int f = find(&stack, rootNode, word, &c, 0);
      printf("%d", f);
      if(N!=0) printf("\n");
    }
    else if (strcmp(op, "print") == 0) {
      Stack stack;
      stack.top = -1;
      print(&stack, rootNode);
      if(N!=0) printf("\n");
    }
  }
  return 0;
}

void insert(char str[]){
  Node* node = rootNode;
  for(int i=0; str[i]!='\0'; i++){
    int index = str[i]-'a';
    if(node -> children[index] != NULL) node = node -> children[index];
    else {
      Node * newNode = (Node *) malloc(sizeof(Node));
      newNode -> isTerminal = 0;
      newNode -> item = str[i];
      for(int k=0;k<26;k++) newNode -> children[k] = NULL;
      node -> children[index] = newNode;
      node = newNode;
    }
  }
  node -> isTerminal = 1;
}

void deletion (char str[]){
  Node* node = rootNode;
  Stack stack;
  stack.top=-1;
  for(int i=0; str[i]!='\0'; i++){
    int index = str[i]-'a';
    if(node -> children[index] == NULL) return;
    else{
      node = node -> children[index];
      stack.item[++stack.top] = node;
    }
  }
  if(node -> isTerminal){
    stack.item[stack.top]->isTerminal = 0;
    while(stack.top>=0){
      for(int k=0; k<26; k++){
        if(stack.item[stack.top]->children[k] != NULL){
          stack.top--;
          break;
        }
        if(k==25){
          int index = stack.item[stack.top]->item-'a';
          if(stack.top!=0) stack.item[stack.top-1]->children[index] = NULL;
          else rootNode->children[index] = NULL;
          free(stack.item[stack.top--]);
        }
      }
    }
    
  }
}

void print(Stack* stack, Node* node){
  stack->item[++stack->top] = node;

  if(node->isTerminal){
    for(int i=1; i<=stack->top; i++){
      printf("%c", stack->item[i]->item);
    }
    printf(" ");
  }
  for(int i=0; i<26; i++){
    if(node->children[i]!=NULL){
      print(stack, node->children[i]);
    }
  }
  stack->top--;
  return;
}

int find(Stack* stack, Node* node, char str[], int* count, int num){
  stack->item[++stack->top] = node;
  if(node!=rootNode && node->item == str[num]) num++;
  if(num==strlen(str)){
    if (node->isTerminal) {
      stack->top --;
      return *count;
    }
    else{
      stack -> top --;
      return -1;
    }
  }
  
  if(node->isTerminal){
    *count += 1;
  }
  
  for(int i=0; i<26; i++){
    if(node->children[i]!=NULL){
      int result = find(stack, node->children[i], str, count, num);
      if (result != -1) {
        stack->top--;
        return result;
      }
    }
  }
  stack->top--;
  return -1;
  
}
