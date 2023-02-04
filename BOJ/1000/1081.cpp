#include <bits/stdc++.h>

// #define int long long
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))
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
using vi = vector<int>;

template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first + y.first, x.second + y.second};
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
}
template <class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template <class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}
void solve();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  while (T-- > 0) solve();
}

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
ll f[10];
ll pw[10];

ll calc(ll n) {
  if (n <= 0) return 0;
  int d = (int)log10(n);
  ll b = n / pw[d];
  ll ret = b * f[d] + b * (b - 1) / 2 * pw[d] + b * (n % pw[d] + 1) +
           calc(n % pw[d]);
  return ret;
}

void solve() {
  pw[0] = 1;
  for (int i = 1; i < 10; ++i) pw[i] = pw[i - 1] * 10;
  f[0] = 0;
  for (int i = 1; i < 10; ++i) {
    f[i] = 10 * f[i - 1] + pw[i - 1] * 45;
  }
  ll L, U;
  cin >> L >> U;
  cout << calc(U) - calc(L - 1) << "\n";
}