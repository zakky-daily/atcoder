#include <bits/stdc++.h>
using namespace std;

random_device seed_gen;
mt19937_64 engine(seed_gen());  // engine(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define MOD 998244353  // 1000000007
#define FOR(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a; i > b; i--)
#define PRINTVW(v) FOR(i,(int)v.size()) cout<<v[i]<<(i==v.size()-1 ? "\n" : " ");
#define PRINTVH(v) for (auto &_v : v) cout << _v << endl;
#define PRINTVV(v) FOR(i,(int)v.size()) FOR(j,(int)v[i].size()) cout<<v[i][j]<<(j==v[i].size()-1 ? "\n" : " ");
#define YN(c) (c ? "Yes" : "No")
#define DOUT(i, j, h, w) !(0 <= i && i < h && 0 <= j && j < w)
#define mp(a, b) make_pair(a, b)
const int DI[] = {-1, 0, 1, 0};
const int DJ[] = {0, 1, 0, -1};
const char DC[] = {'U', 'R', 'D', 'L'};

/*
    二分探索法
    オーダー: O(log N)

    広義短調増加の場合の考えかた
    ・最小インデックス
    if (f[mid] >= p) {  // 基準よりも大きいか「同じ」なら↓
        r = mid;        // まだ小さいものがあるかもしれない
    } else {
        l = mid;
    }
    このとき，【r】はpと同じ値があればその最小インデックス，なければpよりも大きい最小の数

    ・最大インデックス
    if (f[mid] <= p) {  // 基準よりも小さいか「同じ」なら↓
        l = mid;        // まだ大きいものがあるかもしれない
    } else {
        r = mid;
    }
    このとき，【l】はpと同じ値があればその最大インデックス，なければpよりも小さい最大の数

    ・最大インデックスは，最小インデックスにて基準p+1，取得r-1としても問題ない
*/

int main() {

    // 調べる範囲は(l, r)．1だけ外側を初期値にする
    int l = -1;
    int r = N;
    while (r - l > 1) {

        int mid = (l + r) / 2;

        // 処理

        if ( /* 条件を満たすなら */ ) {
            l = mid;  // 範囲を狭める方向．r = h とどっちか判定する
        } else {
            r = mid;  // 範囲を狭める方向．l = h どどっちか判定する
        }
    }

    // 探索結果は，条件を満たすときに狭めた側 (上記の if-true 内でlにしたならl，rにしたならr)
}
