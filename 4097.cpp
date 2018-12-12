#include <stdio.h>
#include <string.h>

int Max(int a, int b) {
	return a > b ? a : b;
}
int t;
int arr[250001];
int main() {
	while (1) {
		scanf("%d", &t);
		if (!t) break;
		for (int i = 1; i <= t; i++) {
			scanf("%d", arr + i);
			arr[i] = Max(arr[i], arr[i - 1] + arr[i]);
		}
		long long ans = arr[1];
		for (int i = 1; i <= t; i++) 
			ans = Max(ans, arr[i]);
		printf("%lld\n", ans);
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}
