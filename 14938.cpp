#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int n, m, r;
int dist[101][101];
int item[31];

void init_and_input() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	for (int i = 1; i <= n; i++)
		scanf("%d", &item[i]);

	for (int i = 0; i < r; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = c;
		dist[b][a] = c;
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}

int main() {
	cin >> n >> m >> r;
	
	init_and_input();
	floyd();
	int ans = 0, tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) tmp += item[j];
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);

	return 0;
}
