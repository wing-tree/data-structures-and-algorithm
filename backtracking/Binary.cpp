#include <cstdio>

char A[16];

void Binary(int n) {
    if (n < 1) {
        printf("%s", A);
    } else {
        A[n - 1] = '0';
        Binary(n - 1);
        A[n - 1] = '1';
        Binary(n - 1);
    }
}
