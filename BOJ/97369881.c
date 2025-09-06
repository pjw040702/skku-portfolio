#include <stdio.h>
#include <stdlib.h>

typedef struct _vertex{
    int i;
    int j;
    int isHouse;
    int visited;
    struct _vertex * next;
} Vertex;

typedef struct _graph{
    Vertex *** heads;
} Graph;

int n;

void connect(Vertex * head, int i, int j);
int DFS(Vertex * head, Graph * graph);
int compareInt(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ia - ib;  // 오름차순
}
int main() {
    scanf("%d", &n);

    Graph graph;
    graph.heads = (Vertex***) malloc(sizeof(Vertex**) * n);
    for(int i=0; i<n; i++){
        graph.heads[i] = (Vertex**) malloc(sizeof(Vertex*) * n);
        for(int j=0; j<n; j++){
            graph.heads[i][j] = (Vertex*) malloc(sizeof(Vertex));
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &graph.heads[i][j]->isHouse);
            graph.heads[i][j]->i = i;
            graph.heads[i][j]->j = j;
            graph.heads[i][j]->visited = 0;
            graph.heads[i][j]->next = NULL;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph.heads[i][j]->isHouse){
                if(i!=0 && graph.heads[i-1][j]->isHouse){
                    connect(graph.heads[i][j], i-1, j);
                    connect(graph.heads[i-1][j], i, j);
                }
                if(i!=n-1 && graph.heads[i+1][j]->isHouse){
                    connect(graph.heads[i][j], i+1, j);
                    connect(graph.heads[i+1][j], i, j);
                }
                if(j!=0 && graph.heads[i][j-1]->isHouse){
                    connect(graph.heads[i][j], i, j-1);
                    connect(graph.heads[i][j-1], i, j);
                }
                if(j!=n-1 && graph.heads[i][j+1]->isHouse){
                    connect(graph.heads[i][j], i, j+1);
                    connect(graph.heads[i][j+1], i, j);
                }
            }
        }
    }

    int * houseNumber = (int*) malloc(sizeof(int) * n * n);
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph.heads[i][j]->isHouse && graph.heads[i][j]->visited == 0){
                houseNumber[cnt++] = DFS(graph.heads[i][j], &graph);
            }
        }
    }
    printf("%d\n", cnt);
    qsort(houseNumber, cnt, sizeof(int), compareInt);
    for(int i=0; i<cnt; i++){
        printf("%d\n", houseNumber[i]);
    }
    

    
    return 0;
}

void connect(Vertex * head, int i, int j){
    for(head; head->next!=NULL; head = head->next);
    head->next = (Vertex *) malloc(sizeof(Vertex));
    head->next->i = i;
    head->next->j = j;
    head->next->isHouse = 1;
    head->next->visited = 0;
    head->next->next = NULL;
}

int DFS(Vertex * head, Graph * graph){
    int num = 0;
    Vertex ** stack = (Vertex**) malloc(sizeof(Vertex*) * n * n);
    int top = -1;
    int ** visited = (int**) malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++)
        visited[i] = (int*) malloc(sizeof(int) * n);
    for(int i=0;i<n;i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
    stack[++top] = head;
    visited[head->i][head->j] = 1;
    head->visited = 1;
    num+=1;
    while(top>=0){
        stack[top] = stack[top] -> next;
        if(stack[top] == NULL){
            top--;
            continue;
        }
        if(visited[stack[top]->i][stack[top]->j] != 1){
            stack[top+1] = graph->heads[stack[top]->i][stack[top]->j];
            visited[stack[top]->i][stack[top]->j]=1;
            stack[++top] -> visited = 1;
            num+=1;
        }
    }
    return num;
}