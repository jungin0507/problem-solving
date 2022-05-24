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

int arr1[35][35];
int arr2[35][35];
int chk[35][35];
bool visited[35][35];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void solve() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> arr1[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> arr2[i][j];
    }
  }
  pii start = { -1, -1 };
  int num = -1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr1[i][j] != arr2[i][j]) {
        start = { i, j };
        num = arr2[i][j];
        i = N;
        break;
      }
    }
  }
  if (num == -1) {
    cout << "YES\n";
    return;
  }
  queue<pii> q;
  q.push(start);
  visited[start.first][start.second] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (visited[nx][ny] || arr1[nx][ny] != arr1[x][y]) continue;
      visited[nx][ny] = true;
      q.push({ nx, ny });
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (visited[i][j])
        arr1[i][j] = num;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr1[i][j] != arr2[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}