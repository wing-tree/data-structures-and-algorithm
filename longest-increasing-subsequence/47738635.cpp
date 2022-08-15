// https://www.acmicpc.net/problem/2631

#include <cstdio>

int main(void) {
    int N, max(0);

    scanf("%d", &N);

    int* A = new int[N];
    int* B = new int[N];

    for (int i(0); i < N; ++i) {
        scanf("%d", &A[i]);
    }

    B[0] = 1;

    for (int i(1); i < N; ++i) {
        B[i] = 1;

        for (int j(0); j < i; ++j) {
            if (A[i] > A[j]) {
                if (B[i] < B[j] + 1) {
                    B[i] = B[j] + 1;
                }
            }
        }

        if (max < B[i]) {
            max = B[i];
        }
    }

    printf("%d", N - max);

    delete[] A;
    delete[] B;

    return 0;
}
