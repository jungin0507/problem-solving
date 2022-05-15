#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define vi vector<int>
#define sq(x) ((x) * (x))
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int MAX_N = 305;
const int sz = 1 << 20;
const ll INF = 0x7fffffff;
int X[MAX_N];
ll DP[MAX_N][MAX_N][MAX_N][2];
int N, M;

void solve() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> X[i];
  }
  X[N + 1] = 0;
  sort(X + 1, X + N + 2);
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      for (int k = 0; k < MAX_N; ++k) {
        DP[i][j][k][0] = INF;
        DP[i][j][k][1] = INF;
      }
  int start = 1;
  while (start <= N + 1 && X[start] != 0) {
    ++start;
  }
  for (int i = 1; i <= N + 1; ++i) {
    for (int j = 1; j <= N + 1; ++j) {
      DP[i][j][0][0] = DP[i][j][0][1] = 0;
    }
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N + 1; ++i) {
      for (int j = i; j <= N + 1; ++j) {
        DP[i][j][k][0] = min(DP[i - 1][j][k - 1][0] + k * (X[i] - X[i - 1]), DP[i][j + 1][k - 1][1] + k * (X[j + 1] - X[i]));
        DP[i][j][k][1] = min(DP[i - 1][j][k - 1][0] + k * (X[j] - X[i - 1]), DP[i][j + 1][k - 1][1] + k * (X[j + 1] - X[j]));
      }
    }
  }
  ll ans = 0;
  for (int k = 1; k <= N; ++k) {
    ans = max(ans, k * M - DP[start][start][k][0]);
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}