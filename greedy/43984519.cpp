// https://www.acmicpc.net/problem/2012

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int main(void) {
    int N, rank;
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int> > priority_queue;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &rank);
        priority_queue.push(rank);
    }

    for (int i = 1; i <= N; ++i) {
        sum += abs(i - priority_queue.top());
        priority_queue.pop();
    }

    printf("%lld", sum);

    return 0;
}
