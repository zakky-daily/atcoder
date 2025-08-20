#include <bits/stdc++.h>
using namespace std;

// int型
struct UnionFind {
    vector<int> parents; vector<int> size; int allGroupCount;
    UnionFind(int n) {parents.assign(n, -1); size.assign(n, 1); allGroupCount = n;}
    int Root(int x) {if (parents[x] == -1) return x; else return parents[x] = Root(parents[x]);}
    bool IsSame(int x, int y) {return Root(x) == Root(y);}
    void Unite(int x, int y) {x = Root(x); y = Root(y); if (x == y) return; if (size[x] < size[y]) swap(x, y); parents[y] = x; size[x] += size[y]; allGroupCount--;}
};

// 任意型
template <typename T>
struct UnionFind2 {
    map<T, T> parents; map<T, int> size; int allGroupCount = 0;
    void Add(T x) { parents[x] = -1; size[x] = 1; allGroupCount++; }
    T Root(T x) {if (parents[x] == -1) return x; else return parents[x] = Root(parents[x]);}
    bool IsSame(T x, T y) {return Root(x) == Root(y);}
    void Unite(T x, T y) {x = Root(x); y = Root(y); if (x == y) return; if (size[x] < size[y]) swap(x, y); parents[y] = x; size[x] += size[y]; allGroupCount--;}
};
