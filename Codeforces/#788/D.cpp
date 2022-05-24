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
void solve();

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
ll DP[MAX_N];

signed main() {
  fastio;
  int T = 1;
  cin >> T;
  ll start = 0;
  for (int i = 1; i < MAX_N; i += 3) {
    DP[i] = start;
    DP[i + 1] = start + 1;
    DP[i + 2] = start + 2;
    start += 2;
  }
  for (int i = 1; i < MAX_N; ++i) {
    DP[i] += DP[i - 1];
  }
  for (int i = 1; i < MAX_N; ++i) {
    DP[i] *= 2;
  }
  while (T-- > 0) solve();
}

void solve() {
  ll N;
  cin >> N;
  int s = 1;
  int e = MAX_N - 1;
  while (s < e) {
    int m = (s + e) >> 1;
    if (DP[m] >= N) {
      e = m;
    } else {
      s = m + 1;
    }
  }
  cout << e << "\n";
}