#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int n;
string number[50];
string bigInt(string num1, string num2) {
	int tmp = 0;
	string res;
	while(!num1.empty() || !num2.empty() || tmp) {
		if(!num1.empty()) {
			tmp += num1.back() - '0';
			num1.pop_back();
		}
		if(!num2.empty()) {
			tmp += num2.back() - '0';
			num2.pop_back();
		}
		res.push_back((tmp%10) + '0');
		tmp /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
void hanoi(int num, int from, int by, int to) {
	if(num == 1) printf("%d %d\n", from, to);
	else {
		hanoi(num-1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(num-1, by, from, to);
	}
}

int main() {
	scanf("%d", &n);
	if(n <= 20) {
		printf("%lld\n", (long long)pow(2, n)-1);
		hanoi(n, 1, 2, 3);
	}
	else {
		string num = "2";
		for(int i = 0; i<n-1; i++) {
			string tmp = bigInt(num, num);
			num = tmp;
		}
		int back = num.back() -'0'; back--;
		num.pop_back();
		num.push_back(back + '0');
		cout<<num<<endl;
		//hanoi(n, 1, 2, 3);
	}
	return 0;
}
