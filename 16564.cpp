#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lint;
lint n, k, sum;
lint arr[1000000], minL = 1000000001, maxL = -1000000001;
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		minL = min(minL, arr[i]);
		maxL = max(maxL, arr[i]);
	}
	
	sum += k;
	if (n == 1) {
		printf("%lld\n", sum); return 0;
	}
	lint lo = minL, hi = sum, mid;
		
	while (lo + 1 <= hi) {
		bool flag = true;
		mid = (lo + hi) / 2;
		lint possible = k;
		for (int i = 0; i < n; i++) {
			if (mid >= arr[i])
				possible -= mid - arr[i];
		}
		if (possible < 0) flag = false;
		lint tmp = mid * n;
		if (tmp <= sum && flag)
			lo = mid + 1;
		else if (tmp > sum || flag == false)
			hi = mid;
	}
	printf("%lld\n", lo - 1);
	return 0;
}
