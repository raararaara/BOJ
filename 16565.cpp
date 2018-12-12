#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long lint;
lint dp[53][53];

lint bino(int n, int m) {
	if (dp[n][m]) return dp[n][m];
	if (n == m || m == 0) return dp[n][m] = 1;
	return dp[n][m] = bino(n - 1, m - 1) + bino(n - 1, m);
}

const int MOD = 10007;
int n;

int main() {
	scanf("%d", &n);
	int bound = n / 4;
	lint sum = 0;
	for (int i = 1; i <= bound; i++) {
		if (i % 2)
			sum += bino(13, i) * bino(52 - 4 * i, n - 4 * i);
		else
			sum -= bino(13, i) * bino(52 - 4 * i, n - 4 * i);
	}
	printf("%lld\n", sum % MOD);
	/*if (n > 39)
		printf("%lld\n", bino(52, 52-n)%MOD);
	else {
		printf("%lld\n", (bino(52, n) - )%MOD);
	}*/
	return 0;
}
