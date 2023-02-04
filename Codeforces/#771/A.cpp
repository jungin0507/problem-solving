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
  vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  int r = 0;
  int l = 0;
  for (int i = 0; i < N; ++i) {
    if (p[i] != i + 1) {
      l = i;
      break;
    }
  }

  for (int i = 0; i < N; ++i) {
    if (p[i] == l + 1) {
      r = i;
      break;
    }
  }
  for (int i = 0; i < l; ++i) {
    cout << p[i] << " ";
  }
  for (int i = r; i >= l; --i) {
    cout << p[i] << " ";
  }
  for (int i = r + 1; i < N; ++i) {
    cout << p[i] << " ";
  }
  cout << "\n";
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