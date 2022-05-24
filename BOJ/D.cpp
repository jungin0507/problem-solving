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
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

void solve() {
  ll b, q, y;
  ll c, r, z;
  cin >> b >> q >> y;
  cin >> c >> r >> z;
  if ((b + (y - 1) * q < c + (z - 1) * r) || (b > c) || (c - b) % gcd(q, r) || r % q) {
    cout << 0 << "\n";
    return;
  }
  if (c - r < b || c + z * r > b + (y - 1) * q) {
    cout << -1 << "\n";
    return;
  }
  ll ans = 0;
  for (ll div = 1; div * div <= r; ++div) {
    if (r % div) continue;
    ll o = r / div;
    ans += o * o * (lcm(div, q) == r);
    ans %= MOD;
    ans += div * div * (lcm(o, q) == r) * (div != o);
    ans %= MOD;
    // cout << div << ' ' << o << "\n";
  }
  cout << ans << "\n";
}