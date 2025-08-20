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
#define PRINTVW(v) for (auto &_v : v) cout << _v << " "; cout << endl;
#define PRINTVH(v) for (auto &_v : v) cout << _v << endl;
#define PRINTVV(v) for (auto &_v : v) { for (auto &__v : _v) cout << __v << " "; cout << endl; }
#define YN(c) (c ? "Yes" : "No")
#define DRANGE(x, y, w, h) 0 <= x && x < w && 0 <= y && y < h
#define mp(a, b) make_pair(a, b)
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char DC[] = {'U', 'R', 'D', 'L'};

/*
    文字列Sの任意の連続部分列について，そのハッシュをO(1)で求められる
    区間は[l, r)
    (事前計算O(n))

    ** 使用時はmain関数の最初に Rolling_Hash::Init(文字列の最大長) をすること！！ **
*/

struct Rolling_Hash {
    static inline ll mod, base;
    static inline vector<ll> power;
    static void Init(int n) {
        const ll mods[5] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
        mod = mods[engine() % 5]; base = engine() % (mod - 1009) + 1009;
        power.resize(n + 1); power[0] = 1;
        FOR(i, n) power[i + 1] = (power[i] * base) % mod;
    }
    vector<ll> hash;
    Rolling_Hash(const string S) {
        int n = S.size();
        hash.resize(n + 1); hash[0] = 0;
        FOR(i, n) hash[i + 1] = ((hash[i] * base) % mod + S[i]) % mod;
    }
    ll Get(int l, int r) const { return (hash[r] - (hash[l] * power[r - l]) % mod + mod) % mod; }
    static ll Concat(const Rolling_Hash &h1, int h1_l, int h1_r, const Rolling_Hash &h2, int h2_l, int h2_r) {
        ll hash1 = h1.Get(h1_l, h1_r); ll hash2 = h2.Get(h2_l, h2_r);
        return ((hash1 * power[h2_r - h2_l]) % mod + hash2) % mod;
    }
};
