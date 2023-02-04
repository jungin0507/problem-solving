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
template<class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template<class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
}
template<class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first + y.first, x.second + y.second};
}
template<class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
}
template<class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template<class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}

/* operators of std::vector<T> */
template<class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template<class T>
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

const int MAX_N = 505;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

struct info {
  int x, y, dir, dist;
  info(int x = 0, int y = 0, int dir = 0, int dist = 0) : x(x), y(y), dir(dir), dist(dist) {};
};

int N, M;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][2];
pii up[MAX_N][MAX_N];
pii down[MAX_N][MAX_N];
pii start, goal;
int dy[2] = {1, -1};

void preproc() {
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    for (int j = 0; j < M; ++j) {
      arr[i][j] = (S[j] == '#');
      if (S[j] == 'C') start = pii{i, j};
      else if (S[j] == 'D') goal = pii{i, j};
    }
  }
  for (int j = 0; j < M; ++j) {
    up[0][j] = {0, j};
    for (int i = 1; i < N; ++i) {
      if (arr[i][j] == 1) continue;
      if (arr[i - 1][j] == 1 || goal == pii{i, j}) up[i][j] = {i, j};
      else up[i][j] = up[i - 1][j];
    }
  }
  for (int j = 0; j < M; ++j) {
    down[N - 1][j] = {N - 1, j};
    for (int i = N - 2; i >= 0; --i) {
      if (arr[i][j] == 1) continue;
      if (arr[i + 1][j] == 1 || goal == pii{i, j}) down[i][j] = {i, j};
      else down[i][j] = down[i + 1][j];
    }
  }
  start = down[start.first][start.second];
  deque<info> deq;
  deq.emplace_back(start.first, start.second, 0, 0);
  while (!deq.empty()) {
    auto [x, y, dir, dist] = deq.front();
    deq.pop_front();
    if (goal == pii{x, y}) {
      cout << dist << "\n";
      return;
    }
    visited[x][y][dir] = true;
    visited[x][y][dir ^ 1] = true;
    if (x == 0 || x == N - 1) continue;
    for (int i = 0; i < 2; ++i) {
      int nx = x;
      int ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (arr[nx][ny]) continue;
      if (dir == 0) {
        nx = down[nx][ny].first;
        ny = down[nx][ny].second;
      } else {
        nx = up[nx][ny].first;
        ny = up[nx][ny].second;
      }
      if (!visited[nx][ny][dir] || !visited[nx][ny][dir ^ 1])
        deq.emplace_front(nx, ny, dir, dist);
    }
    if (dir == 0) {
      auto [nx, ny] = up[x][y];
      if (!visited[nx][ny][dir ^ 1] || !visited[nx][ny][dir])
        deq.emplace_back(nx, ny, dir ^ 1, dist + 1);
    } else {
      auto [nx, ny] = down[x][y];
      if (!visited[nx][ny][dir ^ 1] || !visited[nx][ny][dir])
        deq.emplace_back(nx, ny, dir ^ 1, dist + 1);
    }
  }
  cout << -1 << "\n";
}