#include <iostream>
#include <string>
using namespace std;
string command;
int M, n, val, dir = 0;
int addx[] = { 1, 0, -1, 0 };
int addy[] = { 0, 1, 0, -1 };
int x = 0, y = 0;
int main() {
	scanf("%d%d", &M, &n);
	for (int i = 0; i < n; i++) {
		cin >> command>>val;

		if (command[0] == 'M') {
			x = x + addx[dir] * val, y = y + addy[dir] * val;
		}
		else if (command[0] = 'T') {
			if (!val) dir = (dir + 1) % 4;
			else dir = (dir +3) % 4;
		}
		if (0 > x || x > M || 0 > y || y > M) {
			printf("-1\n");
			return 0;
		}
	}
	if (0 <= x && x <= M && 0 <= y && y <= M) printf("%d %d\n", x, y);
	else printf("-1\n");

	return 0;
}
