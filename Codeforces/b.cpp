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
  string s;
  cin >> s;
  stack<char> stk;
  if (s.length() == 1 || s[s.length() - 1] == 'A') {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'A')
      stk.push(s[i]);
    else if (!stk.empty())
      stk.pop();
    else {
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