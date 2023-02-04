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

int N, M;
vector<int> adj[MAX_N];
int S;
bool chk[MAX_N];
bool visited[MAX_N];

bool dfs(int here) {
  visited[here] = true;
  if (chk[here]) {
    return false;
  }
  for (int there : adj[here]) {
    if (visited[there]) continue;
    if (dfs(there)) {
      return true;
    }
  }
  return adj[here].empty() ? true : false;
}

void solve() {
  cin >> N >> M;
  while (M--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  cin >> S;
  while (S--) {
    int v;
    cin >> v;
    chk[v] = true;
  }
  cout << (dfs(1) ? "yes" : "Yes") << "\n";
}