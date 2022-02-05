#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define INF 987654321
#define vi vector<int>
#define sq(x) ((x) * (x))
#define rep(from, to, it) for (auto(it) = (from); (it) < (to); ++(it))
#define rrep(from, to, it) for (auto(it) = (from)-1; (it) >= (to); --(it))
#define fastio                           \
  ios::ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

using ll = long long;
using namespace std;

const int MAX_R = 105, MAX_C = 105;

int R, C;
int grid[MAX_R][MAX_C];
int cluster[MAX_R][MAX_C];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[MAX_R][MAX_C];

bool dfs(int x, int y) {
  bool ret = false;
  visited[x][y] = true;
  cluster[x][y] = 1;
  if (x == R) ret = true;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > R || ny < 1 || ny > C || visited[nx][ny] || !grid[nx][ny]) continue;
    if (dfs(nx, ny)) ret = true;
  }
  return ret;
}

void solve() {
  cin >> R >> C;
  for (int i = 1; i <= R; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= C; ++j) grid[i][j] = (s[j - 1] == 'x') ? 1 : 0;
  }
  int N;
  cin >> N;
  for (int n = 0; n < N; ++n) {
    memset(visited, false, sizeof(visited));
    memset(cluster, 0, sizeof(cluster));
    int h;
    cin >> h;
    int x = R - h + 1;
    int y = (n % 2) ? C : 1;
    for (; y <= C && n % 2 == 0; ++y)
      if (grid[x][y]) break;
    for (; y >= 1 && n % 2 == 1; --y)
      if (grid[x][y]) break;
    if (!grid[x][y]) continue;
    grid[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > R || ny < 1 || ny > C || visited[nx][ny] || !grid[nx][ny]) continue;
      if (dfs(nx, ny))
        memset(cluster, 0, sizeof(cluster));
      else
        break;
    }

    for (int i = 1; i <= R; ++i)
      for (int j = 1; j <= C; ++j)
        if (cluster[i][j]) grid[i][j] = 0;

    int diff = R;
    for (int i = 1; i <= C; ++i) {
      int a = R + 1;
      for (int j = R; j >= 1; --j) {
        if (grid[j][i])
          a = j;
        else if (cluster[j][i])
          diff = min(diff, a - j - 1);
      }
    }

    for (int i = 1; i <= R; ++i)
      for (int j = 1; j <= C; ++j)
        if (cluster[i][j]) grid[i + diff][j] = 1;
  }
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cout << ((grid[i][j]) ? "x" : ".");
    }
    cout << "\n";
  }
}

int main() {
  fastio
  solve();
}