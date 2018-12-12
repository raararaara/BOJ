#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
int n, m;
vector<vector<int>> g;
int arr[100001];

void dfs(int v) {
	for (int next : g[v]) {
		arr[next] += arr[v];
		dfs(next);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	g.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int tmp; scanf("%d", &tmp);
		if (tmp != -1) g[tmp].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		arr[a] += b;
	}

	//dfs(1);
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int Size = q.size();
		for (int i = 0; i < Size; i++) {
			int curr = q.front();
			q.pop();
			int und = g[curr].size();
			for (int j = 0; j < und; j++) {
				arr[g[curr][j]] += arr[curr];
				q.push(g[curr][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
