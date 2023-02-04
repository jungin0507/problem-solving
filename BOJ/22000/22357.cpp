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

int A[35][2005];
int D[35];
int K, N;

bool is_prime(int n) {
  for (int i = 2; i * i < n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  cin >> K >> N;
  int idx = 0;
  for (int i = 2000; idx < K && i <= 2500; ++i) {
    if (!is_prime(i)) continue;
    D[idx++] = i;
  }
  for (int i = 0; i < K; ++i) {
    int num = 1;
    for (int j = 0; j < N; ++j) {
      cout << num << " ";
      num += D[i];
    }
    cout << "\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}