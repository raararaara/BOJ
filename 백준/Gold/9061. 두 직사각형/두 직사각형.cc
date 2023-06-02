#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using lint = long long;
using ii = pair<int, int>;
using il = pair<int, lint>;
using li = pair<lint, int>;
using ll = pair<lint, lint>;

const int mxn = 101, mxp = 1000001;
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
vector<ll> v;

lint res;
void f() {
    if(int(size(v)) <= 2) {
        res = 0;
        return;
    }
    sort(all(v));
    vector<lint> mxY(N, -30001), mnY(N, 30001);
    vector<lint> pmx(N, -30001), pmn(N, 30001), smx(N, -30001), smn(N, 30001);

    for(int i = 0; i < N; i++) {
        auto &it = v[i];

        mxY[i] = max(mxY[i], it.second);
        mnY[i] = min(mnY[i], it.second);
    }

    pmx[0] = mxY[0];
    pmn[0] = mnY[0];
    for(int i = 1; i < N; i++) {
        pmx[i] = max(pmx[i-1], mxY[i]);
        pmn[i] = min(pmn[i-1], mnY[i]);
    }

    smx[N-1] = mxY[N-1];
    smn[N-1] = mnY[N-1];
    for(int i = N - 2; ~i; i--) {
        smx[i] = max(smx[i+1], mxY[i]);
        smn[i] = min(smn[i+1], mnY[i]);
    }

    for(int i = 0; i < N-1; i++) {
        lint lft = (v[i].first - v[0].first) * (pmx[i] - pmn[i]);
        lint rgt = (v[N-1].first - v[i+1].first) * (smx[i+1] - smn[i+1]);
        res = min(res, max(lft, rgt));
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
    cin >> T;

    while (T--) {
        cin >> N;
        v.resize(N);
        res = LNF;
        for(ll &it: v) {
            cin >> it.first >> it.second;
        }
        f();
        for(ll &it: v) {
            swap(it.first, it.second);
        }
        f();

        cout << res << '\n';

        v.clear();
    }

    return 0;
}
