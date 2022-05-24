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

const int sz = 1 << 19;

pii p[sz];
int A[sz], B[sz], C[sz];
int tree[sz << 1];
int N;

int query(int l, int r, int p = 1, int s = 0, int e = sz - 1) {
  if (l <= s && e <= r) {
    return tree[p];
  } else if (r < s || e < l || r < l) {
    return 0;
  }
  int m = (s + e) >> 1;
  return max(query(l, r, p * 2, s, m), query(l, r, p * 2 + 1, m + 1, e));
}

void update(int n, int v, int p = 1, int s = 0, int e = sz - 1) {
  int m = (s + e) >> 1;
  if (s == e) {
    tree[p] = v;
    return;
  }
  if (n <= m) {
    update(n, v, p * 2, s, m);
  } else {
    update(n, v, p * 2 + 1, m + 1, e);
  }
  tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    A[n] = N - i;
  }
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    B[n] = N - i;
  }
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    C[n] = N - i;
  }
  for (int i = 1; i <= N; ++i) {
    p[C[i]] = { A[i], B[i] };
  }

  int ans = 0;
  for (int i = N; i > 0; --i) {
    auto [x, y] = p[i];
    int q = query(x, sz - 1);
    if (q <= y) {
      ++ans;
    }
    update(x, y);
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}