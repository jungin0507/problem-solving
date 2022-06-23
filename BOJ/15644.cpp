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

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

struct info {
  pii r;
  pii b;
  int num;
};

int arr[15][15];
bool visited[15][15][15][15];
info parent[15][15][15][15];
pii red, blue;
int N, M;

vector<pii> move(int dir, pii r, pii b) {
  vector<pii> ret = { r, b };
  int p = 0;
  int q = 1;
  if (dir == 0) { // L
    if (r < b) swap(p, q);
    while (ret[q].se - 1 >= 0 && arr[ret[q].fi][ret[q].se - 1] == 0)
      --ret[q].se;
    if (ret[q].se - 1 >= 0 && arr[ret[q].fi][ret[q].se - 1] == 2) --ret[q].se;
    while (ret[p].se - 1 >= 0 && arr[ret[p].fi][ret[p].se - 1] == 0 && ret[p] + make_pair(0, -1) != ret[q])
      --ret[p].se;
    if (ret[p].se - 1 >= 0 && arr[ret[p].fi][ret[p].se - 1] == 2) --ret[p].se;
  } else if (dir == 1) { // R
    if (r > b) swap(p, q);
    while (ret[q].se + 1 < M && arr[ret[q].fi][ret[q].se + 1] == 0)
      ++ret[q].se;
    if (ret[q].se + 1 < M && arr[ret[q].fi][ret[q].se + 1] == 2) ++ret[q].se;
    while (ret[p].se + 1 < M && arr[ret[p].fi][ret[p].se + 1] == 0 && ret[p] + make_pair(0, 1) != ret[q])
      ++ret[p].se;
    if (ret[p].se + 1 < M && arr[ret[p].fi][ret[p].se + 1] == 2) ++ret[p].se;
  } else if (dir == 2) { // U
    if (r < b) swap(p, q);
    while (ret[q].fi - 1 >= 0 && arr[ret[q].fi - 1][ret[q].se] == 0)
      --ret[q].fi;
    if (ret[q].fi - 1 >= 0 && arr[ret[q].fi - 1][ret[q].se] == 2) --ret[q].fi;
    while (ret[p].fi - 1 >= 0 && arr[ret[p].fi - 1][ret[p].se] == 0 && ret[p] + make_pair(-1, 0) != ret[q])
      --ret[p].fi;
    if (ret[p].fi - 1 >= 0 && arr[ret[p].fi - 1][ret[p].se] == 2) --ret[p].fi;
  } else if (dir == 3) {
    if (r > b) swap(p, q);
    while (ret[q].fi + 1 < N && arr[ret[q].fi + 1][ret[q].se] == 0)
      ++ret[q].fi;
    if (ret[q].fi + 1 < N && arr[ret[q].fi + 1][ret[q].se] == 2) ++ret[q].fi;
    while (ret[p].fi + 1 < N && arr[ret[p].fi + 1][ret[p].se] == 0 && ret[p] + make_pair(1, 0) != ret[q])
      ++ret[p].fi;
    if (ret[p].fi + 1 < N && arr[ret[p].fi + 1][ret[p].se] == 2) ++ret[p].fi;
  }
  return ret;
}

void preproc() {
}

void solve() {
  cin >> N >> M;
  rep(i, N) {
    string s;
    cin >> s;
    rep(j, M) {
      if (s[j] == '#')
        arr[i][j] = 1;
      else if (s[j] == 'O')
        arr[i][j] = 2;
      else if (s[j] == 'R')
        red = make_pair(i, j);
      else if (s[j] == 'B')
        blue = make_pair(i, j);
    }
  }
  queue<info> q;
  q.push({ red, blue, 0 });
  visited[red.fi][red.se][blue.fi][blue.se] = true;
  parent[red.fi][red.se][blue.fi][blue.se] = info{ red, blue, -1 };
  int ans = -1;
  pii n, m;
  while (!q.empty()) {
    auto [r, b, num] = q.front();
    q.pop();
    if (arr[b.fi][b.se] == 2)
      continue;
    else if (arr[r.fi][r.se] == 2) {
      ans = num;
      n = r;
      m = b;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      vector<pii> next = move(i, r, b);
      auto [rx, ry] = next[0];
      auto [bx, by] = next[1];
      if (visited[rx][ry][bx][by]) continue;
      q.push({ next[0], next[1], num + 1 });
      visited[rx][ry][bx][by] = true;
      parent[rx][ry][bx][by] = info{ r, b, i };
    }
  }
  if (ans > 10) ans = -1;
  cout << ans << "\n";
  if (ans == -1) return;
  vector<char> res;
  while (parent[n.fi][n.se][m.fi][m.se].num != -1) {
    auto [nx, ny] = n;
    auto [mx, my] = m;
    int num = parent[nx][ny][mx][my].num;
    char c;
    if (num == 0)
      c = 'L';
    else if (num == 1)
      c = 'R';
    else if (num == 2)
      c = 'U';
    else if (num == 3)
      c = 'D';
    res.push_back(c);
    n = parent[nx][ny][mx][my].r;
    m = parent[nx][ny][mx][my].b;
  }
  reverse(all(res));
  for (char c : res) cout << c;
  cout << "\n";
}