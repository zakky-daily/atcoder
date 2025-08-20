#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

ll MODINV(ll a) {
	ll b = MOD, u = 1, v = 0;
	while (b) { ll t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
	u %= MOD; if (u < 0) u += MOD;
	return u;
}
