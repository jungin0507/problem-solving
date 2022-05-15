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

const int sz = 1 << 17;
int cnt_x[sz];
int cnt_y[sz];
ll tree_x[sz];
ll tree_y[sz];

void update_x(int i, int v) {
  while (i < sz) {
    tree_x[i] += v;
    i += i & -i;
  }
}

void update_y(int i, int v) {
  while (i < sz) {
    tree_y[i] += v;
    i += i & -i;
  }
}

ll query_x(int l, int r) {
  ll ret = 0;
  while (r) {
    ret += tree_x[r];
    r &= r - 1;
  }
  l--;
  while (l) {
    ret -= tree_x[l];
    l &= l - 1;
  }
  return ret;
}

int query_y(int l, int r) {
  int ret = 0;
  while (r) {
    ret += tree_y[r];
    r &= r - 1;
  }
  l--;
  while (l) {
    ret -= tree_y[l];
    l &= l - 1;
  }
  return ret;
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      if (!cnt_x[x]) update_x(x, 1);
      if (!cnt_y[y]) update_y(y, 1);
      cnt_x[x]++;
      cnt_y[y]++;
    } else if (t == 2) {
      int x, y;
      cin >> x >> y;
      cnt_x[x]--;
      cnt_y[y]--;
      if (!cnt_x[x]) update_x(x, -1);
      if (!cnt_y[y]) update_y(y, -1);
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << "            " << query_x(x1, x2) << " " << query_y(y1, y2) << "\n";
      if (query_x(x1, x2) == x2 - x1 + 1 || query_y(y1, y2) == y2 - y1 + 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}