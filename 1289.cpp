#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
const int MOD = 1000000007;
typedef long long lint;
typedef pair<int, int> ii;
vector < vector<ii> > g;
int n;
lint ans = 0;
lint dfs(int v, int par) {
	lint ret = 1, tmp;
	for (ii next : g[v]) {
		if (next.first == par) continue;
		tmp = dfs(next.first, v) * next.second % MOD;	// 현재 노드에서 하위 노드로 내려갈 때의 가중치 * 그 하위노드의 값
		ans = (ans + tmp * ret) % MOD;	//ans에 뒤에서 구한 tmp값을 추가한다.
		ret = (ret + tmp) % MOD;	//J자 합을 위한, 그림 그려봐라.
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	g.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	dfs(1, 0);
	printf("%lld\n", ans%MOD);
	
	return 0;
}
