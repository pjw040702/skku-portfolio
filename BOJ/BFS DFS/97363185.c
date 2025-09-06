#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _vertex{
    struct _vertex * next;
    int isPos;
    int code;
    int visited;
} Vertex;

typedef struct _graph{
    Vertex ** heads;
} Graph;

int M, N, K;

int code(int m, int n);
void connect(Graph * graph);
void addVertex(Vertex * vertex, int code);

int main()
{
    int testcase = 0;
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        scanf("%d %d %d", &M, &N, &K);
        Graph graph;
        graph.heads = (Vertex**) malloc(sizeof(Vertex*) * M * N);
        for(int j=0; j<M*N; j++){
            graph.heads[j] = (Vertex*) malloc(sizeof(Vertex));
            graph.heads[j] -> code = j;
            graph.heads[j] -> isPos = 0;
            graph.heads[j] -> visited = 0;
            graph.heads[j] -> next = NULL;
        }
        int m, n;
        for(int j=0; j<K; j++){
            scanf("%d %d", &m, &n);
            graph.heads[code(m, n)]->isPos = 1;
        }
        connect(&graph);
        int ans = 0;
        for(int j=0; j<M*N; j++){
            if(graph.heads[j]->visited == 0 && graph.heads[j]->isPos == 1){
                Vertex ** stack = (Vertex**) malloc(sizeof(Vertex*) * M * N);
                int top = -1;
                stack[++top] = graph.heads[j];
                stack[top] -> visited = 1;
                while(top>=0){
                    stack[top] = stack[top] -> next;
                    if(stack[top] == NULL){
                        top--;
                        continue;
                    }
                    if(graph.heads[stack[top]->code]->visited == 0){
                        graph.heads[stack[top]->code]->visited = 1;
                        stack[++top] = graph.heads[stack[top]->code];
                    }
                }
                
                ans+=1;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

int code(int m, int n){
    return n*M+m;
}

void connect(Graph * graph){
    for(int i=0; i<M*N; i++){
        if(graph->heads[i]->isPos == 1){
            if((i+1)%M!=0 && graph->heads[i+1]->isPos == 1){
                addVertex(graph->heads[i], i+1);
                addVertex(graph->heads[i+1], i);
            }
            if((i)%M!=0 && graph->heads[i-1]->isPos == 1){
                addVertex(graph->heads[i], i-1);
                addVertex(graph->heads[i-1], i);
            }
            if((i+M)<M*N && graph->heads[i+M]->isPos == 1){
                addVertex(graph->heads[i], i+M);
                addVertex(graph->heads[i+M], i);
            }
            if((i-M)>=0 && graph->heads[i-M]->isPos == 1){
                addVertex(graph->heads[i], i-M);
                addVertex(graph->heads[i-M], i);
            }
        }
    }
    
}

void addVertex(Vertex * vertex, int code){
    Vertex * v;
    for(v=vertex; v->next!=NULL; v=v->next);
    v->next = (Vertex *) malloc(sizeof(Vertex));
    v->next->code = code;
    v->next->next = NULL;
    
}