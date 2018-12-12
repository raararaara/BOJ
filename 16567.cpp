#include <stdio.h>
#include <string.h>
bool arr[1000002];
int n, m, ans;

int main() {
	scanf("%d%d", &n, &m);
	bool prev = arr[0];
	for(int i = 1; i<=n; i++) {
		scanf("%d", arr + i);
		if(prev == false && arr[i] == true)
			ans++;
		prev = arr[i];
	}
	int cmd, val;
	for(int i = 0; i<m; i++) {
		scanf("%d", &cmd);
		if(cmd) {
			int cnt = 0;
			scanf("%d", &val);
			if(arr[val]) continue;
			arr[val] = true;
			if(arr[val-1])
				cnt++;
			if(arr[val+1])
				cnt++;
			if(cnt == 0) ans++;
			else if(cnt == 2) ans--;
			else continue;
		}
		else
			printf("%d\n", ans);
	}
	return 0;
}
