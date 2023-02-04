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
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  if (N == 1) {
    int mx = 0;
    mx = max(mx, A);
    mx = max(mx, B);
    mx = max(mx, C);
    mx = max(mx, D);
    mx = max(mx, E);
    mx = max(mx, F);
    cout << A + B + C + D + E + F - mx << "\n";
    return;
  }
  int mn1 = INF;
  mn1 = min(mn1, A);
  mn1 = min(mn1, B);
  mn1 = min(mn1, C);
  mn1 = min(mn1, D);
  mn1 = min(mn1, E);
  mn1 = min(mn1, F);
  int mn2 = INF;
  mn2 = min(mn2, A + B);
  mn2 = min(mn2, A + D);
  mn2 = min(mn2, A + E);
  mn2 = min(mn2, A + C);
  mn2 = min(mn2, B + D);
  mn2 = min(mn2, B + C);
  mn2 = min(mn2, B + F);
  mn2 = min(mn2, C + E);
  mn2 = min(mn2, C + F);
  mn2 = min(mn2, D + E);
  mn2 = min(mn2, D + F);
  mn2 = min(mn2, E + F);
  int mn3 = INF;
  mn3 = min(mn3, A + B + D);
  mn3 = min(mn3, A + B + C);
  mn3 = min(mn3, A + C + E);
  mn3 = min(mn3, A + D + E);
  mn3 = min(mn3, B + C + F);
  mn3 = min(mn3, B + D + F);
  mn3 = min(mn3, C + E + F);
  mn3 = min(mn3, D + E + F);

  ll n1 = (N - 2) * (N - 1) * 4 + (N - 2) * (N - 2);
  ll n3 = 4;
  ll n2 = 4 * (N - 1) + 4 * (N - 2);

  ll ans = n1 * mn1 + n3 * mn3 + n2 * mn2;
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}