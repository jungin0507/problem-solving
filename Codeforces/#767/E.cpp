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

const int MAX_N = 1e3 + 5;

int xorSum[MAX_N][MAX_N];
int grid[MAX_N][MAX_N];
int dx[3] = { -1, 0, 0 };
int dy[3] = { 0, 1, -1 };

void testCase() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> xorSum[i][j];
  memset(grid, 0, sizeof(grid));
  int ans = 0;
  for (int i = 0; i + 1 < N; ++i) {
    for (int j = 0; j < N; ++j) {
      grid[i + 1][j] ^= xorSum[i][j];
      for (int k = 0; k < 3; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || ny < 0 || ny >= N)
          continue;
        grid[i + 1][j] ^= grid[nx][ny];
      }
      ans ^= grid[i + 1][j];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    testCase();
  }
}