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
void solve(int N);
void preproc();

signed main() {
  fastio;
  int T = 1;
  // cin >> T;
  preproc();
  int N;
  while (cin >> N) solve(N);
}

/* actual code */

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

struct Trie {
  int node[26];
  bool finished;
  bool isroot;
  int cnt;
  Trie() {
    finished = false;
    isroot = false;
    cnt = 0;
    for (int i = 0; i < 26; ++i) node[i] = 0;
  }
} trie[1111111];

int node_cnt = 1;

void insert(int p, char *str) {
  ++trie[p].cnt;
  if (*str == '\0') {
    trie[p].finished = true;
    return;
  }
  int c = *str - 'a';
  if (!trie[p].node[c]) trie[p].node[c] = node_cnt++;
  insert(trie[p].node[c], str + 1);
}

int calc(int p) {
  int ret = 0;
  int child = 0;
  int sum = 0;
  for (int i = 0; i < 26; ++i)
    if (trie[p].node[i]) {
      ++child;
      sum += trie[trie[p].node[i]].cnt;
    }
  if (trie[p].isroot)
    ret = 0;
  else if (child > 1 || (child == 1 && trie[p].finished))
    ret = sum;
  for (int i = 0; i < 26; ++i) {
    if (trie[p].node[i]) {
      ret += calc(trie[p].node[i]);
    }
  }
  return ret;
}

void preproc() {
}

void solve(int N) {
  int root = node_cnt++;
  trie[root].isroot = true;
  rep(i, N) {
    char s[100];
    cin >> s;
    insert(root, s);
  }
  double total = calc(root) + N;
  cout.precision(2);
  cout << fixed;
  cout << total / N << "\n";
}