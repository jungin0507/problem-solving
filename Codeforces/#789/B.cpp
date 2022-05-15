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

const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<vector<int>> DP(N / 2, vector<int>(2, INF));
  int ans = 0;
  if (S.substr(0, 2) == "11") {
    DP[0][1] = 1;
  } else if (S.substr(0, 2) == "00") {
    DP[0][0] = 1;
  } else {
    DP[0][0] = 1;
    DP[0][1] = 1;
    ++ans;
  }
  for (int i = 2; i < N; i += 2) {
    if (S.substr(i, 2) == "11") {
      DP[i / 2][1] = min(DP[i / 2 - 1][0] + 1, DP[i / 2 - 1][1]);
    } else if (S.substr(i, 2) == "00") {
      DP[i / 2][0] = min(DP[i / 2 - 1][0], DP[i / 2 - 1][1] + 1);
    } else {
      DP[i / 2][0] = min(DP[i / 2 - 1][0], DP[i / 2 - 1][1] + 1);
      DP[i / 2][1] = min(DP[i / 2 - 1][0] + 1, DP[i / 2 - 1][1]);
      ++ans;
    }
  }
  cout << ans << " " << min(DP[(N - 2) / 2][0], DP[(N - 2) / 2][1]) << "\n";
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