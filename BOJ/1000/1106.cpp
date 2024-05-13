#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for (auto i = 0; i < (n); ++i)
#define rrep(i, n) for (auto i = (n) - 1; i >= 0; --i)
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
const int INF = 1e9 + 5;
const ll MOD = 1e9 + 7;

int DP[2005];
int C, N;
pii arr[25];

void preproc() {
  for (int i = 1; i <= 2000; i++) {
    DP[i] = INF;
  }
}

void solve() {
  cin >> C >> N;
  rep(i, N) cin >> arr[i];
  for (int n = 1; n <= 2000; ++n) {
    for (int i = 0; i < N; ++i) {
      if (n - arr[i].second < 0) continue;
      DP[n] = min(DP[n], DP[n - arr[i].second] + arr[i].first);
    }
  }
  int ans = INF;
  for (int n = C; n <= 2000; ++n) {
    ans = min(ans, DP[n]);
  }
  cout << ans << "\n";
}
