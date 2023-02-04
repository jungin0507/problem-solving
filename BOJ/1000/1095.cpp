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

const int MAX_N = 1e5 + 5;
const int INF = 0x7fffffff;
const ll MOD = 1e9 + 7;

vector<ll> prime;
map<ll, ll> prime_factor[3];
ll factor[MAX_N];

bool is_prime(int v) {
  for (int i = 2; i <= sqrt(v); ++i) {
    if (v % i == 0) {
      return false;
    }
  }
  return true;
}

map<ll, ll> factorization(ll V) {
  map<ll, ll> ret;
  for (auto p : prime) {
    ret[p] = 0;
    ll tmp = p;
    while (V / tmp) {
      ret[p] += V / tmp;
      tmp *= p;
    }
  }
  return ret;
}

map<ll, ll> calc(ll v) {
  map<ll, ll> ret;
  ll tmp = v;
  while (tmp > 1) {
    ret[factor[tmp]]++;
    tmp /= factor[tmp];
  }
  return ret;
}

void preproc() {
}

void solve() {
  ll S, F, M;
  cin >> S >> F >> M;
  for (int i = 2; i < MAX_N; ++i) {
    if (factor[i]) continue;
    prime.push_back(i);
    for (int j = i; j < MAX_N; j += i) {
      factor[j] = i;
    }
  }

  auto m1 = factorization(S + F);
  auto m2 = factorization(S);
  auto m3 = factorization(F);

  for (auto p : prime) {
    m1[p] -= m2[p] + m3[p];
  }

  for (ll n = M; n >= 2; --n) {
    bool ok = true;
    auto m = calc(n);
    for (auto [p, c] : m) {
      if (c > m1[p]) {
        ok = false;
      }
    }
    if (ok) {
      cout << n << "\n";
      return;
    }
  }
  cout << 1 << "\n";
}