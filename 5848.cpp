#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>>g;
int n, ans = 0;
bool vis[1001], flag = false;

void dfs(int v) {
	if (vis[v]) return;
	if (v == 0) { flag = true; return; }
	vis[v] = true;
	dfs(g[v][0]);
}
int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int tmp; scanf("%d", &tmp);
		g[i].push_back(tmp);
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		flag = false;
		dfs(i);
		if (flag) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
