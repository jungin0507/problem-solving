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

const int MAX_N = 1005;

int N, M;
int arr[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][2];
bool visited[MAX_N][MAX_N];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      dist[i][j][0] = INF, dist[i][j][1] = INF;

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < M; ++j) {
      if (s[j] == '1')
        arr[i][j] = 1;
    }
  }

  queue<pair<pii, bool>> q;
  q.push(make_pair(make_pair(0, 0), false));
  dist[0][0][0] = 1;
  while (!q.empty()) {
    pii cur = q.front().first;
    bool isCrashed = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      bool b = isCrashed;
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (arr[nx][ny] == 1) {
        if (!isCrashed)
          b = true;
        else
          continue;
      }

      if (dist[nx][ny][b] > dist[cur.first][cur.second][isCrashed] + 1) {
        dist[nx][ny][b] = dist[cur.first][cur.second][isCrashed] + 1;
        q.push(make_pair(make_pair(nx, ny), b));
      }
    }
  }

  int ans = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
  if (ans == INF)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}