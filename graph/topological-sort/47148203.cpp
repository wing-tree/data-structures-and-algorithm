// https://www.acmicpc.net/problem/1766

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    priority_queue<int> priority_queue;

    scanf("%d %d", &N, &M);

    int V = N + 1;
    vector<int> graph[V];
    int indegree[V];

    memset(indegree, 0, V * sizeof(int));

    for (int i = 0; i < M; ++i) {
        int A, B;
        
        scanf("%d %d", &A, &B);

        graph[A].push_back(B);
        indegree[B]++;
    }

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            priority_queue.push(-i);
        }
    }
    
    while(!priority_queue.empty()) {
        int v = -priority_queue.top(); priority_queue.pop();

        printf("%d ", v);

        for (int i = 0; i < graph[v].size(); ++i) {
            int w = graph[v][i];

            if (--indegree[w] == 0) {
                priority_queue.push(-w);
            }
        }
    }

    return 0;
}
