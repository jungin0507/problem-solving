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
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int MAX_N = 1e3 + 5;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool painted[MAX_N][MAX_N];
int N, M;
vector<pair<pair<int, int>, int>> res;

int dx[9] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[9] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int chk(int x, int y) {
  int c = arr[x][y];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (!painted[x + i][y + j]) c = arr[x + i][y + j];
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (!painted[x + i][y + j] && c != arr[x + i][y + j]) return -1;
    }
  }
  return c;
}

void solve() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> arr[i][j];
    }
  }

  queue<pair<pii, int>> q;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      int c = chk(i, j);
      if (c != -1) {
        q.push(make_pair(pii(i, j), c));
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front().first;
    int c = q.front().second;
    q.pop();
    visited[x][y] = true;
    res.emplace_back(pii(x, y), c);

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        painted[x + i][y + j] = true;
      }
    }

    for (int i = 0; i < 9; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 1 || nx >= N) continue;
      if (ny < 1 || ny >= M) continue;
      if (visited[nx][ny]) continue;

      int c = chk(nx, ny);
      if (c != -1) {
        visited[nx][ny] = true;
        q.push(make_pair(pii(nx, ny), c));
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (!painted[i][j]) {
        cout << -1 << "\n";
        return;
      }
    }
  }

  cout << res.size() << "\n";
  for (int i = res.size() - 1; i >= 0; --i) {
    cout << res[i].first.first << " " << res[i].first.second << " " << res[i].second << "\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}