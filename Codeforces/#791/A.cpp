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
  ll N;
  cin >> N;
  if (N < 4 || N % 2 != 0) {
    cout << -1 << "\n";
    return;
  }
  if (N % 12 == 0) {
    cout << N / 6 << ' ' << N / 4 << "\n";
  } else if (N % 4 == 0) {
    cout << N / 6 + 1 << ' ' << N / 4 << "\n";
  } else if (N % 6 == 0) {
    cout << N / 6 << ' ' << N / 4 << "\n";
  } else {
    cout << N / 6 + 1 << ' ' << N / 4 << "\n";
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