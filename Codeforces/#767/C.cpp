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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> mex(n);
  vector<bool> chk(n + 2);
  if (a[n - 1] == 0) {
    mex[n - 1] = 1;
  } else {
    mex[n - 1] = 0;
  }
  chk[a[n - 1]] = true;
  for (int i = n - 2; i >= 0; --i) {
    chk[a[i]] = true;
    if (a[i] == mex[i + 1]) {
      for (int j = mex[i + 1] + 1; j <= n + 1; ++j) {
        if (chk[j] == false) {
          mex[i] = j;
          break;
        }
      }
    } else {
      mex[i] = mex[i + 1];
    }
  }

  fill(chk.begin(), chk.end(), false);
  int cur_mex = 0;
  int prev = 0;
  int mx = -1;
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    chk[a[i]] = true;
    mx = max(mx, a[i]);

    if (a[i] == cur_mex) {
      for (int j = cur_mex + 1; j <= mx + 1; ++j) {
        if (chk[j] == false) {
          cur_mex = j;
          break;
        }
      }
    }

    if (mex[prev] == cur_mex) {
      b.push_back(cur_mex);
      for (int j = prev; j <= i; ++j) {
        chk[a[j]] = false;
      }
      prev = i + 1;
      cur_mex = 0;
      mx = 0;
    }
  }
  cout << b.size() << "\n";
  for (int i = 0; i < b.size(); ++i) {
    cout << b[i] << " ";
  }
  cout << "\n";
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