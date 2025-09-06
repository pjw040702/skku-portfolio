#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
char item;
struct _node * left;
struct _node * right;

} Node;

void Pre(Node * head){
    if(head == NULL) return;
    printf("%c",head->item);
    Pre(head->left);
    Pre(head->right);
}

void In(Node * head){
    if(head == NULL) return;
    In(head->left);
    printf("%c",head->item);
    In(head->right);
}

void Post(Node * head){
    if(head == NULL) return;
    Post(head->left);
    Post(head->right);
    printf("%c",head->item);
}

int main() {
    int num;
    scanf("%d", &num);
    Node ** nodes = (Node **) malloc(sizeof(Node*) * num);
    for(int i=0; i<num; i++)
        nodes[i] = (Node*) malloc(sizeof(Node));
    Node * head = nodes[0];
    for(int i=0; i<num; i++){
        char head, left, right;
        scanf("\n%c %c %c", &head, &left, &right);
        nodes[head-'A'] ->item = head;
        if(left == '.') nodes[head-'A'] -> left = NULL;
        else nodes[head-'A'] -> left = nodes[left-'A'];
        if(right == '.') nodes[head-'A'] -> right = NULL;
        else nodes[head-'A'] -> right = nodes[right-'A'];
    
    }
    Pre(head);
    printf("\n");
    In(head);
    printf("\n");
    Post(head);
    
    
    return 0;
}
