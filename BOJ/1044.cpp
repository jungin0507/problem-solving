#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define INF 9876543210000
#define vi vector<int>
#define sq(x) ((x) * (x))
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int MAX_N = 36;

int N;
ll s1[MAX_N];
ll s2[MAX_N];
pll a1[MAX_N];
pll a2[MAX_N];

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> s1[i];
  for (int i = 0; i < N; ++i) cin >> s2[i];

  for (int b = 0; b < (1 << (N / 2)); ++b) {
    int tmp = b;
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = N / 2 - 1; i >= 0; --i) {
      if (tmp % 2) {
        sum2 += s2[i];
      } else {
        sum1 += s1[i];
      }
      tmp >>= 1;
    }
    a1[b] = make_pair(sum1 - sum2, b);
  }

  for (int b = 0; b < (1 << (N - N / 2)); ++b) {
    int tmp = b;
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = N - 1; i >= N / 2; --i) {
      if (tmp % 2) {
        sum2 += s2[i];
      } else {
        sum1 += s1[i];
      }
      tmp >>= 1;
    }
    a2[b] = make_pair(sum1 - sum2, b);
  }
  sort(a1, a1 + (1 << (N / 2)));
  sort(a2, a2 + (1 << (N - N / 2)), [&](const pll &a, const pll &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });

  ll mn = INF;
  ll ans = 0;
  int i = 0, j = (1 << (N - N / 2)) - 1;
  while (i < (1 << (N / 2)) && j >= 0) {
    if (mn > abs(a1[i].first + a2[j].first)) {
      mn = abs(a1[i].first + a2[j].first);
      ans = a1[i].second << (N - N / 2) | a2[j].second;
    } else if (mn == abs(a1[i].first + a2[j].first) && ans > (a1[i].second << (N - N / 2) | a2[j].second)) {
      ans = a1[i].second << (N - N / 2) | a2[j].second;
    }

    if (j == 0)
      ++i;
    else if (i == (1 << (N / 2)) - 1)
      --j;
    else if (a1[i].first + a2[j].first < 0)
      ++i;
    else
      --j;
  }

  string prt = "";
  for (int i = 0; i < N; ++i) {
    if (ans % 2) {
      prt = "2 " + prt;
    } else {
      prt = "1 " + prt;
    }
    ans >>= 1;
  }
  cout << prt << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}