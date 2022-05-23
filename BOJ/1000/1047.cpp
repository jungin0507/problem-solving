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

const int MAX_N = 45;

struct info {
  int x, y, l;
  info(int x = 0, int y = 0, int l = 0) : x(x), y(y), l(l) {}

  bool operator<(const info &x) const {
    return l > x.l;
  }
};

int N;
info tree[MAX_N];

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x, y, l;
    cin >> x >> y >> l;
    tree[i] = info(x, y, l);
  }

  sort(tree, tree + N);

  int ans = INF;
  for (int i = 0; i < N; ++i)
    for (int j = i; j < N; ++j)
      for (int k = j; k < N; ++k)
        for (int l = k; l < N; ++l) {
          int a = i, b = i, c = i, d = i;

          if (tree[i].x < tree[a].x) a = i;
          if (tree[j].x < tree[a].x) a = j;
          if (tree[k].x < tree[a].x) a = k;
          if (tree[l].x < tree[a].x) a = l;

          if (tree[i].x > tree[b].x) b = i;
          if (tree[j].x > tree[b].x) b = j;
          if (tree[k].x > tree[b].x) b = k;
          if (tree[l].x > tree[b].x) b = l;

          if (tree[i].y < tree[c].y) c = i;
          if (tree[j].y < tree[c].y) c = j;
          if (tree[k].y < tree[c].y) c = k;
          if (tree[l].y < tree[c].y) c = l;

          if (tree[i].y > tree[d].y) d = i;
          if (tree[j].y > tree[d].y) d = j;
          if (tree[k].y > tree[d].y) d = k;
          if (tree[l].y > tree[d].y) d = l;

          int needs = tree[b].x - tree[a].x + tree[d].y - tree[c].y;
          needs *= 2;
          int cnt = 0;
          for (int m = 0; m < N; ++m) {
            if (m == a || m == b || m == c || m == d) continue;
            if (tree[m].x < tree[a].x || tree[m].y < tree[c].y || tree[m].x > tree[b].x || tree[m].y > tree[d].y) {
              needs -= tree[m].l;
              ++cnt;
            }
          }

          for (int m = 0; m < N; ++m) {
            if (m == a || m == b || m == c || m == d) continue;
            if (needs > 0 && (tree[m].x >= tree[a].x && tree[m].y >= tree[c].y && tree[m].x <= tree[b].x && tree[m].y <= tree[d].y)) {
              needs -= tree[m].l;
              ++cnt;
            }
          }

          if (needs <= 0)
            ans = min(ans, cnt);
        }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}