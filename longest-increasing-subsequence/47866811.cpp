// https://www.acmicpc.net/problem/7570

#include <algorithm>
#include <cstdio>

int A[1000001];

int main(void) {
    int N, max(0), n;

    scanf("%d", &N);

    for (int i(1); i <= N; ++i) {
        scanf("%d", &n);

        A[n] = A[n - 1] + 1;
        max = std::max(max, A[n] = A[n - 1] + 1);
    }
    
    printf("%d", N - max);

    return 0;
}
