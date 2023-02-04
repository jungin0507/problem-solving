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
  cin >> T;
  preproc();
  while (T-- > 0) solve();
}

/* actual code */

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

void preproc() {
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;
  if (N % 2 == 1) {
    cout << "NO\n";
    return;
  }
  sort(all(A));
  vector<int> res(N);
  for (int i = 0; i < N / 2; ++i) {
    res[i * 2] = A[i];
  }
  for (int i = N / 2; i < N; ++i) {
    res[(i - N / 2) * 2 + 1] = A[i];
  }
  bool ok = true;
  for (int i = 0; i < N; ++i) {
    if ((res[i] > res[(i - 1 + N) % N] && res[i] > res[(i + 1) % N]) || (res[i] < res[(i - 1 + N) % N] && res[i] < res[(i + 1) % N]))
      continue;
    ok = false;
  }
  if (ok) {
    cout << "YES\n";
    cout << res << "\n";
  } else {
    cout << "NO\n";
  }
}