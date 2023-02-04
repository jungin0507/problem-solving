#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
#define double long double
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for (auto i = 0; i < (n); ++i)
#define rrep(i, n) for (auto i = (n)-1; i >= 0; --i)
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

/* operators of std::pair<T1, T2> */
template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
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

/* operators of std::vector<T> */
template <class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template <class T>
istream &operator>>(istream &i, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    i >> (*it);
  }
  return i;
}
void solve();
void preproc();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  preproc();
  while (T-- > 0) solve();
}

/* actual code */

const int MAX_N = 1e5 + 5;
const double INF = 1e18;
const ll MOD = 1e9 + 7;

double get(int l, int r, vector<double> &v) {
  if (l > r) return 0;
  if (l == 0) return v[r];
  return v[r] - v[l - 1];
}

void preproc() {
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<double> vec(N);
  cin >> vec;
  vector<double> sq_vec(N);
  sq_vec = vec;
  transform(all(sq_vec), sq_vec.begin(), [](const double a) -> double { return sq(a); });
  rep(i, N) if (i != 0) vec[i] += vec[i - 1];
  rep(i, N) if (i != 0) sq_vec[i] += sq_vec[i - 1];
  double ans = INF;
  for (int sz = K; sz <= N; ++sz) {
    for (int i = 0; i + sz - 1 < N; ++i) {
      double E_X2 = get(i, i + sz - 1, sq_vec) / sz;
      double E_X = get(i, i + sz - 1, vec) / sz;
      E_X *= E_X;
      ans = min(ans, E_X2 - E_X);
    }
  }
  cout.precision(11);
  cout << fixed;
  cout << sqrt(ans) << "\n";
}