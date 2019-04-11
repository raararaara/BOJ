#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int64_t basis[60], x;

void computeREF(int x) {
	for (int i = 59; i >= 0; i--) {
		if ((x >> i) & 1) {
			if (!basis[i]) {
				basis[i] = x;
				return;
			}
			else x ^= basis[i]; // elimination
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		computeREF(x);
	}
	x = 0;
	for (int i = 59; i >= 0; i--)
		x = max(x, x ^ basis[i]);
	printf("%lld\n", x);

	return 0;
}