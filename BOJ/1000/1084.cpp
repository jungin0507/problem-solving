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
using ll = unsigned long long;
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
  return { x.first + y.first, x.second + y.second };
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return { x.first - y.first, x.second - y.second };
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

int N;
ostream &operator<<(ostream &o, vector<ll> &v) {
  string s = "";
  ll limit = 100;
  for (int i = N - 1; i >= 0 && limit; --i) {
    if (!v[i]) continue;
    s += string(min(limit, v[i]), '0' + i);
    limit -= min(limit, v[i]);
  }
  if (s.length() < 50) {
    return o << s << "\n"
             << s << "\n";
  } else {
    return o << s.substr(0, 50) << "\n"
             << s.substr(s.length() - 50) << "\n";
  }
}

bool operator<(vector<ll> &v1, vector<ll> &v2) {
  ll sum1 = accumulate(all(v1), 0LL);
  ll sum2 = accumulate(all(v2), 0LL);
  if (sum1 == sum2) {
    for (int i = N - 1; i > 0; --i) {
      if (v1[i] == v2[i]) continue;
      return v1[i] < v2[i];
    }
    return true;
  }
  return sum1 < sum2;
}

void solve() {
  cin >> N;
  vector<ll> P(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  ll M;
  cin >> M;
  vector<ll> res(N);
  ll mn = *min_element(P.rbegin(), P.rend());
  int x = N - 1 - (min_element(P.rbegin(), P.rend()) - P.rbegin());
  if (mn > M) {
    cout << "0\n\n\n";
    return;
  } else if (*min_element(P.rbegin(), P.rend() - 1) > M) {
    cout << "1\n0\n0\n";
    return;
  }
  if (x == 0) {
    res[x] = (M - *min_element(P.rbegin(), P.rend() - 1)) / mn;
    int y = N - 1 - (min_element(P.rbegin(), P.rend() - 1) - P.rbegin());
    res[y] = 1;
    M -= P[x] * res[x];
    M -= P[y] * res[y];
    for (int i = N - 1; i > y && M; --i) {
      ll num = min(M / (P[i] - P[y]), res[y]);
      res[i] += num;
      res[y] -= num;
      M -= (P[i] - P[y]) * num;
    }
  } else {
    res[x] = M / mn;
    M -= P[x] * res[x];
  }
  for (int i = N - 1; i > x && M; --i) {
    ll num = min(M / (P[i] - P[x]), res[x]);
    res[i] += num;
    res[x] -= num;
    M -= (P[i] - P[x]) * num;
  }

  ll sum = 0;
  for (int i = 0; i < N; ++i) sum += res[i];
  cout << sum << "\n";
  string s = "";
  ll len = sum;
  if (len > 100) {
    len = 100;
  }
  int idx = N - 1;
  while (len) {
    if (!res[idx]) {
      --idx;
      continue;
    }
    s += '0' + idx;
    --res[idx];
    --len;
  }
  cout << s.substr(0, min(50, (int)s.length())) << "\n";
  cout << s.substr(max(0, (int)s.length() - 50)) << "\n";
}