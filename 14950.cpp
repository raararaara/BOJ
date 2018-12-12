#include <stdio.h>
#include <vector>
#include <functional>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
int n, m, t;
int par[10001], Rank[10001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (Rank[a] < Rank[b]) par[a] = b;
	else {
		par[b] = a;
		if (Rank[a] == Rank[b]) Rank[a]++;
	}
}
long long ans = 0;
int main() {
	scanf("%d%d%d", &n, &m, &t);
	ans += (n-2) * (n - 1) * t;
	ans /= 2;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		pq.push(pii(w, ii(u, v)));
	}

	for (int i = 1; i <= n; i++) {
		par[i] = i; Rank[i] = 0;
	}
	int cnt = 0, Size = pq.size();
	for (int i = 0; i < Size; i++) {
		pii curr = pq.top();
		if (find(curr.second.first) == find(curr.second.second)) {
			pq.pop(); continue;
		}
		ans += curr.first;
		merge(curr.second.first, curr.second.second);
		pq.pop();
		if (++cnt == n) break;
	}
	printf("%lld\n", ans);

	return 0;
}
