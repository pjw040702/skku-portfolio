#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int K, N;
long long *arr;

bool possible(long long len) {
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
        cnt += arr[i] / len;
        if (cnt >= N) return true; // 조기 종료
    }
    return false;
}

int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    return (x > y) - (x < y);
}

long long parSearch() {
    long long left = 1;               // 0 금지 (0으로 나누기 방지)
    long long right = arr[K - 1];     // 정렬했으므로 최대값
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (possible(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    scanf("%d %d", &K, &N);
    arr = (long long *)malloc(sizeof(long long) * K);
    for (int i = 0; i < K; i++) scanf("%lld", &arr[i]);

    qsort(arr, K, sizeof(long long), cmp_ll);
    printf("%lld\n", parSearch());

    free(arr);
    return 0;
}