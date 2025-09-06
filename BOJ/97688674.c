#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void * a, const void * b){
    const char * const* x = (const char * const*) a;
    const char * const* y = (const char * const*) b;
    return strcmp(*x,*y);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char ** D = (char**) malloc(sizeof(char*) * a);
    char ** B = (char**) malloc(sizeof(char*) * b);
    char ** DB = (char**) malloc(sizeof(char*) * (a+b));
    for(int i=0; i<a; i++)
        D[i] = (char*) malloc(sizeof(char) * 21);
    for(int i=0; i<b; i++)
        B[i] = (char*) malloc(sizeof(char) * 21);
    for(int i=0; i<a+b; i++)
        DB[i] = (char*) malloc(sizeof(char) * 21);
    int size = 0;
    for(int i=0; i<a; i++)
        scanf("\n%s", D[i]);
    for(int i=0; i<b; i++){
        scanf("\n%s", B[i]);
    }
    qsort(D, a, sizeof(char*), cmp);
    qsort(B, b, sizeof(char*), cmp);
    int cmpA=0, cmpB=0;
    while(cmpA<a && cmpB<b){
        if(strcmp(D[cmpA], B[cmpB])<0) cmpA ++;
        else if (strcmp(D[cmpA],B[cmpB])>0) cmpB++;
        else {
            DB[size++] = D[cmpA];
            cmpA++;
            cmpB++;
        }
    }
    printf("%d", size);
    for(int i=0; i<size; i++)
        printf("\n%s", DB[i]);
    
    return 0;
}