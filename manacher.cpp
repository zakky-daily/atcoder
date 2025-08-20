#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353
#define FOR(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define PRINTVW(v) for (auto &_v : v) cout << _v << " "; cout << endl;
#define PRINTVH(v) for (auto &_v : v) cout << _v << endl;
#define PRINTVV(v) for (auto &_v : v) { for (auto &__v : _v) cout << __v << " "; cout << endl; }
#define YN(c) (c ? "Yes" : "No")
#define DRANGE(x, y, w, h) 0 <= x && x < w && 0 <= y && y < h
#define mp(a, b) make_pair(a, b)
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

/*
    回文判定アルゴリズム
    文字iを中心とする最長の回文の半径を記録している

    例:
    abaaababa
    ↓
    .a.b.a.a.a.b.a.b.a.
    0103012721030503010
*/

vector<int>& Manacher(string _S) {
    string S = "."; for (auto s : _S) S += s, S += '.';
    int S_len = S.size();
    static vector<int> res(S_len);
    int i = 0, j = 0;
    while (i < S_len) {
        while (i - j >= 0 && i + j < S_len && S[i - j] == S[i + j]) j++;
        res[i] = j - 1; int k = 1;
        while (i - k >= 0 && k + res[i - k] + 1 < j) res[i + k] = res[i - k], k++;
        i += k; j -= k;
    }
    return res;
}

