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
    区間は[l, r)であることに注意
    string型は SegMin seg(vector<char>(S.begin(), S.end())); のようにする
*/

template <typename T>
struct SegMin {
    vector<T> value;
    int offset;
    SegMin(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, std::numeric_limits<T>::max());
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = min(value[i * 2], value[i * 2 + 1]);
    }
    void Update(int idx, T x) {
        int i = idx + offset; value[i] = x;
        while (i > 1) { i >>= 1; value[i] = min(value[i * 2], value[i * 2 + 1]); }
    }
    T Solve(int l, int r) {
        l += offset; r += offset; T res = numeric_limits<T>::max();
        while (l < r) {
            if (l & 1) res = min(res, value[l++]);
            if (r & 1) res = min(res, value[--r]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
    int SolveIndex(int l, int r) {
        T s = Solve(l, r);
        l += offset; r += offset; int i;
        while (l < r) {
            if (l & 1 && value[l++] == s) { i = l-1; break; }
            if (r & 1 && value[--r] == s) i = r;
            l >>= 1; r >>= 1;
        }
        while (i < offset) if (value[i*2] == s) i *= 2; else i = i*2+1;
        return i - offset;
    }
};

template <typename T>
struct SegSum {
    vector<T> value;
    int offset;
    SegSum(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, 0);
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = value[i * 2] + value[i * 2 + 1];
    }
    void Update(int idx, T x) {
        int i = idx + offset; value[i] = x;
        while (i > 1) { i >>= 1; value[i] = value[i * 2] + value[i * 2 + 1]; }
    }
    T Solve(int l, int r) {
        l += offset; r += offset; T res = 0;
        while (l < r) {
            if (l & 1) res += value[l++];
            if (r & 1) res += value[--r];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

template <typename T>
struct LazySegAssignMin {
    vector<T> value, lazy;
    int offset;
    LazySegAssignMin(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, std::numeric_limits<T>::max());
        lazy.assign(offset * 2, std::numeric_limits<T>::max());
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = min(value[i * 2], value[i * 2 + 1]);
    }
    void Push(int k) {
        if (lazy[k] == std::numeric_limits<T>::max()) return;
        value[k] = lazy[k];
        if (k < offset) {
            lazy[k*2] = lazy[k];
            lazy[k*2+1] = lazy[k];
        }
        lazy[k] = std::numeric_limits<T>::max();
    }
    void Assign(int a, int b, T x, int k, int l, int r) {
        Push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) { lazy[k] = x; Push(k); return; }
		Assign(a, b, x, k * 2, l, (l + r) / 2);
		Assign(a, b, x, k * 2 + 1, (l + r) / 2, r);
		value[k] = min(value[k*2], value[k*2+1]);
    }
    void Assign(int l, int r, T x) {
        Assign(l, r, x, 1, 0, offset);
    }
	T Solve(int a, int b, int k, int l, int r) {
		Push(k);
		if (r <= a || b <= l) return numeric_limits<T>::max();
		if (a <= l && r <= b) return value[k];
		T lc = Solve(a, b, k*2, l, (l + r) >> 1);
		T rc = Solve(a, b, k*2+1, (l + r) >> 1, r);
		return min(lc, rc);
    }
    T Solve(int l, int r) {
        return Solve(l, r, 1, 0, offset);
    }
};

template <typename T>
struct LazySegAddMin {
    vector<T> value, lazy;
    int offset;
    LazySegAddMin(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, std::numeric_limits<T>::max());
        lazy.assign(offset * 2, 0);
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = min(value[i * 2], value[i * 2 + 1]);
    }
    void Push(int k) {
        if (lazy[k] == 0) return;
        value[k] += lazy[k];
        if (k < offset) {
            lazy[k*2] += lazy[k];
            lazy[k*2+1] += lazy[k];
        }
        lazy[k] = 0;
    }
    void Add(int a, int b, T x, int k, int l, int r) {
        Push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) { lazy[k] += x; Push(k); return; }
		Add(a, b, x, k * 2, l, (l + r) / 2);
		Add(a, b, x, k * 2 + 1, (l + r) / 2, r);
		value[k] = min(value[k*2], value[k*2+1]);
    }
    void Add(int l, int r, T x) {
        Add(l, r, x, 1, 0, offset);
    }
	T Solve(int a, int b, int k, int l, int r) {
		Push(k);
		if (r <= a || b <= l) return numeric_limits<T>::max();
		if (a <= l && r <= b) return value[k];
		T lc = Solve(a, b, k*2, l, (l + r) >> 1);
		T rc = Solve(a, b, k*2+1, (l + r) >> 1, r);
		return min(lc, rc);
    }
    T Solve(int l, int r) {
        return Solve(l, r, 1, 0, offset);
    }
};

