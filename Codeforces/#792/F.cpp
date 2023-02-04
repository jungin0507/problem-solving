#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

vector<int> f;

void incr(int x, int d) {
  for (; x < (int)f.size(); x |= (x + 1)) f[x] = max(f[x], d);
}

int get(int x) {
  int ans = -1;
  for (; x >= 0; x = (x & (x + 1)) - 1) ans = max(ans, f[x]);
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &c : a) cin >> c;
  map<int, vector<int>> gist;
  for (int i = 0; i < n; i++) gist[a[i]].pb(i);
  vector<pii> seg(m);
  f.assign(n, -1);
  for (auto &c : seg) {
    cin >> c.fi >> c.se;
    c.fi--;
    c.se--;
    incr(c.fi, c.se);
  }
  vector<int> mnl(n);
  set<int> s;
  int l = n;
  for (int r = n - 1; r >= 0; r--) {
    while (l - 1 >= 0 && !s.count(a[l - 1])) {
      l--;
      s.insert(a[l]);
    }
    mnl[r] = l;
    s.erase(a[r]);
  }
  int mnr = -1;
  for (auto &c : seg) {
    int l = c.fi, r = c.se;
    if (mnl[r] <= l) continue;
    mnr = max(mnr, mnl[r] - 1);
  }
  if (mnr == -1) {
    cout << 0 << "\n";
    return;
  }
  int ans = mnr + 1;
  for (int l = 0; l + 1 < n; l++) {
    if (gist[a[l]][0] != l) {
      int id = lower_bound(all(gist[a[l]]), l) - gist[a[l]].begin() - 1;
      int pr = gist[a[l]][id];
      if (get(pr) >= l) {
        break;
      }
    }
    int id = upper_bound(all(gist[a[l]]), mnr) - gist[a[l]].begin();
    if (id != (int)gist[a[l]].size()) {
      int nxt = gist[a[l]][id];
      if (get(l) >= nxt) {
        mnr = nxt;
      }
    }
    // mnr = max(mnr, l + 1);
    ans = min(ans, mnr - l);
  }
  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#endif
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}