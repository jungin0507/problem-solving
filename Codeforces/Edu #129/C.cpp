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
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < N; ++i) cin >> B[i];
  vector<pii> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = { A[i], B[i] };
  }
  vector<pii> tmp = v;
  sort(all(A));
  sort(all(B));
  sort(all(tmp));
  for (int i = 0; i < N; ++i) {
    auto [a, b] = tmp[i];
    if (a != A[i] || b != B[i]) {
      cout << -1 << "\n";
      return;
    }
  }
  vector<pii> res;
  for (int i = N - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1]) {
        res.emplace_back(j, j + 1);
        swap(v[j], v[j + 1]);
      }
    }
  }
  cout << res.size() << "\n";
  for (auto [u, v] : res) {
    cout << u + 1 << ' ' << v + 1 << "\n";
  }
}