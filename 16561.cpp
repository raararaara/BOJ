#include <stdio.h>

int n;
int dp[1000][1000];
int main() {
	scanf("%d", &n);
	int k = n / 3;
	k--;
	if (n <= 6) printf("0\n");
	else {
		int ans = k * (k - 1);
		printf("%d\n", ans / 2);
	}


	return 0;
}
