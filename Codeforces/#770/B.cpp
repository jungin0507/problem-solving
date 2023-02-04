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

const int MAX_N = 1e5 + 5;
const int MOD = 2;

void solve() {
  int n, x;
  cin >> n >> x;
  x %= MOD;
  ll y;
  cin >> y;
  y %= MOD;

  vector<vector<bool>> DP = vector<vector<bool>>(n, vector<bool>(MOD, false));
  vector<int> A = vector<int>(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    A[i] %= MOD;
  }

  DP[0][(x + A[0]) % MOD] = true;
  DP[0][(x ^ A[0]) % MOD] = true;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < MOD; ++j) {
      if (DP[i - 1][j]) {
        DP[i][(j + A[i]) % MOD] = true;
        DP[i][(j ^ A[i]) % MOD] = true;
      }
    }
  }

  if (DP[n - 1][y])
    cout << "Alice\n";
  else
    cout << "Bob\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}