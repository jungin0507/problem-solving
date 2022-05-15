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

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;

int N;
int S, C, H;
vector<int> adj[MAX_N];
vector<int> route[2];
stack<int> s;
bool chk[MAX_N];

void dfs(int here, int parent, int target, int num) {
  s.push(here);
  if (here == target) {
    while (!s.empty()) {
      route[num].push_back(s.top());
      s.pop();
    }
    return;
  }
  for (int there : adj[here]) {
    if (there == parent) continue;
    dfs(there, here, target, num);
  }
  if (!s.empty())
    s.pop();
}

void solve() {
  cin >> N;
  cin >> S >> C >> H;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(S, -1, C, 0);
  dfs(C, -1, H, 1);
  for (int n : route[0]) {
    chk[n] = true;
  }
  ll x = route[0].size();
  ll y = route[1].size();
  ll ans = x * (x - 1) / 2 + y * (y - 1) / 2;
  for (int n : route[1]) {
    if (chk[n]) {
      --x;
      --y;
    }
  }
  ans += x * y;
  cout << ans << "\n";
}