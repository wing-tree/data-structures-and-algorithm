// https://www.acmicpc.net/problem/2839

#include <cstdio>

int main() {
    int N(0), n(0), m(0);
    
    scanf("%d", &N);

    while (N > 0) {
        if (N % 5 == 0) {
            n = N / 5;
            break;
        } else {
            N -= 3;
            ++m;
        }
    }

    if (N < 0) {
        printf("-1");
    } else {
        printf("%d", n + m);
    }

    return 0;
}
