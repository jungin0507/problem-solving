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
template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
  return i >> x.first >> x.second;
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

/* operators of std::vector<T> */
template <class T>
ostream &operator<<(ostream &o, vector<T> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << (*it) << ' ';
  }
  return o;
}
template <class T>
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
  cin >> T;
  preproc();
  while (T-- > 0) solve();
}

/* actual code */

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

int chk(string &s) {
  if (s.front() == 'A' && s.back() == 'B') {
    return 0;
  } else if (s.front() == s.back()) {
    return 1;
  } else {
    return 2;
  }
}

bool cmp(string &x, string &y) {
  if (chk(x) == chk(y)) return x < y;
  return chk(x) < chk(y);
}

void preproc() {
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string S;
  cin >> S;
  int N = S.length();
  int cnt_a = 0;
  int cnt_b = 0;
  for (char ch : S) {
    if (ch == 'A')
      ++cnt_a;
    else
      ++cnt_b;
  }
  if (cnt_a != (a + c + d) || cnt_b != (b + c + d)) {
    cout << "NO\n";
    return;
  }
  if (c == 0 && d == 0) {
    cout << "YES\n";
    return;
  }
  vector<string> vec;
  for (int i = 0; i + 1 < N; ++i) {
    if (S[i] == S[i + 1]) continue;
    int j = i + 1;
    while (j < N && S[j] != S[j - 1]) {
      ++j;
    }
    vec.push_back(S.substr(i, j - i));
    i = j - 1;
  }
  for (string &s : vec) {
    if (s.front() == 'B') {
      for (auto &ch : s) {
        ch = ch == 'A' ? 'B' : 'A';
      }
    }
  }
  sort(all(vec), cmp);
  int i = 0;
  int j = 0;
  cout << vec << "\n";
  while (i < vec.size() && c) {
    if (j + 1 >= vec[i].length()) {
      ++i;
      continue;
    }
    if (vec[i][j] == 'B') {
      ++j;
    } else {
      --c;
      j += 2;
    }
  }
  while (i < vec.size() && d) {
    if (j + 1 >= vec[i].length()) {
      ++i;
      j = 0;
      continue;
    }
    if (vec[i][j] == 'A') {
      ++j;
    } else {
      --d;
      j += 2;
    }
  }
  cout << c << ' ' << d << "\n";
}