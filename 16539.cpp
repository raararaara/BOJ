#include <stdio.h>
#include <string.h>
#define MAX 500000
int n;
int arr[MAX], dp[MAX];

int go(int i) {
	if (dp[i] != -1) return dp[i];
	if (i == n - 1) return dp[i] = 0;
	int j;
	for (j = i + 1; j < n; j++)
		if (arr[j] > arr[i]) break;
	if (j == n) return dp[i] = 0;
	return dp[i] = go(j) + 1;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	for (int i = 0; i < n; i++) {
		go(i);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", dp[i]);
	printf("\n");
	return 0;
}
