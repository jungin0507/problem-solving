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
const int INF = 0x3f3f3f3f;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  map<ll, int> m;
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(all(A));
  int MEX = 0;
  vector<int> need(N + 1);
  for (int i = 0; i < N; ++i) {
    m[A[i]]++;
    if (A[i] == MEX) {
      ++MEX;
    }
  }
  int cnt = 0;
  for (int i = MEX; i < N; ++i) {
    if (m.find(i) == m.end()) {
      ++cnt;
    }
    need[i + 1] = cnt;
  }
  set<pair<int, ll>> s;
  for (auto &[v, c] : m) {
    s.insert(make_pair(c, v));
  }
  int ans = INF;
  int num = 0;
  set<pair<int, ll>> erased;
  for (int x = 0; x <= N; ++x) {
    if (need[x] > K) continue;
    if (erased.find(make_pair(m[x - 1], x - 1)) != erased.end()) {
      erased.erase(make_pair(m[x - 1], x - 1));
      num -= m[x - 1];
    }
    if (s.find(make_pair(m[x - 1], x - 1)) != s.end()) {
      s.erase(make_pair(m[x - 1], x - 1));
    }
    while (!s.empty() && num + s.begin()->first <= K) {
      num += s.begin()->first;
      erased.insert(*s.begin());
      s.erase(s.begin());
    }
    ans = min(ans, (int)s.size() + (x == 0 && s.empty()));
  }
  cout << ans << "\n";
}