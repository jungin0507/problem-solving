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

const int MAX_N = 55;
const int INF = 0x7fffffff;

ll DP[MAX_N][MAX_N];
vector<string> vec;

void solve() {
  string s;
  cin >> s;
  vec.push_back(s);
  for (int i = 0; i < s.length(); ++i) {
    for (int j = i + 1; j < s.length(); ++j) {
      string tmp = s;
      swap(tmp[i], tmp[j]);
      vec.push_back(tmp);
    }
  }
  int N = s.length();
  ll ans = INF;
  for (string &S : vec) {
    for (int i = 0; i < MAX_N; ++i)
      for (int j = 0; j < MAX_N; ++j) DP[i][j] = INF;
    for (int i = 0; i < N; ++i) {
      DP[i][i] = DP[i + 1][i] = 0;
    }
    for (int len = 2; len <= N; ++len) {
      for (int l = 0; l + len - 1 < N; ++l) {
        int r = l + len - 1;
        DP[l][r] = min(DP[l + 1][r - 1] + (S[l] != S[r]),
                       min(DP[l][r - 1] + 1, DP[l + 1][r] + 1));
      }
    }
    ans = min(ans, DP[0][N - 1] + (S != s));
  }
  cout << ans << "\n";
}