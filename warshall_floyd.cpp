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
    ワーシャル・フロイド法
    全頂点どうしの最短距離を求める
    オーダー:
    ・AddEdges          : 初期値として辺を追加する O(1)
    ・Build             : 最短の隣接行列を構築する O(V^3)
    ・AddEdgesAndUpdate : 計算済みの最短隣接行列に対し，辺を追加して更新する O(Q * V^2)    
*/

struct Warshall_Floyd {
    vector<vector<ll>> dist;
    Warshall_Floyd(int n) { dist.assign(n, vector<ll>(n, LLONG_MAX)); FOR(i, n) dist[i][i] = 0; }
    void AddEdges(int a, int b, ll c) { dist[a][b] = min(dist[a][b], c); }
    void Build() {
        int n = dist.size();
        FOR(k, n) FOR(i, n) FOR(j, n) {
            ll d = (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX ? LLONG_MAX : dist[i][k] + dist[k][j]);
            dist[i][j] = min(dist[i][j], d);
        }
    }
    void AddEdgesAndUpdate(int a, int b, ll c) {
        int n = dist.size();
        FOR(i, n) FOR(j, n) {
            ll d = ((dist[i][a] == LLONG_MAX || dist[b][j] == LLONG_MAX) ? LLONG_MAX : dist[i][a] + c + dist[b][j]);
            dist[i][j] = min(dist[i][j], d);
        }
    }
};
