#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for (auto i = 0; i < (n); ++i)
#define rrep(i, n) for (auto i = (n)-1; i >= 0; --i)
#define fastio                             \
  {                                        \
    ios::ios_base::sync_with_stdio(false); \
    cin.tie(0);                            \
    cout.tie(0);                           \
  }

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
using pid = pair<int, double>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

/* operators of std::pair<T1, T2> */
template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return { x.first + y.first, x.second + y.second };
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return { x.first - y.first, x.second - y.second };
}
template <class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template <class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}

/* operators of std::vector<T> */
template <class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template <class T>
istream &operator>>(istream &i, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    i >> (*it);
  }
  return i;
}
void solve();
void preproc();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  preproc();
  while (T-- > 0) solve();
}

/* actual code */

const int sz = 1 << 12;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

struct Seg {
  ll l_mx;
  ll r_mx;
  ll mx;
  ll sum;
} tree[sz << 1];

void update(int n, ll v, int p = 1, int s = 0, int e = sz - 1) {
  int m = (s + e) >> 1;
  if (s == e) {
    tree[p] = { tree[p].l_mx + v, tree[p].r_mx + v, tree[p].mx + v, tree[p].sum + v };
    return;
  }
  if (n <= m) {
    update(n, v, p * 2, s, m);
  } else {
    update(n, v, p * 2 + 1, m + 1, e);
  }
  tree[p].l_mx = max(tree[p * 2].l_mx, tree[p * 2].sum + tree[p * 2 + 1].l_mx);
  tree[p].r_mx = max(tree[p * 2 + 1].r_mx, tree[p * 2 + 1].sum + tree[p * 2].r_mx);
  tree[p].mx = max(tree[p * 2].r_mx + tree[p * 2 + 1].l_mx, max(tree[p * 2].mx, tree[p * 2 + 1].mx));
  tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}

Seg query(int l, int r, int p = 1, int s = 0, int e = sz - 1) {
  if (l <= s && e <= r) {
    return tree[p];
  } else if (r < s || e < l || r < l) {
    return { -INF, -INF, -INF, 0 };
  }
  int m = (s + e) >> 1;
  Seg l_node = query(l, r, p * 2, s, m);
  Seg r_node = query(l, r, p * 2 + 1, m + 1, e);
  Seg ret;
  ret.l_mx = max(l_node.l_mx, l_node.sum + r_node.l_mx);
  ret.r_mx = max(r_node.r_mx, r_node.sum + l_node.r_mx);
  ret.mx = max(l_node.r_mx + r_node.l_mx, max(l_node.mx, r_node.mx));
  ret.sum = l_node.sum + r_node.sum;
  return ret;
}

void preproc() {
}

void solve() {
  int N;
  cin >> N;
  vector<pll> P(N);
  vector<ll> W(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i].fi >> P[i].se;
    cin >> W[i];
  }
  vector<ll> Cx;
  vector<ll> Cy;
  for (auto &[x, y] : P) {
    Cx.push_back(x);
    Cy.push_back(y);
  }
  sort(all(Cx));
  sort(all(Cy));
  Cx.erase(unique(all(Cx)), Cx.end());
  Cy.erase(unique(all(Cy)), Cy.end());
  vector<vector<pll>> vec(N + 1);
  for (int i = 0; i < N; ++i) {
    auto &[x, y] = P[i];
    x = lower_bound(all(Cx), x) - Cx.begin() + 1;
    y = lower_bound(all(Cy), y) - Cy.begin() + 1;
    vec[x].emplace_back(y, W[i]);
  }
  ll ans = -INF;
  for (int i = 1; i <= Cx.size(); ++i) {
    for (int j = i; j <= Cx.size(); ++j) {
      for (auto [y, w] : vec[j]) {
        update(y, w);
      }
      ans = max(ans, query(0, sz - 1).mx);
    }

    for (int j = i; j <= Cx.size(); ++j) {
      for (auto [y, w] : vec[j]) {
        update(y, -w);
      }
    }
  }
  cout << ans << "\n";
}