#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long lint;
int main() {
	int n;
	lint ans = 0, curr = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		lint tmp;
		scanf("%lld", &tmp);
		ans += (lint)abs(curr);
		curr += tmp;
	}
	printf("%lld\n", ans);
	return 0;
}
