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
  ll hc, dc, hm, dm;
  ll k, w, a;
  cin >> hc >> dc >> hm >> dm >> k >> w >> a;
  for (int i = 0; i <= k; ++i) {
    int na = i;
    int nw = k - i;
    if (hm / (dc + w * nw) + (hm % (dc + w * nw) != 0) <= (hc + a * na) / dm + ((hc + a * na) % dm != 0)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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