#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &it : a) {
    cin >> it;
  }

  long long ans = 0;
  for (int it = 0; it < n; ++it) {
    vector<int> cnt(n);
    for (int i = n - 1; i >= 0; --i) {
      cnt[i] = (a[i] == 0);
      if (i + 1 < n) {
        cnt[i] += cnt[i + 1];
      }
    }
    vector<long long> b = a;
    long long s = accumulate(b.begin(), b.end(), 0ll);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (b[i] == 0) {
        long long x = (i + 1 < n ? cnt[i + 1] : 0);
        b[i] = min(k, x * k - s);
        if (b[i] < -k) {
          ok = false;
        }
        s += b[i];
      }
    }
    if (ok) {
      long long pos = 0, mn = 0, mx = 0;
      for (int i = 0; i < n; ++i) {
        pos += b[i];
        mn = min(mn, pos);
        mx = max(mx, pos);
      }
      if (pos == 0) {
        ans = max(ans, mx - mn + 1);
      }
    }
    cout << boolalpha << ok << "\n";
    for (int i = 0; i < n; ++i) {
      cout << b[i] << ' ' << " ";
    }
    cout << "\n";
    rotate(a.begin(), a.begin() + 1, a.end());
  }

  if (ans == 0) {
    ans = -1;
  }

  cout << ans << endl;

  return 0;
}