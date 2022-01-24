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
#define FOR(i, n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;

using namespace std;

const int MAX_N = 1e6 + 5;
const ll mod = 1e9 + 7;

ll fac[MAX_N];
ll ifac[MAX_N];

ll POW(ll a, ll p) {
  ll ret = 1;
  while (p) {
    if (p % 2) {
      ret *= a;
      ret %= mod;
    }
    a = a * a;
    a %= mod;
    p >>= 1;
  }
  return ret;
}

ll comb(ll n, ll r) {
  ll ret = fac[n];
  ret *= ifac[r];
  ret %= mod;
  ret *= ifac[n - r];
  ret %= mod;
  return ret;
}

void testCase() {
  ll N, M, K;
  cin >> N >> M >> K;
  ll ans = 0;
  if (N == M) {
    cout << K * N % mod << "\n";
    return;
  }
  for (int i = 1; i <= M; ++i) {
    ll coef = comb(N - i - 1, M - i);
    ll base = i * K % mod;
    ll calc = coef * base % mod;
    calc *= POW(POW(2, N - i), mod - 2) % mod;
    ans += calc;
    ans %= mod;
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fac[0] = 1;
  ifac[0] = 1;
  for (int i = 1; i < MAX_N; ++i) {
    fac[i] = fac[i - 1] * i % mod;
    ifac[i] = ifac[i - 1] * POW(i, mod - 2) % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    testCase();
  }
}