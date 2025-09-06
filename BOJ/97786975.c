#include <stdio.h>
#include <stdlib.h>

typedef struct _vertex{
int visited;
int num;
struct _vertex * next;
} Vertex;

typedef struct _graph{
Vertex ** heads;
} Graph;

int N, M;
Graph graph;

int main() {
    scanf("%d %d", &N, &M);
    graph.heads = (Vertex **) malloc(sizeof(Vertex*) * N);
    for(int i=0; i<N; i++){
        graph.heads[i] = (Vertex *) malloc(sizeof(Vertex));
        graph.heads[i]->num = i+1;
        graph.heads[i]->next = NULL;
        graph.heads[i]->visited = 0;
    }
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        Vertex *nv = (Vertex*)malloc(sizeof(Vertex));
        nv->num = b;
        nv->next = graph.heads[a-1]->next;
        graph.heads[a-1]->next = nv;

        nv = (Vertex*)malloc(sizeof(Vertex));
        nv->num = a;
        nv->next = graph.heads[b-1]->next;
        graph.heads[b-1]->next = nv;
    }
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(!graph.heads[i]->visited){
            Vertex** stack = (Vertex**) malloc(sizeof(Vertex*) * N);
            int top = -1;
            stack[++top] = graph.heads[i];
            graph.heads[i]->visited = 1;
            while(top>=0){
                stack[top] = stack[top]->next;
                if(stack[top] == NULL){
                    top--;
                    continue;
                }
                if(!graph.heads[stack[top]->num-1]->visited){
                    stack[++top] = graph.heads[stack[top]->num-1];
                    graph.heads[stack[top]->num-1]->visited = 1;
                }
            }
            cnt +=1;
        }
    }
    printf("%d", cnt);

    
    return 0;
}