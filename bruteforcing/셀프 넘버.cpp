// https://www.acmicpc.net/problem/4673

#include <cstdio>
#include <vector>

std::vector<bool> N(10001, true);

int d(int n) {
	int digit;
	int m(n);

  while (n > 0) {
    digit = n % 10;
    m += digit;
    n /= 10;
  }

  return m;
}

int main() {
	for (int i(1); i < 10001; ++i) {
		N[d(i)] = false;
	}

	for (int i(1); i < 10001; ++i) {
		if (N[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}

