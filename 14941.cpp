#include <stdio.h>
#include <cstring>
typedef long long lint;
lint two[100001], thr[100001]/*, total[100001]*/;
bool isprime[100001], is2 = true;
int a, b;
int left, right;

void init() {
	memset(two, 0, sizeof(two));
	memset(thr, 0, sizeof(thr));
	//memset(total, 0, sizeof(total));
	for (int i = 2; i <= 100000; i++)
		isprime[i] = true;

	for (int i = 2; i <= 100000; i++) {
		if (isprime[i]) {
			//total[i] = total[i - 1];
			if (is2) {
				two[i] = two[i - 1] + i;
				thr[i] = thr[i - 1];
			}
			else {
				thr[i] = thr[i - 1] + i;
				two[i] = two[i - 1];
			} is2 = !is2;
		}
		else {
			two[i] = two[i - 1];
			thr[i] = thr[i - 1];
		}

		for (int j = i * 2; j <= 100000; j += i)
			isprime[j] = false;
	}
}

void find_bound() {
	int i = -1;
	if (!isprime[a]) {
		for(i = a; i<=b; i++)
			if (isprime[i]) {
				left = i; break;
			}
	}
	else left = a;
	if (i == b + 1) left = 1;
	if (!isprime[b]) {
		for(i = b; i >= a; i--)
			if (isprime[i]) {
				right = i; break;
			}
	}
	else right = b;
	if (i == a - 1) right = 1;
}

int main() {
	init();
	int t;
	for (scanf("%d", &t); t--;) {
		scanf("%d%d", &a, &b);
		find_bound();

		lint ans = 0;
		if (two[left] < thr[left]) {
			ans += 3 * (thr[right] - thr[left - 1]);
			ans -= two[right] - two[left - 1];
		}
		else {
			ans += 3 * (two[right] - two[left - 1]);
			ans -= thr[right] - thr[left - 1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
