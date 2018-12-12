#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;
int T, k;
string A, B;
int lenA, lenB;
map <char, string> mapping;

bool alphabet[26];
bool realans = true;

void init() {
	A.clear(); B.clear();
	memset(alphabet, 0, sizeof(alphabet));
	mapping.clear();
}

bool backtr(int i1, int i2) {
	if (i1 == lenA && i2 == lenB) return true;
	if (i2 >= lenB) return false;
	bool ans = true, tmp = true;
	char ch = A[i1];

	if (!alphabet[ch - 'a']) {
		alphabet[ch - 'a'] = true;
		for (int i = 1; i <= k; ++i) {
			mapping[ch] = B.substr(i2, i);
			tmp = backtr(i1 + 1, i2 + i);
			if (tmp == true) break;
		}
		alphabet[ch - 'a'] = false;
		ans = tmp;
	}
	else {
		string mapped = mapping[ch];
		if (B.substr(i2, mapped.size()) == mapped)
			return backtr(i1 + 1, i2 + mapped.size());
		else {
			//alphabet[ch-'a'] = false;
			return false;
		}
	}
	return ans;
}

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &k);
		cin >> A >> B;

		lenA = A.size(), lenB = B.size();
		realans = backtr(0, 0);
		if (!realans) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
