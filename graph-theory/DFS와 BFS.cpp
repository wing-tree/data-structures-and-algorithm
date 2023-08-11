// https://www.acmicpc.net/problem/1260

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
  visited[v] = true;
	printf("%d ", v);

	for (int i(0); i < graph[v].size(); ++i) {
  	int u(graph[v][i]);

		if (!visited[u]) {
			dfs(u);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);

	visited[v] = true;

	while (!q.empty()) {
		int p(q.front()); q.pop();

		printf("%d ", p);

		for (int i(0); i < graph[p].size(); ++i) {
			int u(graph[p][i]);

			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);

	for (int i(0); i < M; ++i) {
		int v, u;
		scanf("%d %d", &v, &u);
		graph[v].push_back(u);
		graph[u].push_back(v);

		sort(graph[v].begin(), graph[v].end());
		sort(graph[u].begin(), graph[u].end());
	}

	dfs(V);

	fill(visited, visited + 1001, false);
  
  printf("\n");
  
	bfs(V);

	return 0;
}
