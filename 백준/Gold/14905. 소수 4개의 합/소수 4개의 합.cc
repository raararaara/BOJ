#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using lint = long long;
using ii = pair<int, int>;
using il = pair<int, lint>;
using li = pair<lint, int>;
using ll = pair<lint, lint>;

const int mxn = 1e8+1, mxp = 1000001;
const int MOD = 998244353, inf = -1e9 - 7, INF = 1e9 + 1;
const lint lnf = -4e18, LNF = 1e18;
const double eps = 1e-10;
const int sqrtN = 200;

#define fst(x) (x).begin()
#define all(x) (x).begin(),(x).end()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define lb(x, v) (lower_bound(all(x), v) - (x).begin())
vector<lint> xl, yl;

#define Yes "Yes\n"
#define No "No\n"

int N, M, Q, R, C, H, K, st, en;
int spf[mxn];
vector<int> pList;

void sieve() {
    for (int i = 2; i < mxn; i++) {
        if(!spf[i]) {
            pList.emplace_back(i);
            spf[i] = i;
        }
        for (int j = 0; i * pList[j] < mxn; j++) {
            spf[i * pList[j]] = pList[j];
            if (i % pList[j] == 0) break;
        }
    }
}

void f(int n) {
    for(int i = 0;;i++) {
        if(pList[i] > n) break;
        for(int j = i;; j++) {
            if(pList[i] + pList[j] > n) break;
            if(pList[i] + pList[j] == n) {
                cout << pList[i] << ' ' << pList[j] << '\n';
                return;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;

    sieve();
//    while (T--) {
    while(cin >> N) {
        K = 4;
        if(N < 8) {
            cout << "Impossible.\n";
            continue;
        } else if(N >= 100) {
            int l = lb(pList, N - 100);
            N -= pList[l];
            cout << pList[l]<< ' ';
        } else {
            cout << "2 ";
            N -= 2;
        }

        if(N&1) {
            cout << "3 ";
            N -= 3;
        } else {
            cout << "2 ";
            N -= 2;
        }

        assert(N%2 == 0);
        f(N);
    }

    return 0;
}
