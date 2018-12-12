#include <stdio.h>
typedef struct {
	int load, num;
}mytype;
int N, W, L;	//1000 100 1000
int arr[1000], idx;	// under 11
mytype arr2[100000];
int ans, time;

int main() {
	scanf("%d%d%d", &N, &W, &L);

	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	while (idx < N) {
		int i;
		while (time && arr2[time].load + arr[idx] > L && arr2[time].num +1 <= W)
			time++;
		if (!time) time++;
		for (i = time; i < time + W; i++) {
			arr2[i].load += arr[idx];
			arr2[i].num++;
		}
		time++; ans = i; idx++;
	}
	printf("%d\n", ans);
	return 0;
}
