#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a, b, dp[1000001];

int getans(int n) {
	if (n < 0) return 10000000;
	int &ret = dp[n];
	if (ret != -1) return ret;
	if (n == 0) return ret = 0;
	if (n == a + 1 || n == b+1) return ret = 1;
	return ret = min(min(getans(n - (a + 1)), getans(n - (b + 1))), getans(n - 1)) + 1;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	fill(dp, dp + (n+1), -1);
	printf("%d\n", getans(n));
}
