#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int n, arr[MAX];

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int sum = 0;
    for(int j = 0; j<n;j++){
        sum += arr[j];
        if(sum < j * (j+1) / 2) {
            printf("-1\n");
            return 0;
        }
    }
    if(sum == n*(n-1)/2)
        printf("1\n");
    else printf("-1\n");

	return 0;
}
