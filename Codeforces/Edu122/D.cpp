#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define INF 0x7fffffff
#define vi vector<int>
#define sq(x) ((x) * (x))
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int MAX = 1e3 + 5;

int cnt[MAX];
int b[MAX];
int c[MAX];
int needs[MAX];

void solve() {
  int N, K;
  cin >> N >> K;
  vector<vector<ll>> DP = vector<vector<ll>>(N, vector<ll>(N * 12 + 1, 0));
  for (int i = 0; i < N; ++i) {
    cin >> b[i];
    needs[i] = cnt[b[i]];
  }
  for (int i = 0; i < N; ++i) {
    cin >> c[i];
  }

  DP[0][needs[0]] = c[0];
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N * 12 + 1; ++j) {
      if (j - needs[i] >= 0)
        DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - needs[i]] + c[i]);
      else
        DP[i][j] = DP[i - 1][j];
    }
  }

  ll ans = 0;
  for (int i = 0; i <= min(K, N * 12); ++i) {
    ans = max(ans, DP[N - 1][i]);
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < MAX; ++i) cnt[i] = INF;

  cnt[1] = 0;
  for (int i = 1; i < MAX; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      if (i + i / j >= MAX) continue;
      cnt[i + i / j] = min(cnt[i + i / j], cnt[i] + 1);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}