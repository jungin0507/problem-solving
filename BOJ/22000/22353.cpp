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
  double a, d, k;
  cin >> a >> d >> k;
  d /= 100;
  k /= 100;
  double res = 0;
  vector<double> vec;
  double p = 1;
  while (1) {
    vec.push_back(p * d);
    if (d >= 1) break;
    p *= (1 - d);
    d *= (1 + k);
    if (d > 1) d = 1;
  }
  for (int i = 0; i < vec.size(); ++i) {
    res += a * (i + 1) * vec[i];
  }
  cout << fixed;
  cout.precision(7);
  cout << res << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}