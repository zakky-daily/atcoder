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


// vector型

struct Graph_vector {

    struct Edge { int to; ll cost; };
    struct Graph {
        vector<vector<Edge>> edges;
        Graph(int n) { edges.resize(n); }
        void AddEdges(int from, int to, ll cost = 0) { edges[from].push_back({ to, cost }); }
    };
};


// set型(Union-Find等に)

struct Graph_set {

    struct Edge {
        int to, cost;
        bool operator<(const Edge& other) const { return mp(cost, to) < mp(other.cost, other.to); }
    };

    struct Graph {
        vector<set<Edge>> edges;
        Graph(int n) { edges.resize(n); }
        void AddEdges(int from, int to, int cost = 0) { edges[from].insert({ to, cost }); }
    };
};


