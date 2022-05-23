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

const int MAX_N = 1e3 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;
ll DP[MAX_N][MAX_N];
ll DP_sum[MAX_N][MAX_N];
int N, M;
int cards[MAX_N];

ll get(int i, int l, int r) {
  if (r < l) return 0;
  if (l <= 0) {
    return DP_sum[i][r];
  }
  ll ret = DP_sum[i][r] - DP_sum[i][l - 1] + MOD;
  ret %= MOD;
  return ret;
}

void solve() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    cards[n]++;
  }
  int x = 0;
  int y = 0;
  for (int i = MAX_N - 1; i >= 0; --i) {
    if (cards[i] > x) {
      x = cards[i];
      y = i;
    }
  }
  for (int i = 0; i < MAX_N; ++i) {
    if (y == 1) {
      DP[1][i] = (i <= x - 1);
    } else {
      DP[1][i] = (i <= x);
    }
  }
  DP_sum[1][0] = 1;
  for (int i = 1; i < MAX_N; ++i) {
    DP_sum[1][i] = DP_sum[1][i - 1] + DP[1][i];
    DP_sum[1][i] %= MOD;
  }
  for (int i = 2; i < MAX_N; ++i) {
    DP[i][0] = 1;
    DP_sum[i][0] = 1;
    for (int j = 1; j < MAX_N; ++j) {
      DP[i][j] = get(i - 1, j - x + (i >= y), j);
      DP_sum[i][j] = DP_sum[i][j - 1] + DP[i][j];
      DP_sum[i][j] %= MOD;
    }
  }

  cout << DP[M][N] << "\n";
}