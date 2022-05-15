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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == a[i + 1]) ++cnt;
  }

  int d = -1;
  int ans = 0;
  for (int i = 0; i < n - 2 && cnt > 1; ++i) {
    if (a[i] == a[i + 1]) {
      int tmp = a[i + 2];
      if (a[i + 1] == a[i + 2])
        --cnt;
      a[i + 1] = a[i + 2] = d--;
      if (i + 3 < n && a[i + 3] == tmp)
        --cnt;
      ++ans;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}