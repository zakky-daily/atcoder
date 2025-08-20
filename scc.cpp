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
#define mp(a, b) make_pair(a, b)


/*
    scc(強連結成分分解) ... 有向グラフにおいて，互いに行き来出来る頂点同士の集合を求める (Tarjanのアルゴリズム)
    例: 1 ⇆ 2 → 3  ->  {{1, 2}, {3}}

    オーダー: O(N)
    返却されるsccの列はトポロジカルソートの逆順になる
    自己ループ，多重辺，非連結グラフに対応する
*/


struct Edge { int to; ll cost; };
struct Graph {
    vector<vector<Edge>> edges;
    Graph(int n) { edges.resize(n); }
    void AddEdges(int from, int to, ll cost = 0) { edges[from].push_back({ to, cost }); }
};

vector<vector<int>>& scc(Graph &g) {
    int n = g.edges.size();
    vector<int> index(n, -1), lowlink(n, -1); vector<bool> on_stack(n); stack<int> st;
    static vector<vector<int>> res;
    int current_index = 0;
    function<void(int)> dfs = [&](int v) {
        index[v] = lowlink[v] = current_index++;
        st.push(v); on_stack[v] = true;
        for (const auto &e : g.edges[v]) {
            int to = e.to;
            if (index[to] == -1) { dfs(to); lowlink[v] = min(lowlink[v], lowlink[to]); }
            else if (on_stack[to]) lowlink[v] = min(lowlink[v], index[to]);
        }
        if (lowlink[v] == index[v]) {
            vector<int> component;
            while (true) {
                int u = st.top(); st.pop();
                on_stack[u] = false; component.push_back(u);
                if (u == v) break;
            }
            res.push_back(component);
        }
    };
    for (int v = 0; v < n; v++) if (index[v] == -1) dfs(v);
    return res;
}
