#include <bits/stdc++.h>

#define int long long
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

const int MAX_N = 3e3 + 5;
const int INF = 0x7fffffff;

int N, K;
pii prefix[MAX_N];

void solve() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    int A;
    cin >> A;
    prefix[i] = prefix[i - 1] + pii{ A - (!A) * K, A + (!A) * K };
  }
  auto GET = [&](int l, int r) -> pii {
    if (l > r) return { 0, 0 };
    return prefix[r] - (l ? prefix[l - 1] : pii{ 0, 0 });
  };
  if (prefix[N].first > 0 || prefix[N].second < 0) {
    cout << -1 << "\n";
    return;
  }
  int mx = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      pii a = GET(0, i);
      pii b = GET(i + 1, j);
      pii c = GET(j + 1, N);
      {
        int R = min(a.second, -b.first - c.first);
        int L = max(R + b.first, -c.second);
        mx = max(mx, R - L);
      }
      // {
      //   int L = max(a.first + b.first, -c.second);
      //   int R = min(a.second, L - b.first);
      //   mx = max(mx, R - L);
      // }
    }
  }
  for (int i = 0; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      pii a = GET(0, i);
      pii b = GET(i + 1, j);
      pii c = GET(j + 1, N);
      // {
      //   int L = max(a.first, -b.second - c.second);
      //   int R = min(L + b.second, -c.first);
      //   mx = max(mx, R - L);
      // }
      {
        int R = min(a.second + b.second, -c.first);
        int L = max(a.first, R - b.second);
        mx = max(mx, R - L);
      }
    }
  }
  cout << mx + 1 << "\n";
}