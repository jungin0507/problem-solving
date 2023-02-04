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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(k, 0));
  if (n % 2 == 1 && k != 1) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  int num = 1;
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < k; ++j) {
      A[i][j] = num;
      num += 2;
    }
  }

  num = 2;
  for (int i = 1; i < n; i += 2) {
    for (int j = 0; j < k; ++j) {
      A[i][j] = num;
      num += 2;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) cout << A[i][j] << " ";
    cout << "\n";
  }
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