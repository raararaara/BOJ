#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[50], num[50];
int N;
double tangent(int x1, int x2, int y1, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	return (double)dy / dx;
}

void input() {
	scanf("%d", &N);
	for(int i = 0; i<N; i++) scanf("%d", arr+i);
}

void proc() {
	for(int i = 0; i<N; i++) {
		//left side
		double Max = -1000000000;
		for(int j = i+1; j<N; j++) {
			if(Max < tangent(i, j, arr[i], arr[j])) {
				num[i]++; num[j]++;
				Max = tangent(i, j, arr[i], arr[j]);
			}
		}
	}
	int ans = num[0];
	for(int i = 1; i<N; i++) if(ans < num[i]) ans = num[i];
	printf("%d\n", ans);
}
int main() {
	input();
	proc();
	return 0;
}
