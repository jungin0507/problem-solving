#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define INF 987654321
#define vi vector<int>
#define sq(x) ((x) * (x))
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int sz = 1 << 17;
const ll MOD = 1e9 + 7;
int N, M;
ll tree[sz << 1];
ll lazy[2][sz << 1];

void update_lazy(int p, int s, int e) {
  tree[p] = (tree[p] * lazy[0][p]) % MOD + ((e - s + 1) * lazy[1][p]) % MOD;
  tree[p] %= MOD;

  if (s != e) {
    lazy[0][p * 2] *= lazy[0][p];
    lazy[1][p * 2] = lazy[1][p * 2] * lazy[0][p] + lazy[1][p];
    lazy[0][p * 2 + 1] *= lazy[0][p];
    lazy[1][p * 2 + 1] = lazy[1][p * 2 + 1] * lazy[0][p] + lazy[1][p];
    lazy[0][p * 2] %= MOD;
    lazy[1][p * 2] %= MOD;
    lazy[0][p * 2 + 1] %= MOD;
    lazy[1][p * 2 + 1] %= MOD;
  }
  lazy[0][p] = 1;
  lazy[1][p] = 0;
}

void update(int l, int r, pll v, int p = 1, int s = 0, int e = sz - 1) {
  update_lazy(p, s, e);
  if (l <= s && e <= r) {
    ll a = v.first;
    ll b = v.second;
    tree[p] = (tree[p] * a) % MOD + ((e - s + 1) * b) % MOD;
    tree[p] %= MOD;
    if (s != e) {
      lazy[0][p * 2] *= a;
      lazy[1][p * 2] = lazy[1][p * 2] * a + b;
      lazy[0][p * 2 + 1] *= a;
      lazy[1][p * 2 + 1] = lazy[1][p * 2 + 1] * a + b;
      lazy[0][p * 2] %= MOD;
      lazy[1][p * 2] %= MOD;
      lazy[0][p * 2 + 1] %= MOD;
      lazy[1][p * 2 + 1] %= MOD;
    }
    return;
  } else if (r < s || e < l || r < l) {
    return;
  }
  int m = (s + e) >> 1;
  update(l, r, v, p * 2, s, m);
  update(l, r, v, p * 2 + 1, m + 1, e);
  tree[p] = tree[p * 2] + tree[p * 2 + 1];
  tree[p] %= MOD;
}

ll query(int l, int r, int p = 1, int s = 0, int e = sz - 1) {
  update_lazy(p, s, e);
  if (l <= s && e <= r) {
    return tree[p] % MOD;
  } else if (r < s || e < l || r < l) {
    return 0;
  }
  int m = (s + e) >> 1;
  ll ret = query(l, r, p * 2, s, m) + query(l, r, p * 2 + 1, m + 1, e);
  ret %= MOD;
  return ret;
}

void solve() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    ll A;
    cin >> A;
    update(i, i, pll{0, A});
  }
  cin >> M;
  while (M--) {
    int q;
    int x, y;
    ll v;
    cin >> q >> x >> y;
    if (q == 4) {
      cout << query(x, y) << "\n";
      continue;
    }
    pll val = {0, 0};
    cin >> v;
    if (q == 1) {
      val = {1, v};
    } else if (q == 2) {
      val = {v, 0};
    } else if (q == 3) {
      val = {0, v};
    }
    update(x, y, val);
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}