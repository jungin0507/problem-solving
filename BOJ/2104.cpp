#include <bits/stdc++.h>

// #define int long long
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))
#define fi first
#define se second
#define mp(a, b) make_pair((a), (b))
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

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> res(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  {
    stack<pll> s;
    for (int i = 0; i < N; ++i) {
      ll sum = A[i];
      while (!s.empty() && s.top().fi >= A[i]) {
        sum += s.top().se;
        s.pop();
      }
      s.push(mp(A[i], sum));
      res[i] += sum;
    }
  }
  {
    stack<pll> s;
    for (int i = N - 1; i >= 0; --i) {
      ll sum = 0;
      while (!s.empty() && s.top().fi >= A[i]) {
        sum += s.top().se;
        s.pop();
      }
      s.push(mp(A[i], sum + A[i]));
      res[i] += sum;
    }
  }
  ll mx = 0;
  for (int i = 0; i < N; ++i) {
    mx = max(mx, res[i] * A[i]);
  }
  cout << mx << "\n";
}