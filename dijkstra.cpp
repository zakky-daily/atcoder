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
    ダイクストラ法
    1点から1点までの最短距離．辺のコストは非負整数のみ
    オーダー: O((V+E)logV)

    返却されるのは，頂点start_indexからの最短距離のリスト．

    **  1-index の時は start_index = 1, 0-index の時は start_index = 0 にすること!!  **
*/

struct Edge { int to; ll cost; };
struct Graph {
    vector<vector<Edge>> edges;
    Graph(int n) { edges.resize(n); }
    void AddEdges(int from, int to, ll cost = 0) { edges[from].push_back({ to, cost }); }
};

vector<ll>& Dijkstra(Graph &graph, int start_index = 1) {
    auto comp = [](Edge &a, Edge &b) -> bool { return a.cost > b.cost; };
    int N = graph.edges.size();
    priority_queue<Edge, vector<Edge>, decltype(comp)> que(comp);
    que.push({ start_index, 0 });
    static vector<ll> res(N, LLONG_MAX);
    while (!que.empty()) {
        Edge target = que.top(); que.pop();
        if (target.cost < res[target.to]) {
            res[target.to] = target.cost;
            for (auto &e : graph.edges[target.to]) que.push({ e.to, e.cost + target.cost });
        }
    }
    return res;
}

