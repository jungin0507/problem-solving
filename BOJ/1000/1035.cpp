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
#define FOR(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;

using namespace std;

pii piece[5];
int cnt;
int ans = INF;
int arr[5][5];
bool visited[5][5];
int dir_x[4] = { 1, -1, 0, 0 };
int dir_y[4] = { 0, 0, -1, 1 };
int tmp = 0;

void dfs(int x, int y) {
  visited[x][y] = true;
  ++tmp;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dir_x[i];
    int ny = y + dir_y[i];
    if (nx >= 5 || nx < 0)
      continue;
    if (ny >= 5 || ny < 0)
      continue;
    if (visited[nx][ny])
      continue;
    if (arr[nx][ny] == 0)
      continue;
    dfs(nx, ny);
  }
}

bool chk() {
  memset(visited, false, sizeof(visited));
  tmp = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (arr[i][j]) {
        dfs(i, j);
        if (tmp == cnt) {
          return true;
        } else {
          return false;
        }
      }
    }
  }
  return false;
}

void solve(int n, int d) {
  if (n == cnt) {
    if (chk()) {
      ans = min(ans, d);
    }
    return;
  }

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (arr[i][j])
        continue;
      arr[i][j] = 1;
      solve(n + 1, d + abs(piece[n].first - i) + abs(piece[n].second - j));
      arr[i][j] = 0;
    }
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 5; ++i) {
    string input;
    cin >> input;
    for (int j = 0; j < 5; ++j) {
      if (input[j] == '*') {
        piece[cnt++] = make_pair(i, j);
      }
    }
  }

  solve(0, 0);
  cout << ans << "\n";
}