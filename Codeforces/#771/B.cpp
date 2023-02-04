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
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int o = 0, e = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] % 2) {
      if (a[i] < o) {
        cout << "No\n";
        return;
      }
      o = a[i];
    } else {
      if (a[i] < e) {
        cout << "No\n";
        return;
      }
      e = a[i];
    }
  }
  cout << "Yes\n";
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