#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n, tmp, start;

vector<vector<int>> g;
queue<int> q;

int arr[21];
int height = 0;

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 1; i <= n; i++)
		g[i].resize(2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		if (tmp == -1) {
			start = i;
			arr[start] = height; q.push(start);
			continue;
		}
		if (!tmp) {
			arr[i] = height; q.push(i);
			arr[tmp] = 0; continue;
			
		}
		if (!g[tmp][0]) g[tmp][0] = i;
		else g[tmp][1] = i;
	}
	
	while (!q.empty()) {
		int Size = q.size();
		for (int i = 0; i < Size; i++) {
			int curr = q.front(); q.pop();
			for (int next : g[curr]) {
				if (next) {
					arr[next] = height + 1;
					q.push(next);
				}
			}
		}
		height++;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);
	return 0;
}
