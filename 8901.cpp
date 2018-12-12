#include <iostream>
#include <algorithm>
using namespace std;

int ab, bc, ca;
int price[3];
int AB, BC, CA;	//number of ab, bc, ca, total materials
int x, y, z;	//number of A, B, C

int main(int T, int a, int b, int c) {
	for(scanf("%d", &T); T--;) {
		cin>>a>>b>>c;		//number of materials
		cin>>price[0]>>price[1]>>price[2];	//price of ab, bc, ca

		//let AB = i, BC = j, then CA = min(a-i,c-j)
		//let AB = i,then BC = min(b-i,c), then CA = min(a-i,c-min(b-i,c))
		int ans = 0;
		for(int i = 0; i<=min(a, b); i++) {
			for(int j = 0; j<=min(b-i, c); j++) {
				int tmp = min(a-i, c-j);
				ans = max(ans, price[0]*i+price[1]*j+price[2]*tmp);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
