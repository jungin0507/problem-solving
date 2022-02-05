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

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == n - 1) {
    if (n <= 4)
      cout << -1 << "\n";
    else {
      for (int i = 1; i < (n >> 1); ++i) {
        if (i == 1 || i == 2) continue;
        cout << i << " " << ((~i) & (n - 1)) << "\n";
      }
      cout << 0 << " " << 2 << "\n";
      cout << 1 << " " << n - 3 << "\n";
      cout << n - 2 << " " << n - 1 << "\n";
    }
    return;
  }

  for (int i = 1; i < (n >> 1); ++i) {
    if (i == k || i == ((~k) & (n - 1))) continue;
    cout << i << " " << ((~i) & (n - 1)) << "\n";
  }
  cout << 0 << " " << ((~k) & (n - 1)) << "\n";
  if (k != 0)
    cout << k << " " << n - 1 << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}