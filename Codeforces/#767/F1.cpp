
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

typedef long long ll;

using namespace std;

const int MAX_N = 2e3 + 5;
const ll mod = 1e9 + 7;

ll DP[MAX_N][MAX_N];

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

void testCase() {
  int N, M, K;
  cin >> N >> M >> K;
  cout << K * DP[N][M] % mod << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll two = POW(2, mod - 2);

  for (int i = 1; i < MAX_N; ++i)
    DP[i][i] = i % mod;
  for (int i = 2; i < MAX_N; ++i) {
    for (int j = 1; j < i; ++j) {
      DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) * two % mod;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    testCase();
  }
}