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

bool chk(ll v) {
  while (v) {
    if (v % 10 > 1) return true;
    v /= 10;
  }
  return false;
}

int cnt(ll v) {
  int ret = 0;
  while (v) {
    ++ret;
    v /= 10;
  }
  return ret;
}

vector<int> edge(ll X, ll v) {
  vector<bool> chk(10);
  ll tmp = X * v;
  while (tmp) {
    chk[tmp % 10] = true;
    tmp /= 10;
  }
  vector<int> res;
  for (int i = 2; i < 10; ++i) {
    if (chk[i]) res.push_back(i);
  }
  return res;
}

void solve() {
  ll N, X;
  cin >> N >> X;
  if (!chk(X)) {
    cout << -1 << "\n";
    return;
  }
  map<ll, ll> dist;
  dist[1] = 0;
  deque<ll> deq;
  deq.push_front(1);
  ll ans = -1;
  while (!deq.empty()) {
    ll x = deq.front();
    deq.pop_front();
    if (cnt(X * x) > N)
      continue;
    else if (cnt(X * x) == N) {
      ans = x;
      break;
    }
    vector<int> e = edge(X, x);
    for (int i = 0; i < e.size(); ++i) {
      ll next = x * e[i];
      ll next_dist = dist[x] + 1;
      if (dist.find(next) == dist.end() || next_dist < dist[next]) {
        dist[next] = next_dist;
        deq.push_back(next);
      }
    }
  }
  cout << dist[ans] << "\n";
}