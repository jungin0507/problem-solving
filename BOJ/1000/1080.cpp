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

int A[55][55];
int B[55][55];

void f(int x, int y) {
  for (int i = x; i < x + 3; ++i) {
    for (int j = y; j < y + 3; ++j) {
      A[i][j] = !A[i][j];
    }
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < M; ++j) {
      A[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < M; ++j) {
      B[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < N - 2; ++i) {
    for (int j = 0; j < M - 2; ++j) {
      if (A[i][j] != B[i][j]) {
        f(i, j);
        ++cnt;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (A[i][j] != B[i][j]) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  cout << cnt << "\n";
}