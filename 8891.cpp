#include <stdio.h>

int t;
int a, b;
int arr[300];
int main() {
	for (int i = 1; i <= 300; i++)
		arr[i] = arr[i - 1] + i;
	for (scanf("%d", &t); t--;) {
		int groupa = 0, groupb = 0, xa, ya, xb, yb;

		scanf("%d%d", &a, &b);

		for (int i = 0; i < 143; i++) {
			if (arr[i] < a && a <= arr[i + 1])
				groupa = i+1;
			if (arr[i] < b && b <= arr[i + 1])
				groupb = i + 1;
			if (groupa && groupb) break;
		}
		xa = a - arr[groupa - 1];
		ya = groupa + 1 - xa;
		xb = b - arr[groupb - 1];
		yb = groupb + 1 - xb;

		int x = xa + xb, y = ya + yb;
		int group = x + y - 1;
		printf("%d\n", arr[group - 1] + x);
	}
	return 0;
}
