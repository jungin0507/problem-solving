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
template<class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template<class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
}
template<class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first + y.first, x.second + y.second};
}
template<class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
}
template<class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template<class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}

/* operators of std::vector<T> */
template<class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template<class T>
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

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

ll fact[MAX_N];
ll res[MAX_N];

void preproc() {
  fact[0] = 1;
  for (int i = 1; i < MAX_N; ++i) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
}

ll pw(ll n, ll k) {
  if (k == 0) {
    return 1;
  }
  ll ret = pw(n, k / 2);
  ret *= ret;
  ret %= MOD;
  if (k % 2) {
    ret *= n;
    ret %= MOD;
  }
  return ret;
}

ll calc(ll n, ll k) {
  ll ret = fact[n];
  ll div = fact[k] * fact[n - k];
  div %= MOD;
  div = pw(div, MOD - 2);
  ret *= div;
  ret %= MOD;
  return ret;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  k = min(k, n);

  res[0] = 1;
  for (int i = 1; i <= k; ++i) {
    res[i] = res[i - 1] + calc(n, i);
    res[i] %= MOD;
  }
  cout << res[k] << "\n";
}