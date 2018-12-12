#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;

int par[10001], price[10001];
int n, m, k;
bool vis[10001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	if (price[a] > price[b]) par[a] = b;
	else par[b] = a;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i <= n; i++)
		par[i] = i;


	for (int i = 1; i <= n; i++)
		scanf("%d", &price[i]);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		merge(u, v);
	}
	bool flag = true;
	int totl = k;
	for (int i = 1; i <= n; i++) {
		int tmp = find(i);
		if (vis[tmp]) continue;
		if (k < price[tmp]) {
			flag = false;
			break;
		}
		k -= price[tmp];
		vis[tmp] = true;
	}
	if (!flag) printf("Oh no\n");
	else printf("%d\n", totl - k);
	
	return 0;
}
