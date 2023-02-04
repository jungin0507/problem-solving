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
  // cin >> T;
  while (T-- > 0) solve();
}

const int MAX_N = 1005;
const int INF = 0x7fffffff;
const ll MOD = 998244353;
ll POW[18][MAX_N];

void preproc() {
  for (int i = 1; i <= 17; ++i)
    POW[i][0] = 1;
  for (int i = 1; i <= 17; ++i)
    for (int j = 1; j < 1005; ++j) {
      POW[i][j] = POW[i][j - 1] * i;
      POW[i][j] %= MOD;
    }
}

pll DP[MAX_N][MAX_N];
ll F[18][1 << 17];

void solve() {
  preproc();
  int N;
  string S;
  cin >> N >> S;
  int f = 0;
  for (auto c : S) {
    if (c == '?') ++f;
  }
  for (int l = 0; l < N; ++l) {
    DP[l][l] = { 0, f };
  }
  for (int l = 0; l + 1 < N; ++l) {
    int r = l + 1;
    if (S[l] == S[r] && S[l] != '?') {
      DP[l][r] = { 0, f };
    } else if (S[l] == S[r] && S[l] == '?') {
      DP[l][r] = { 0, f - 1 };
    } else if (S[l] == '?') {
      DP[l][r] = { 1 << (S[r] - 'a'), f - 1 };
    } else if (S[r] == '?') {
      DP[l][r] = { 1 << (S[l] - 'a'), f - 1 };
    } else {
      DP[l][r] = { 0, -1 };
    }
  }
  for (int len = 3; len <= N; ++len) {
    for (int l = 0; l + len - 1 < N; ++l) {
      int r = l + len - 1;
      if (DP[l + 1][r - 1] == pll{ 0, -1 }) {
        DP[l][r] = { 0, -1 };
        continue;
      }
      if (S[l] == S[r] && S[l] != '?') {
        DP[l][r] = DP[l + 1][r - 1];
      } else if (S[l] == S[r] && S[l] == '?') {
        DP[l][r] = DP[l + 1][r - 1] + pll{ 0, -1 };
      } else if (S[l] == '?') {
        DP[l][r] = { DP[l + 1][r - 1].first | 1 << (S[r] - 'a'),
                     DP[l + 1][r - 1].second - 1 };
      } else if (S[r] == '?') {
        DP[l][r] = { DP[l + 1][r - 1].first | 1 << (S[l] - 'a'),
                     DP[l + 1][r - 1].second - 1 };
      } else {
        DP[l][r] = { 0, -1 };
      }
    }
  }
  // for (int l = 0; l < N; ++l) {
  //   for (int r = 0; r < N; ++r) {
  //     // if (DP[l][r] == pll{ 0, -1 }) continue;
  //     // F[i][DP[l][r].first] += POW[i][DP[l][r].second];
  //     // F[i][DP[l][r].first] %= MOD;
  //     cout << DP[l][r] << " | ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  for (int i = 1; i <= 17; ++i) {
    for (int l = 0; l < N; ++l) {
      for (int r = l; r < N; ++r) {
        if (DP[l][r] == pll{ 0, -1 }) continue;
        F[i][DP[l][r].first] = (F[i][DP[l][r].first] + POW[i][DP[l][r].second] >= MOD) ? F[i][DP[l][r].first] + POW[i][DP[l][r].second] - MOD : F[i][DP[l][r].first] + POW[i][DP[l][r].second];
        // F[i][DP[l][r].first] %= MOD;
      }
    }
  }
  for (int i = 1; i <= 17; ++i) {
    for (int j = 0; j < 17; ++j) {
      for (int k = 0; k < (1 << 17); ++k) {
        if (k & (1 << j)) {
          F[i][k] = (F[i][k] + F[i][k ^ (1 << j)] >= MOD) ? F[i][k] + F[i][k ^ (1 << j)] - MOD : F[i][k] + F[i][k ^ (1 << j)];
          // F[i][k] %= MOD;
        }
      }
    }
  }
  // cout << F[1][0] << "\n";

  int Q;
  cin >> Q;
  while (Q-- > 0) {
    string T;
    cin >> T;
    int bit = 0;
    for (int i = 0; i < T.length(); ++i) {
      bit |= (1 << (T[i] - 'a'));
    }
    auto COUNT = [](int mask) -> int {
      int ret = 0;
      while (mask) {
        ret += mask % 2;
        mask >>= 1;
      }
      return ret;
    };
    cout << F[COUNT(bit)][bit] << "\n";
  }
}