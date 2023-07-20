// https://www.acmicpc.net/problem/2581

#include <algorithm>
#include <cstdio>

bool is_prime_number(int number) {
  if (number < 2) {
    return false;
  }
  
  for (int i(2); i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int M, N;
  int sum(0), min(10000);

  scanf("%d", &M);
  scanf("%d", &N);
	
  for (int i(M); i <= N; ++i) {
    if (is_prime_number(i)) {
      sum += i; 
      min = std::min(i, min);
    }
  }
  
  if (sum == 0) {
    printf("-1");
  } else {
    printf("%d\n", sum);
    printf("%d", min);
  }

	return 0;
}
