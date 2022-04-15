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
  queue<int> q;
  q.push(1);
  q.push(2);
  int tmp = 0;
  for (int i = 3; i <= n; i += 2) {
    vector<pii> cpl(4);
    cpl[0].second = q.front();
    q.pop();
    cpl[1].second = q.front();
    q.pop();
    cpl[2].second = i;
    if (i + 1 <= n)
      cpl[3].second = i + 1;
    else {
      cpl[3].second = q.front();
      q.pop();
    }
    for (int q = 0; q < 4; ++q) {
      cout << "? " << cpl[(q + 1) % 4].second << " " << cpl[(q + 2) % 4].second << " " << cpl[(q + 3) % 4].second << "\n";
      cout.flush();
      cin >> cpl[q].first;
      if (cpl[q].first == -1) exit(0);
    }
    sort(cpl.begin(), cpl.end());
    q.push(cpl[0].second);
    q.push(cpl[1].second);
    if (i == 3)
      tmp = cpl[3].second;
    if (i == n - 2) {
      q.push(tmp);
    }
  }

  cout << "! " << q.front() << " ";
  q.pop();
  cout << q.front() << "\n";
  cout.flush();
  q.pop();
}

signed main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}