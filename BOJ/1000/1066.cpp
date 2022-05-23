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
const ll MOD = 1e9 + 7;

vector<pii> prefix[10];
ll DP[10][MAX_N][MAX_N];

void solve() {
  for (int n = 1; n < 10; ++n) {
    for (int i = 1; i <= 1000; ++i) {
      for (int j = n; j < 10; ++j) {
        if (i == 1 || (j - n) % (i - 1) == 0) {
          prefix[n].emplace_back(i, j);
          ++DP[n][i][1];
        }
      }
    }
  }

  // for (int i = 1; i < 10; ++i) {
  //   for (int j = 1; j < MAX_N; ++j) {
  //     for (int k = 2; k <= j; ++k) {
  //       for (auto [n, e] : prefix[i]) {
  //         if (j - n < 1) continue;
  //         for (int l = e; l < 10; ++l) {
  //           DP[i][j][k] += DP[l][j - n][k - 1];
  //           DP[i][j][k] %= MOD;
  //         }
  //       }
  //     }
  //   }
  // }

  ll ans = 0;
  for (int i = 1; i < 10; ++i) {
    ans += DP[i][2][1];
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}