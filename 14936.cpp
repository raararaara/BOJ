#include <stdio.h>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	int half, k3;
	if (n <= 2) {
		if (n == 1) {
			if (m == 0) printf("1\n");
			else printf("2\n");
		}
		if (n == 2) {
			if (m == 0) printf("1\n");
			else if (m == 1) printf("3\n");
			else printf("4\n");
		}
	}
	else {
		int arr[8];
		arr[0] = 0, arr[7] = n;
		arr[1] = arr[2] = n / 2;
		if (n % 2 == 1) arr[2]++;

		arr[3] = (n + 2) / 3;
		arr[4] = arr[1] + arr[2]; arr[5] = arr[1] + arr[3];
		arr[6] = arr[2] + arr[3]; arr[7] = arr[4] + arr[3];
		for (int i = 0; i < 8; i++)
			if (arr[i] <= m) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
