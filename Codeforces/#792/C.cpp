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
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B = A;
  for (int i = 0; i < N; ++i) {
    sort(all(B[i]));
  }
  vector<int> idx;
  for (int j = 0; j < M; ++j) {
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      if (A[i][j] != B[i][j]) {
        ok = false;
        break;
      }
    }
    if (!ok) idx.push_back(j);
  }
  if (idx.empty()) {
    cout << "1 1\n";
  } else if (idx.size() != 2) {
    cout << -1 << "\n";
  } else {
    for (int i = 0; i < N; ++i) {
      swap(A[i][idx[0]], A[i][idx[1]]);
    }
    for (int j = 0; j < M; ++j) {
      bool ok = true;
      for (int i = 0; i < N; ++i) {
        if (A[i][j] != B[i][j]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        cout << -1 << "\n";
        return;
      }
    }
    cout << idx[0] + 1 << ' ' << idx[1] + 1 << "\n";
  }
}