#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for (auto i = 0; i < (n); ++i)
#define rrep(i, n) for (auto i = (n)-1; i >= 0; --i)
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

/* operators of std::pair<T1, T2> */
template<class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template<class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
}
template<class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first + y.first, x.second + y.second};
}
template<class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
  return {x.first - y.first, x.second - y.second};
}
template<class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x + y;
}
template<class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
  x = x - y;
}

/* operators of std::vector<T> */
template<class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template<class T>
istream &operator>>(istream &i, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    i >> (*it);
  }
  return i;
}
void solve();
void preproc();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  preproc();
  while (T-- > 0) solve();
}

/* actual code */

const int sz = 1 << 12;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

vector<int> bit[13];
int r_possible[sz];
int c_possible[sz];

int bit_cnt(int v) {
  int ret = 0;
  while (v) {
    ret += v % 2;
    v >>= 1;
  }
  return ret;
}

void build(vector<int> arr, int possible[]) {
  for (int i = 0; i < arr.size(); ++i) {
    possible[arr[i]] = 1;
  }
  if (arr.size() == 1) {
    return;
  }
  for (int i = 0; i + 1 < arr.size(); ++i) {
    vector<int> tmp;
    for (int k = 0; i - k >= 0 || i + 1 + k < arr.size(); ++k) {
      if (i - k >= 0 && i + 1 + k < arr.size())
        tmp.push_back(arr[i - k] | arr[i + 1 + k]);
      else if (i - k >= 0)
        tmp.push_back(arr[i - k]);
      else if (i + 1 + k < arr.size())
        tmp.push_back(arr[i + 1 + k]);
    }
    build(tmp, possible);
  }
}

void preproc() {
  for (int b = 0; b < sz; ++b) {
    bit[bit_cnt(b)].push_back(b);
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> arr(N, vector<int>(M));
  cin >> arr;
  vector<int> tmp;
  for (int i = 0; i < N; ++i) {
    tmp.push_back(1 << i);
  }
  build(tmp, r_possible);
  tmp.clear();
  for (int i = 0; i < M; ++i) {
    tmp.push_back(1 << i);
  }
  build(tmp, c_possible);
  int ans = arr[0][0];
  for (int i = 0; i < (1 << N); ++i) {
    if (!r_possible[i]) continue;
    for (int j = 0; j < (1 << M); ++j) {
      if (!c_possible[j]) continue;
      int sum = 0;
      for (int x = 0; x < N; ++x) {
        if (!(i & (1 << x))) continue;
        for (int y = 0; y < M; ++y) {
          if (!(j & (1 << y))) continue;
          sum += arr[x][y];
        }
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << "\n";
}
