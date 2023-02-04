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

const int MAX_N = 3e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

vector<int> adj[MAX_N];
ll D, G;
ll W[MAX_N];
int H[MAX_N];
int P[MAX_N];

void dfs(int here, int parent) {
    P[here] = parent;
    for(int there : adj[here]) {
        if(there == parent) continue;
        H[there] = H[here] + 1;
        dfs(there, here);
        W[here]++;
    }
}

void preproc() {
}

void solve() {
    int N;
    cin >> N;
    rep(_, N-1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for(int i=1; i<=N; ++i) {
        if(H[i] >= 3) D++;
        if(H[i] >= 2) {
            int pp = P[P[i]];
            D += W[pp] - 1;
        }
        if(W[i] >= 3) {
            G += 1LL * W[i] * (W[i] - 1) * (W[i] - 2) / 6;
        }
        if(H[i] >= 1 && W[i] >= 2) {
            G += 1LL * W[i] * (W[i] - 1) / 2;
        }
    }
    if(D > 3 * G) {
        cout << "D\n";
    } else if(D < 3 * G) {
        cout << "G\n";
    } else {
        cout << "DUDUDUNGA\n";
    }
}