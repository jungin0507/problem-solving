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

const int MAX_N = 1e3 + 5;
const int INF = 0x7fffffff;

int N;
int A[MAX_N];
bool chk[7];

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] %= 7;
  }
  chk[A[0]] = true;
  for (int i = 1; i < N; ++i) {
    bool tmp[7];
    for (int j = 0; j < 7; ++j) {
      tmp[j] = chk[j];
    }
    for (int j = 0; j < 7; ++j) {
      if (!chk[j]) continue;
      tmp[(j + A[i]) % 7] = true;
    }
    for (int j = 0; j < 7; ++j) {
      chk[j] = tmp[j];
    }
    chk[A[i]] = true;
  }
  if (chk[4])
    cout << "YES\n";
  else
    cout << "NO\n";
}