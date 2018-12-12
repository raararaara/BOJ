#include <stdio.h>
#include <vector>
using namespace std;

int t, n;
bool isprime[100001];
vector<int> primelist;
void init() {
	for (int i = 2; i <= 100000; i++)
		isprime[i] = true;
	for (int i = 2; i <= 100000; i++) {
		for (int j = i * 2; j <= 100000; j += i)
			isprime[j] = false;
	}
	for (int i = 2; i <= 313; i++)
		if (isprime[i]) primelist.push_back(i);
}

int main() {
	init();
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n);
		int idx = 0, count=0, num;
		while (1) {
			if (n % primelist[idx] == 0) {
				num = primelist[idx]; count++;
				n /= primelist[idx];
				continue;
			}
			else {
				if (count) {
					printf("%d %d\n", num, count);
					count = 0;
				}
				idx++;
				if (n == 1) break;
			}
			if (isprime[n]) {
				printf("%d %d\n", n, 1);
				n /= n;
			}
		}
	}
}