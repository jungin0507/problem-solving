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

bool chk(string s) {
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != s[s.length() - i - 1]) return false;
  }
  return true;
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  if (chk(s)) {
    cout << 1 << "\n";
  } else {
    cout << ((k >= 1) ? 2 : 1) << "\n";
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