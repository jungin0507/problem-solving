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
const int INF = 0x7fffffff;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(M, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[j][i];
    }
  }
  int idx = -1;
  for (int i = 0; i + 1 < M; ++i) {
    if (idx != -1) break;
    for (int j = 0; j < N; ++j) {
      if (A[i][j] > A[i + 1][j]) {
        idx = i;
        break;
      }
    }
  }
  if (idx == -1) {
    cout << "1 1\n";
    return;
  }
  vector<vector<int>> B = A;
  swap(B[idx], B[idx + 1]);
  bool ok = true;
  for (int i = 0; i + 1 < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (B[i][j] > B[i + 1][j]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << idx + 1 << ' ' << idx + 2 << "\n";
    return;
  }
  int idx2 = idx + 2;
  for (; idx2 < M; ++idx2) {
    bool ok = true;
    for (int j = 0; j < N; ++j) {
      if (A[idx2][j] > A[idx + 1][j]) {
        ok = false;
      }
    }
    if (ok) {
      break;
    }
  }
  B = A;
  if (idx2 < M) {
    swap(B[idx], B[idx2]);
  }
  ok = true;
  for (int i = 0; i + 1 < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (B[i][j] > B[i + 1][j]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << idx + 1 << ' ' << idx2 + 1 << "\n";
    return;
  }
  cout << -1 << "\n";
}