// https://www.acmicpc.net/problem/11055

#include <cstdio>

int main(void) {
    int N, max;

    scanf("%d", &N);

    int* array = new int[N];
    int* sum = new int[N];

    for (int i(0); i < N; ++i) {
        scanf("%d", &array[i]);
    }

    sum[0] = array[0];
    max = sum[0];

    for (int i(1); i < N; ++i) {
        sum[i] = array[i];

        for (int j(0); j < i; ++j) {
            if (array[i] > array[j]) {
                if (sum[i] < sum[j] + array[i]) {
                    sum[i] = sum[j] + array[i];
                }
            }
        }

        if (max < sum[i]) {
            max = sum[i];
        }
    }

    printf("%d", max);

    delete[] array;

    return 0;
}
