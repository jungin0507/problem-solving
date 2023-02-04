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
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  int ans = 0;
  if (A[0] != 0) {
    ans += 1;
    bool flag = false;
    for (int i = 1; i < N; ++i) {
      if (A[i] == A[i - 1]) flag = true;
    }
    if (!flag) ++ans;
  }
  for (int i = 1; i < N; ++i) {
    if (A[i] != 0) ++ans;
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