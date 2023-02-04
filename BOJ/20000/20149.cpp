#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
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
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

ll ccw(pll a, pll b) {
  ll cal = a.fi * b.se - b.fi * a.se;
  if (cal > 0)
    return 1;
  else if (cal == 0)
    return 0;
  else
    return -1;
}

bool chk(pll a, pll b, pll c, pll d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  ll ab = ccw(b - a, c - a) * ccw(b - a, d - a);
  ll cd = ccw(d - c, a - c) * ccw(d - c, b - c);
  if (ab == 0 && cd == 0) {
    return c <= b && a <= d;
  } else {
    return ab <= 0 && cd <= 0;
  }
}

void preproc() {
}

void solve() {
  pll A, B, C, D;
  cin >> A >> B >> C >> D;
  if (A > B) swap(A, B);
  if (C > D) swap(C, D);
  cout << chk(A, B, C, D) << "\n";
  ll a, b, c, d, e, f;
  a = B.fi - A.fi;
  b = D.fi - C.fi;
  c = B.se - A.se;
  d = D.se - C.se;
  e = C.fi - A.fi;
  f = C.se - A.se;
  if (!chk(A, B, C, D)) return;
  if (a * d != b * c) {
    double t = 1.0 * (e * d - b * f) / (a * d - b * c);
    double s = 1.0 * (a * f - e * c) / (a * d - b * c);
    double x = t * a + A.fi;
    double y = t * c + A.se;
    cout.precision(12);
    cout << fixed;
    cout << x << ' ' << y << "\n";
  } else if (B == C) {
    cout << B << "\n";
  } else if (A == D) {
    cout << A << "\n";
  }
}