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
void preproc();

signed main() {
  fastio;
  int T = 1;
  cin >> T;
  preproc();
  while (T-- > 0) solve();
}

const int MAX_N = 4e4 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

vector<int> pi;
ll DP[500][MAX_N];
int sz;
bool chk(int n) {
  int tmp = n;
  int nn = 0;
  while (tmp) {
    // if (tmp % 10 == 0) return false;
    nn = nn * 10 + tmp % 10;
    tmp /= 10;
  }
  return (n == nn);
}

void preproc() {
  for (int i = 1; i < MAX_N; ++i) {
    if (chk(i)) {
      pi.push_back(i);
    }
  }
  sz = pi.size();
  for (int i = 0; i < MAX_N; ++i) {
    DP[0][i] = 1;
  }
  for (int i = 1; i < sz; ++i) {
    for (int j = 0; j < MAX_N; ++j) {
      if (j >= pi[i])
        DP[i][j] += DP[i][j - pi[i]];
      DP[i][j] += DP[i - 1][j];
      DP[i][j] %= MOD;
    }
  }
}

void solve() {
  int N;
  cin >> N;
  cout << DP[sz - 1][N] << "\n";
  // cout << sz << "\n";
}