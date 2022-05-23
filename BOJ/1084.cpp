#include <bits/stdc++.h>

// #define int long long
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))
#define fastio                             \
  {                                        \
    ios::ios_base::sync_with_stdio(false); \
    cin.tie(0);                            \
    cout.tie(0);                           \
  }

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
using pid = pair<int, double>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using vi = vector<int>;

template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first + y.first, x.second + y.second};
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
}
template <class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template <class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}
void solve();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  while (T-- > 0) solve();
}

const int MAX_N = 1e5 + 5;
const ll INF = 1e18;

void solve() {
  int N;
  cin >> N;
  vector<ll> P(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  ll M;
  cin >> M;

  vector<ll> res(N);
  ll mn = INF;
  int x = N - 1;
  for (int i = 1; i < N; ++i) {
    if (P[i] <= mn) {
      mn = P[i];
      x = i;
    }
  }
  ll k = M / mn;
  ll r = M % mn;
  for (int i = N - 1; i > x && k >= r / (P[i] - mn); --i) {
    ll diff = P[i] - mn;
    res[i] = r / diff;
    k -= res[i];
    r %= diff;
  }
  res[x] = k;

  vector<ll> res2(N);
  if (P[0] < mn) {
    M -= mn;
    k = M / P[0];
    r = M % P[0];
    ll sum = 0;
    for (int i = N - 1; i > 0 && k >= r / (P[i] - P[0]); --i) {
      ll diff = P[i] - P[0];
      res2[i] = r / diff;
      k -= res2[i];
      r %= diff;
      sum += P[i] * res2[i];
    }
    res2[0] = k;
    sum += P[0] * k;
    for (int i = N - 1; i > 0; --i) {
      if (P[i] <= mn + M - sum) {
        res2[i]++;
        break;
      }
    }
  }

  int sz1 = 0;
  int sz2 = 0;
  // for (int i = 0; i < N; ++i) {
  //   if (res[i]) ++sz1;
  //   if (res2[i]) ++sz2;
  // }
  // if (!sz1 && !sz2) {
  //   cout << 0 << "\n";
  //   return;
  // } else if (!sz1 && sz2 == 1) {
  //   cout << 1 << "\n";
  //   cout << 0 << "\n";
  //   cout << 0 << "\n";
  //   return;
  // }
  // string s1 = "";
  // ll limit = 100;
  // for (int i = N - 1; i >= 0; --i) {
  //   if (!res[i]) continue;
  //   s1 += string(min(limit, res[i]), '0' + i);
  //   limit -= min(limit, res[i]);
  // }
  // string s2 = "";
  // limit = 100;
  // for (int i = N - 1; i >= 0; --i) {
  //   if (!res2[i]) continue;
  //   s2 += string(min(limit, res2[i]), '0' + i);
  //   limit -= min(limit, res2[i]);
  // }
  // cout << max(sz1, sz2) << "\n";
  // if (sz1 > sz2) {
  //   if (s1.length() < 50) {
  //     cout << s1 << "\n";
  //     cout << s1 << "\n";
  //   } else {
  //     cout << s1.substr(0, 50) << "\n";
  //     cout << s1.substr(50) << "\n";
  //   }
  // } else if (sz1 < sz2) {
  //   if (s2.length() < 50) {
  //     cout << s2 << "\n";
  //     cout << s2 << "\n";
  //   } else {
  //     cout << s2.substr(0, 50) << "\n";
  //     cout << s2.substr(50) << "\n";
  //   }
  // } else if (s1 > s2) {
  //   if (s1.length() < 50) {
  //     cout << s1 << "\n";
  //     cout << s1 << "\n";
  //   } else {
  //     cout << s1.substr(0, 50) << "\n";
  //     cout << s1.substr(50) << "\n";
  //   }
  // } else {
  //   if (s2.length() < 50) {
  //     cout << s2 << "\n";
  //     cout << s2 << "\n";
  //   } else {
  //     cout << s2.substr(0, 50) << "\n";
  //     cout << s2.substr(50) << "\n";
  //   }
  // }
}