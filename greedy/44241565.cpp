// https://www.acmicpc.net/problem/1417

#include <algorithm>
#include <cstdio>

#define SIZE 50

using namespace std;

int main(void) {
    int N, m, n = 0;
    int array[SIZE];

    scanf("%d", &N);
    scanf("%d", &m);

    for (int i = 0; i < N - 1; ++i) {
        scanf("%d", &array[i]);
    }

    while(true) {
        int i = distance(array, max_element(array, array + N - 1));

        if (m > array[i]) {
            printf("%d", n);
            break;
        } else {
            --array[i];
            ++m;
            ++n;
        }
    }

    return 0;
}
