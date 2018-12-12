#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1000000000;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n, m;
int arr[1001][1001], dist[1001][1001];
int sr, sc;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				sr = i; sc = j;
				dist[i][j] = 0;
			}
			else if (arr[i][j] == 0)
				dist[i][j] = 0;
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(pair<int, pair<int, int> >(0, pair<int, int>(sr, sc)));
	while (!pq.empty()) {
		int cr = pq.top().second.first, cc = pq.top().second.second, cd = pq.top().first;
		pq.pop();
		if (cd > dist[cr][cc]) continue;
		for (int i = 0; i < 4; i++) {
			int nextr = cr + dy[i], nextc = cc + dx[i];
			if (0 <= nextr && nextr < n && 0 <= nextc && nextc < m && arr[nextr][nextc] == 1) {
				if (dist[nextr][nextc] > dist[cr][cc] + 1) {
					dist[nextr][nextc] = dist[cr][cc] + 1;
					pq.push(pair<int, pair<int, int> >(dist[cr][cc] + 1, pair<int, int>(nextr, nextc)));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", dist[i][j] < INF ? dist[i][j] : -1);
		printf("\n");
	}

	return 0;
}
