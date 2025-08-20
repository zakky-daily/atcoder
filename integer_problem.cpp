#include <bits/stdc++.h>
using namespace std;

random_device seed_gen;
mt19937_64 engine(seed_gen());  // engine(0);
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353  // 1000000007
#define FOR(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a; i > b; i--)
#define PRINTVW(v) FOR(i,(int)v.size()) cout<<v[i]<<(i==v.size()-1 ? "\n" : " ");
#define PRINTVH(v) for (auto &_v : v) cout << _v << endl;
#define PRINTVV(v) FOR(i,(int)v.size()) FOR(j,(int)v[i].size()) cout<<v[i][j]<<(j==v[i].size()-1 ? "\n" : " ");
#define YN(c) (c ? "Yes" : "No")
#define DRANGE(x, y, w, h) 0 <= x && x < w && 0 <= y && y < h
#define mp(a, b) make_pair(a, b)
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char DC[] = {'U', 'R', 'D', 'L'};


// 素因数分解(1回) | オーダー: O(sqrt(n))  * 素数判定にも使える  * n=1のときは空のmapを返す
map<ll, int>& PrimeFactorization(ll n) {
    static map<ll, int> res;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        while (n % p == 0) { res[p]++; n /= p; }
    }
    if (n > 1) res[n] = 1;
    return res;
}

// spf(1〜nのそれぞれにおける最小の素因数)を求める | オーダー: O(n loglog n)
vector<int>& SPF(int n) {
    static vector<int> res(n + 1);
    for (int i = 0; i <= n; i++) res[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (res[i] == i) for (int j = i * i; j <= n; j += i) if (res[j] == j) res[j] = i;
    }
    return res;
}

// 素因数分解(複数クエリ) | オーダー: O(n loglog n + Q log n)  * n=1のときは空のmapを返す
map<int, int>& PrimeFactorizations(int n, vector<int> &spf) {
    static map<int, int> res;
    while (n != 1) { res[spf[n]]++; n /= spf[n]; }
    return res;
}

// n以下の素数列挙(エラトステネスの篩) | オーダー: O(n loglog n + n)
set<int>& PrimeList(int n, vector<int> &spf) {
    static set<int> res;
    REP(i, 2, n + 1) if (spf[i] == i) res.insert(i);
    return res;
}

// l以上r以下の素数列挙 -> AtCoder ABC 412-E参照

// nの約数を総列挙する(1回) | オーダー: O(sqrt(n))
set<ll>& Divisor(ll n) {
    static set<ll> res;
    for (ll p = 1; p * p <= n; p++) {
        if (n % p != 0) continue;
        res.insert(p); res.insert(n / p);
    }
    return res;
}

// 1〜nの各数についてその約数を列挙する | オーダー: O(n log n)
vector<set<ll>>& Divisors(int n) {
    static vector<set<ll>> res(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            res[j].insert(i);
        }
    }
    return res;
}

// 1〜nまでの各数の約数の個数の総和を求める | オーダー: O(sqrt(n))
// 言い換え: sum_{k=1}^n{floor(N/k)}を高速に求める
ll DivisorsCountSum(ll N) {
    ll res = 1;
    for (ll i = 1; i <= N; ) {
        ll q = N / i; ll j = N / q;
        res += (j - i + 1) * q;
        i = j + 1;
    }
    return res;
}

// 1〜nまでの階乗を求める | オーダー: O(n)
vector<ll>& Factorials(int N) {
    static vector<ll> ans; ll r = 1;
    FOR(i, N + 1) {
        ans.push_back(r);
        r = (r * (i + 1)) % MOD;
    }
    return ans;
}

// コンビネーションを求める | オーダー: O(log n)
ll MODINV(ll a) {
	ll b = MOD, u = 1, v = 0;
	while (b) { ll t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
	u %= MOD; if (u < 0) u += MOD;
	return u;
}

ll Combination(int n, int r, vector<ll> &factorials) {
    return ((factorials[n] * MODINV(factorials[r])) % MOD * MODINV(factorials[n - r])) % MOD;
}

// 最大公約数 ... __gcd(a, b)で求められる | オーダー: O(log a)


