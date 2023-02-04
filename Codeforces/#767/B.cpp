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

void testCase() {
  int l, r, k;
  cin >> l >> r >> k;
  int n = (r - l + 1) / 2 + (l % 2 && r % 2);
  if (l == r) {
    if (l == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    return;
  }
  if (n > k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    testCase();
  }
}