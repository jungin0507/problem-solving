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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int l = n - 1, r = n - 1;

  vector<int> cnt(n + 1);
  while (l >= 0 || r >= 0) {
    if (l >= 0 && r >= 0 && a[l] == b[r]) {
      --l;
      --r;
    } else if (r >= 0 && r + 1 < n && b[r] == b[r + 1]) {
      cnt[b[r]]++;
      --r;
    } else if (l >= 0 && cnt[a[l]]) {
      cnt[a[l]]--;
      --l;
    } else {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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