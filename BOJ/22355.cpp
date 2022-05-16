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

struct info {
  ll a = 0;
  ll b = 0;
};
ll coef[sz];
ll cnst[sz];
ll H[sz];
ll A[sz];
ll B[sz];
int N, K;

void update(int l, int r, ll v, ll vv) {
  if (l == 0 || r == 0) return;
  while (l < sz) {
    coef[l] += v;
    cnst[l] += vv;
    l += (l & -l);
  }
  r++;
  if (r >= sz) return;
  while (r < sz) {
    coef[r] -= v;
    cnst[r] -= vv;
    r += (r & -r);
  }
}

info query(int n) {
  info ret = {0, 0};
  while (n) {
    ret.a += coef[n];
    ret.b += cnst[n];
    n &= n - 1;
  }
  return ret;
}

void solve() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> H[i];
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N; ++i) cin >> B[i];

  ll mn = 1e15;

  for (int i = 1; i < K; ++i) {
    update(1, H[i], -B[i], H[i] * B[i]);
    update(H[i], sz - 1, A[i], -H[i] * A[i]);
  }

  // for (int i = K; i <= N; ++i) {
  //   update(1, H[i], -B[i], H[i] * B[i]);
  //   update(H[i], sz - 1, A[i], -H[i] * A[i]);
  //   update(1, H[i - K], B[i - K], -H[i - K] * B[i - K]);
  //   update(H[i - K], sz - 1, -A[i - K], H[i - K] * A[i - K]);
  //   ll lo = 1;
  //   ll hi = sz - 1;
  //   while (hi - lo >= 3) {
  //     ll p = (2 * lo + hi) / 3;
  //     ll q = (lo + 2 * hi) / 3;
  //     info f_p = query(p);
  //     info f_q = query(q);
  //     if (f_p.a * p + f_p.b > f_q.a * q + f_q.b) {
  //       lo = p;
  //     } else {
  //       hi = q;
  //     }
  //   }
  //   for (int j = lo; j <= hi; ++j) {
  //     info f = query(j);
  //     mn = min(mn, f.a * j + f.b);
  //     cout << j << " " << f.a << "\n";
  //   }
  // }
  // cout << mn << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}