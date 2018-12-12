#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
map<string, int> mp;
int par[500];
int n, m;

void merge(int a, int b, int result) {
	if (result == 1) {
		if (par[a] == b)
			par[a] = a;

		if (par[a] != a && par[a] != b)
			a = par[a];
		if (par[b] != b && par[b] != a)
			b = par[b];

		par[b] = a;
		for (int i = 0; i < n; i++)
			if (par[i] == b)
				par[i] = a;
	}
	else {
		if (par[b] == a)
			par[b] = b;

		if (par[a] != a && par[a] != b)
			a = par[a];
		if (par[b] != b && par[b] != a)
			b = par[b];

		par[a] = b;
		for (int i = 0; i < n; i++)
			if (par[i] == a)
				par[i] = b;
	}
}

int main() {
	for (int i = 0; i < 500; i++)
		par[i] = i;

	priority_queue<string, vector<string>, greater<string>> pq;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		string k, d, str;
		cin >> k >> d >> str;
		mp[str] = i;
		pq.push(str);
	}
	for (int i = 0; i < m; i++) {
		int battle, idx;
		string k, d, mid, left, last, right;
		cin >> k >> d >> mid >> d >> last;
		for (int i = 0; i < mid.size(); i++)
			if (mid[i] == ',') {
				idx = i; break;
			}
		for (int i = 0; i < idx; i++)
			left = left + mid[i];
		battle = last[last.size() - 1] - '0';
		for (int i = 0; i < last.size() - 2; i++)
			right = right + last[i];

		merge(mp.find(left)->second, mp.find(right)->second, battle);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (par[i] == i) ans++;
	cout << ans << endl;

	while (!pq.empty()) {
		if (par[mp[pq.top()]] == mp[pq.top()]) {
			printf("Kingdom of ");
			cout << pq.top();
			printf("\n");
		}
		pq.pop();
	}
	return 0;
}
