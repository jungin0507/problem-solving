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

const int MAX_N = 150000;

map<pii, pii> roads;
map<pii, string> traffic;
vector<pii> cross;
pair<int, bool> DP[MAX_N][2][10][60];
pii v[MAX_N];
int ss[60];
int N, K;

void solve() {
  cin >> N >> K;
  for (int _ = 0; _ < N; ++_) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    cross.emplace_back(x, y);
    traffic[pii(x, y)] = s;
  }

  for (int i = 0; i < 60; ++i) {
    ss[i] = ((ll)1 << i) % K;
  }

  int ind = 0;
  sort(cross.begin(), cross.end());
  for (int i = 1; i < N; ++i) {
    auto [x, y] = cross[i];
    auto [px, py] = cross[i - 1];
    if (px == x) {
      v[ind] = pii(x, (y + py) >> 1);
      roads[pii(x, (y + py) >> 1)] = pii(ind++, 0);
    }
  }

  sort(cross.begin(), cross.end(), [&](pii &a, pii &b) {
    if (a.second == b.second) {
      return a.first < b.second;
    }
    return a.second < b.second;
  });
  for (int i = 1; i < N; ++i) {
    auto [x, y] = cross[i];
    auto [px, py] = cross[i - 1];
    if (py == y) {
      v[ind] = pii(x, (y + py) >> 1);
      roads[pii((x + px) >> 1, y)] = pii(ind++, 1);
    }
  }

  for (auto &road : roads) {
    auto [x, y] = road.first;
    int i = road.second.first;

    for (int d : { 0, 1 }) {
      string t;
      if (road.second.second == 0) {
        pii c = make_pair(x, y + ((d) ? 1 : -1));
        t = traffic[c];
        for (int k = 0; k < 10; ++k) {
          pii npos;
          if (t[k] == '1') {
            npos = make_pair(x, y);
          } else if (t[k] == '2') {
            npos = make_pair(x, y + ((d) ? 1 : -1));
            if (!roads.count(npos))
              npos = make_pair(x, y);
          } else if (t[k] == '3') {
            npos = make_pair()
          } else if (t[k] == '4') {
          }
        }
      }
    }

    for (int t = 1; t < 60; ++t) {
      for (int d : { 0, 1 }) {
        for (int k = 0; k < 10; ++k) {
          auto [midx, mdir] = DP[i][d][k][t - 1];
          int nk = (k + ss[t - 1]) % K;
          DP[i][d][k][t] = DP[midx][mdir][nk][t - 1];
        }
      }
    }
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
}