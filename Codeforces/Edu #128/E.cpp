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

signed main() {
  fastio;
  int T = 1;
  cin >> T;
  while (T-- > 0) solve();
}

const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> board(2, vector<int>(N + 2));
  string S;
  cin >> S;
  for (int i = 1; i <= N; ++i) {
    if (S[i - 1] == '*') board[0][i] = 1;
  }
  cin >> S;
  for (int i = 1; i <= N; ++i) {
    if (S[i - 1] == '*') board[1][i] = 1;
  }

  vector<vector<int>> DP(2, vector<int>(N + 1, INF));
  for (int i = 1; i <= N; ++i) {
    DP[0][i] = min(DP[0][i], DP[0][i - 1] + 1 + (board[1][i] == 1));
    DP[0][i] = min(DP[0][i], DP[1][i - 1] + 2);
    if (DP[0][i] == INF) {
      if (board[1][i])
        DP[0][i] = 1;
      else if (board[0][i])
        DP[0][i] = 0;
    }
    DP[1][i] = min(DP[1][i], DP[1][i - 1] + 1 + (board[0][i] == 1));
    DP[1][i] = min(DP[1][i], DP[0][i - 1] + 2);
    if (DP[1][i] == INF) {
      if (board[0][i])
        DP[1][i] = 1;
      else if (board[1][i])
        DP[1][i] = 0;
    }
  }
  // for (int i = 0; i < 2; ++i) {
  //   for (int j = 1; j <= N; ++j) {
  //     cout << DP[i][j] << ' ';
  //   }
  //   cout << "\n";
  // }
  int e = N;
  for (; e > 0; --e) {
    if (board[0][e] == 1 || board[1][e] == 1) break;
  }
  cout << min(DP[0][e], DP[1][e]) << "\n";
}