#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isprime[5000001];
vector<int> prime;
int t;
int main() {
	
	fill(isprime + 2, isprime + 5000000, true);
	for (int i = 2; i <= 5000000; i++) {
		if (!isprime[i]) continue;
		for (int j = i * 2; j <= 5000000; j += i)
			isprime[j] = false;
	}
	for (int i = 2; i <= 2238; i++)
		if (isprime[i]) prime.push_back(i);
	scanf("%d", &t);
	while (t--) {
		int tmp; scanf("%d", &tmp);
		if (isprime[tmp]) {
			printf("%d\n", tmp);
			continue;
		}
		int half = tmp/2;
		for (int i : prime) {
			if (!isprime[i] || tmp %i != 0) continue;
			while (1) {
				if (tmp % i == 0) {
					printf("%d ", i);
					tmp /= i;
				}
				else break;
			}
		}
		if (isprime[tmp]) printf("%d ", tmp);
		printf("\n");
	}
	return 0;
}