template <typename T>
struct LazySegAssignSum {
    vector<T> value, lazy;
    int offset;
    LazySegAssignSum(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, 0);
        lazy.assign(offset * 2, std::numeric_limits<T>::max());
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = value[i * 2] + value[i * 2 + 1];
    }
    void Push(int k, int l, int r) {
        if (lazy[k] == std::numeric_limits<T>::max()) return;
        value[k] = lazy[k]*(r-l);
        if (k < offset) {
            lazy[k*2] = lazy[k];
            lazy[k*2+1] = lazy[k];
        }
        lazy[k] = std::numeric_limits<T>::max();
    }
    void Assign(int a, int b, T x, int k, int l, int r) {
        Push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) { lazy[k] = x; Push(k, l, r); return; }
		Assign(a, b, x, k * 2, l, (l + r) / 2);
		Assign(a, b, x, k * 2 + 1, (l + r) / 2, r);
		value[k] = value[k*2] + value[k*2+1];
    }
    void Assign(int l, int r, T x) {
        Assign(l, r, x, 1, 0, offset);
    }
	T Solve(int a, int b, int k, int l, int r) {
		Push(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return value[k];
		T lc = Solve(a, b, k*2, l, (l + r) >> 1);
		T rc = Solve(a, b, k*2+1, (l + r) >> 1, r);
		return lc + rc;
    }
    T Solve(int l, int r) {
        return Solve(l, r, 1, 0, offset);
    }
};

template <typename T>
struct LazySegAddSum {
    vector<T> value, lazy;
    int offset;
    LazySegAddSum(vector<T> v) {
        offset = static_cast<int>(bit_ceil((size_t)v.size()));
        value.assign(offset * 2, 0);
        lazy.assign(offset * 2, 0);
        FOR(i, v.size()) value[i + offset] = v[i];
        for (int i = offset - 1; i > 0; i--) value[i] = value[i * 2] + value[i * 2 + 1];
    }
    void Push(int k, int l, int r) {
        if (lazy[k] == 0) return;
        value[k] += lazy[k]*(r-l);
        if (k < offset) {
            lazy[k*2] += lazy[k];
            lazy[k*2+1] += lazy[k];
        }
        lazy[k] = 0;
    }
    void Add(int a, int b, T x, int k, int l, int r) {
        Push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) { lazy[k] += x; Push(k, l, r); return; }
		Add(a, b, x, k * 2, l, (l + r) / 2);
		Add(a, b, x, k * 2 + 1, (l + r) / 2, r);
		value[k] = value[k*2] + value[k*2+1];
    }
    void Add(int l, int r, T x) {
        Add(l, r, x, 1, 0, offset);
    }
	T Solve(int a, int b, int k, int l, int r) {
		Push(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return value[k];
		T lc = Solve(a, b, k*2, l, (l + r) >> 1);
		T rc = Solve(a, b, k*2+1, (l + r) >> 1, r);
		return lc + rc;
    }
    T Solve(int l, int r) {
        return Solve(l, r, 1, 0, offset);
    }
};

