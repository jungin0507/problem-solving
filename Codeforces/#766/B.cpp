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

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void testCase() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> visited(N, vector<bool>(M));

  queue<pair<pii, int>> q;
  if (N == 1) {
    q.push(make_pair(make_pair(0, 0), N + M - 2));
    q.push(make_pair(make_pair(0, M - 1), N + M - 2));
    visited[0][0] = true;
    visited[0][M - 1] = true;
  } else if (M == 1) {
    q.push(make_pair(make_pair(0, 0), N + M - 2));
    q.push(make_pair(make_pair(N - 1, 0), N + M - 2));
    visited[0][0] = true;
    visited[N - 1][0] = true;
  } else {
    q.push(make_pair(make_pair(0, 0), N + M - 2));
    q.push(make_pair(make_pair(0, M - 1), N + M - 2));
    q.push(make_pair(make_pair(N - 1, 0), N + M - 2));
    q.push(make_pair(make_pair(N - 1, M - 1), N + M - 2));
    visited[0][0] = true;
    visited[0][M - 1] = true;
    visited[N - 1][0] = true;
    visited[N - 1][M - 1] = true;
  }

  vector<int> res;

  while (!q.empty()) {
    pii cur = q.front().first;
    int d = q.front().second;
    q.pop();
    res.push_back(d);

    for (int i = 0; i < 4; ++i) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push(make_pair(make_pair(nx, ny), d - 1));
    }
  }

  for (int i = res.size() - 1; i >= 0; --i) {
    cout << res[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    testCase();
}