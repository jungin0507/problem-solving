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

const int MAX_N = 1e6 + 5;

int A[MAX_N];
int DP[MAX_N];
int N;

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < MAX_N; ++i)
    DP[i] = INF;

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  DP[0] = A[0];
  int ans = 1;
  for (int i = 1; i < N; ++i) {
    int u = lower_bound(DP, DP + ans, A[i]) - DP;
    ans = max(ans, u + 1);
    DP[u] = min(DP[u], A[i]);
  }

  cout << ans << "\n";
}