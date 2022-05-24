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
  string S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) A[i] = S[i] - '0';
  vector<pii> res;
  vector<pii> s;
  for (int i = 0; i < N; ++i) {
    if (s.empty() || s.back().first == A[i]) {
      s.push_back(pii{ A[i], i });
      continue;
    }
    if (A[i] == 0) {
      if (s.back().first == 1) {
        auto [v, idx] = s.back();
        s.pop_back();
        res.emplace_back(idx, i);
        s.push_back(pii{ 1, i });
      }
    } else {
      int cur = i;
      while (!s.empty() && s.back().first == 0) {
        auto [v, idx] = s.back();
        s.pop_back();
        res.emplace_back(idx, cur);
        cur = idx;
      }
      s.push_back(pii{ 1, cur });
    }
  }
  if (s.size() % 2) {
    cout << "NO\n";
    return;
  }
  N = s.size();
  for (int i = 0; i < N; ++i) {
    if (s[i].first == 0) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 1; i < N; ++i) {
    res.emplace_back(s[0].second, s[i].second);
  }
  cout << "YES\n";
  for (auto [u, v] : res) {
    cout << u + 1 << ' ' << v + 1 << "\n";
  }
}