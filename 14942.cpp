#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> ii;

vector<vector<ii> > g;

int n, E[100001], dp[100001], par[100001];
bool vis[100001];
void dfs(int v) {
	vis[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		if (!vis[g[v][i].first]) {
			par[g[v][i].first] = v;
			dp[g[v][i].first] = g[v][i].second;
			dfs(g[v][i].first);
		}
	}
}

int move(int v, int energy) {
	if (v == 1) return 1;
	if (dp[v] > energy) return v;
	return move(par[v], energy - dp[v]);
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", E + i);

	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}
	dfs(1);
	printf("1\n");
	for (int i = 2; i <= n; i++)
		printf("%d\n", move(i, E[i]));
	return 0;
}
