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
  return {x.first + y.first, x.second + y.second};
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
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

const int MAX_N = 3e5 + 5;
const int INF = 0x7fffffff;

struct DisjoinSet {
  int N;
  vector<int> parent;
  DisjoinSet(int N) : N(N) {
    parent.resize(N);
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }
  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v;
  }
};

stack<int> s[MAX_N];
int U[MAX_N];
int V[MAX_N];
int res[MAX_N];

void solve() {
  int N, M;
  cin >> N >> M;
  DisjoinSet UF(M + 1);
  for (int i = 1; i <= M; ++i) {
    int &u = U[i];
    int &v = V[i];
    cin >> u >> v;
    while (!s[u].empty()) {
      UF.merge(s[u].top(), i);
      s[u].pop();
    }
    s[v].push(i);
  }
  for (int i = 1; i <= M; ++i) {
    if (res[U[i]]) continue;
    res[U[i]] = V[UF.find(i)];
  }
  for (int i = 1; i <= N; ++i) {
    cout << (res[i] ? res[i] : i) << ' ';
  }
  cout << '\n';
}