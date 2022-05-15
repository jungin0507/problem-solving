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
  string S;
  cin >> S;
  int N = S.length();
  vector<int> vec(N);
  for (int i = 0; i < N; ++i) vec[i] = S[i] - '0';
  int total = 0;
  for (int i = 0; i < N; ++i) {
    if (vec[i] == 1) total++;
  }
  int ans = 0x3f3f3f3f;
  int cnt_0 = 0;
  int cnt_1 = 0;
  for (int i = 0; i < total; ++i) {
    if (vec[i] == 0) {
      cnt_0++;
    } else {
      cnt_1++;
    }
  }
  ans = min(ans, min(cnt_0, total - cnt_1));
  for (int i = 1; i + total - 1 < N; ++i) {
    if (vec[i + total - 1] == 0) {
      cnt_0++;
    } else {
      cnt_1++;
    }
    if (vec[i - 1] == 0) {
      cnt_0--;
    } else {
      cnt_1--;
    }
    ans = min(ans, min(cnt_0, total - cnt_1));
  }
  cout << ans << "\n";
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