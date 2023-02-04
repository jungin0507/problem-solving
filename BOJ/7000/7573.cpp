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
  int N, L, M;
  cin >> N >> L >> M;
  vector<pii> fish(M);
  for (int i = 0; i < M; ++i) cin >> fish[i].first >> fish[i].second;
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      int x = fish[i].first, y = fish[j].second;
      for (int l = 1; l < L / 2; ++l) {
        int cnt = 0;
        for (int k = 0; k < M; ++k) {
          if (fish[k].first >= x && fish[k].first <= x + l && fish[k].second >= y && fish[k].second <= y + L / 2 - l) ++cnt;
        }
        ans = max(ans, cnt);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}