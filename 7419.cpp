#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, arr[10000], ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		double tmp;
		scanf("%lf", &tmp);
		tmp *= 100;
		int tmp2 = (int)tmp;
		arr[i] = tmp2;
	}

	int lo = 0, hi = 1000000001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cuts = 0;
		for (int i = 0; i < n; i++)
			cuts += arr[i] / mid;
		if (cuts < m)
			hi = mid;
		else
			lo = mid;
	}
	if (lo < 1)
		printf("0.00\n");
	else
	printf("%.2lf\n", (double)lo / 100);
	
	return 0;
}