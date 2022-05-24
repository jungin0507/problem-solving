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

const int sz = 1 << 17;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int N;
pii in[sz][2];
pii out[sz][2];
ll DP[sz][17][2][2]; // dp_i_x_d1_d2

ll dist(pii a, pii b) {
  return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void preproc() {
}

void solve() {
  cin >> N;
  for (int i = 1; i < N; ++i) {
    vector<pii> d(2);
    d[0] = { 1, 0 };
    d[1] = { 0, 1 };
    rep(j, 2) {
      int dx, dy;
      cin >> dx >> dy;
      in[i][j] = { dx, dy };
      out[i][j] = in[i][j] + d[j];
    }
  }
  rep(i, sz) rep(j, 17) rep(k, 2) rep(l, 2) DP[i][j][k][l] = INF;
  for (int i = 1; i < N - 1; ++i) {
    rep(k, 2) rep(l, 2)
        DP[i][0][k][l] = dist(out[i][k], in[i + 1][l]) + 1;
  }
  for (int x = 1; x < 17; ++x) {
    for (int i = 1; i < N - 1; ++i) {
      int m = i + (1 << (x - 1));
      if (m >= N - 1) break;
      rep(k, 2) rep(l, 2) rep(t, 2)
          DP[i][x][k][l] = min(DP[i][x][k][l], DP[i][x - 1][k][t] + DP[m][x - 1][t][l]);
    }
  }

  int M;
  cin >> M;
  while (M-- > 0) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int l1 = max(x1, y1);
    int l2 = max(x2, y2);
    if (l1 == l2) {
      cout << dist(pii{ x1, y1 }, pii{ x2, y2 }) << "\n";
      continue;
    } else if (l1 > l2) {
      swap(x1, x2);
      swap(y1, y2);
      swap(l1, l2);
    }
    vector<ll> v = { dist(pii(x1, y1), in[l1][0]), dist(pii(x1, y1), in[l1][1]) };
    for (int x = 17; x >= 0; --x) {
      if (l1 + (1 << x) >= l2) continue;
      vector<ll> tmp(2, INF);
      rep(k, 2) rep(l, 2)
          tmp[l] = min(tmp[l], v[k] + DP[l1][x][k][l]);
      l1 += (1 << x);
      v = tmp;
    }
    ll ans = INF;
    rep(k, 2)
        ans = min(ans, v[k] + dist(pii(x2, y2), out[l1][k]) + 1);
    cout << ans << "\n";
  }
}