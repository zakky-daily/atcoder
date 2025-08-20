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
    ベルマン・フォード法
    1点から1点までの最短距離．辺のコストが負にも対応する
    オーダー: O(V(V+E))

    返却されるのは，頂点start_indexからの最短距離のリストと，負のループが存在しないかどうか．

    ** 注意 **
    ベルマン・フォードは有向辺だからAddEdgesは1回のみ
    1-index / 0-index に注意する
*/

struct Edge { int to; ll cost; };
struct Graph {
    vector<vector<Edge>> edges;
    Graph(int n) { edges.resize(n); }
    void AddEdges(int from, int to, ll cost = 0) { edges[from].push_back({ to, cost }); }
};

vector<ll>& Bellman_Ford(Graph &graph, bool &has_negative_cycle, int start_index = 0) {
    int N = graph.edges.size();
    static vector<ll> res(N, LLONG_MAX);
    res[start_index] = 0;
    int i; for (i = 1; i < N; i++) {
        bool flag = true;
        REP(from, 1, N) {
            for (auto &e : graph.edges[from]) {
                if (res[from] != LLONG_MAX && res[from] + e.cost < res[e.to]) {
                    res[e.to] = res[from] + e.cost;
                    flag = false;
                }
            }
        }
        if (flag) break;
    }
    has_negative_cycle = (i == N); return res;
}

vector<ll>& Bellman_Ford_0_index(Graph &graph, bool &has_negative_cycle, int start_index = 0) {
    int N = graph.edges.size();
    static vector<ll> res(N, LLONG_MAX);
    res[start_index] = 0;
    int i; for (i = 0; i < N; i++) {
        bool flag = true;
        FOR(from, N) {
            for (auto &e : graph.edges[from]) {
                if (res[from] != LLONG_MAX && res[from] + e.cost < res[e.to]) {
                    res[e.to] = res[from] + e.cost;
                    flag = false;
                }
            }
        }
        if (flag) break;
    }
    has_negative_cycle = (i == N); return res;
}
