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

const int DIGIT = 10, LEN = 11;

int N;
int cnt[LEN][DIGIT];
int S[LEN][DIGIT];

ll f(int n) {
  if (n <= 10) {
    return n - 1;
  }

  for (int l = 1; l < LEN; ++l) {
    for (int d = 0; d < DIGIT; ++d) {
      if (n <= cnt[l][d]) {
        return (ll)d * pow(10, l - 1) + f(n + S[l - 2][9]);
      } else {
        n -= cnt[l][d];
      }
    }
  }
  return -1;
}

void solve() {
  cin >> N;
  ++N;

  int sum = 0;
  for (int l = 0; l < LEN; ++l) {
    for (int d = 0; d < DIGIT; ++d) {
      sum += cnt[l][d];
    }
  }
  if (N > sum) {
    cout << -1 << "\n";
    return;
  }

  cout << f(N) << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int d = 0; d < DIGIT; ++d) cnt[1][d] = 1;

  for (int l = 2; l < LEN; ++l) {
    for (int d = 0; d < DIGIT; ++d) {
      for (int d_ = 0; d_ < d; ++d_) {
        cnt[l][d] += cnt[l - 1][d_];
      }
    }
  }

  for (int l = 1; l < LEN; ++l) {
    for (int d = 0; d < DIGIT; ++d) {
      if (d == 0)
        S[l][d] = cnt[l][d] + S[l - 1][DIGIT - 1];
      else
        S[l][d] = cnt[l][d] + S[l][d - 1];
    }
  }

  solve();
}