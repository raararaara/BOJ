#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;
vector<string> tmp;
int ans = 101;

void change(char &c) {
	if (c == '#') c = 'O';
	else c = '#';
}

void push(int r, int c) {
	change(tmp[r][c]);
	if (r) change(tmp[r - 1][c]);
	if (c) change(tmp[r][c - 1]);
	if (r != 9) change(tmp[r + 1][c]);
	if (c != 9) change(tmp[r][c + 1]);
}

int main() {
	arr.resize(10);
	tmp.resize(10);
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	int maxkind = 1 << 11 - 1;
	for (int kind = 0; kind <= maxkind; kind++) {
		int ret = 0;
		tmp = arr;

		for (int i = 0; i < 10; i++)
			if (kind & (1 << i)) {
				push(0, i);
				ret++;
			}

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (tmp[i - 1][j] == '#') continue;
				push(i, j);
				ret++;
			}
		}

		bool isoff = true;
		for(int i = 0; i<10; i++)
			if (tmp[9][i] == 'O') {
				isoff = false;
				break;
			}

		if (isoff) ans = min(ans, ret);
	}

	printf("%d\n", ans == 101 ? -1 : ans);

	return 0;
}
