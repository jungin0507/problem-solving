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

int N;

void solve() {
  int Q;
  cin >> N >> Q;
  vector<ll> A(N + 1);
  vector<ll> cnt(N + 1);
  vector<ll> query(Q);
  ll sum = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    sum += A[i];
  }
  int c = 0;
  ll v = 0;
  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      ll x;
      cin >> i >> x;
      if (cnt[i] == c) {
        sum += x - A[i];
      } else {
        sum += x - v;
      }
      cnt[i] = c;
      A[i] = x;
    } else {
      ll x;
      cin >> x;
      sum = x * N;
      ++c;
      v = x;
    }
    cout << sum << "\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}