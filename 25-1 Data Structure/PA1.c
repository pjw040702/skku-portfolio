#include <stdio.h>
#define MAX_SIZE 1000

int N, M;
int A[MAX_SIZE][MAX_SIZE];
int sum = 0;

int main() {
  int i, j;
  int r0, r1, c0, c1, sum = 0;

  scanf("%d", &N);
  for (i = 0; i < N; i ++) {
    for (j = 0; j < N; j ++) {
      scanf("%d", &A[i][j]);
    }
  }

  scanf("%d", &M);
  for (i = 0; i < M; i ++) {
    sum = 0;
    scanf("%d%d%d%d", &r0, &r1, &c0, &c1);
    for(int r = r0;r<r1;r++){
      for(int c = c0;c<c1;c++){
        sum+=*(*(A+r)+c);
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
