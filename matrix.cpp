#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353
#define FOR(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define mp(a, b) make_pair(a, b)

template <typename T>
vector<vector<T>>& Mul(const vector<vector<T>> &A, const vector<vector<T>> &B) {
    int k = A.size();
    static vector<vector<T>> C(k, vector<T>(k, T{}));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            for (int l = 0; l < k; l++)
                C[i][j] += A[i][l] * B[l][j];
    return C;
}

template <typename T>
vector<T>& Mul(const vector<vector<T>> &A, const vector<T> &B) {
    int k = A.size();
    static vector<T> C(k, T{});
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i] += A[i][j] * B[j];
    return C;
}

template <typename T>
vector<vector<T>>& Pow(vector<vector<T>> A, long long n) {
    int k = A.size();
    static vector<vector<T>> res(k, vector<T>(k, T{}));
    for (int i = 0; i < k; i++) res[i][i] = T{1};
    while (n > 0) {
        if (n & 1) res = Mul(res, A);
        A = Mul(A, A);
        n >>= 1;
    }
    return res;
}