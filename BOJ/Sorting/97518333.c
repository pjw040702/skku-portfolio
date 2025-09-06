#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Conf;

int cmp(const void *a, const void *b) {
    const Conf *x = (const Conf *)a;
    const Conf *y = (const Conf *)b;
    if (x->end != y->end) return (x->end < y->end) ? -1 : 1;   // 종료 오름차순
    if (x->start != y->start) return (x->start < y->start) ? -1 : 1; // 시작 오름차순
    return 0;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Conf *conf = (Conf *)malloc(sizeof(Conf) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &conf[i].start, &conf[i].end);
    }

    qsort(conf, n, sizeof(Conf), cmp);

    int count = 0;
    int endTime = 0;
    for (int i = 0; i < n; i++) {
        if (endTime <= conf[i].start) {
            count++;
            endTime = conf[i].end;
        }
    }

    printf("%d", count);
    return 0;
}