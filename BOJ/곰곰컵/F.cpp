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

const int MAX_N = 4e6 + 5;
const int INF = 0x7fffffff;

int sum[MAX_N];

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (!b) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void solve() {
  int Av, As, Ae;
  int Bv, Bs, Be;
  int Cv, Cs, Ce;
  cin >> Av >> As >> Ae;
  cin >> Bv >> Bs >> Be;
  cin >> Cv >> Cs >> Ce;
  if (Av < Bv) {
    swap(Av, Bv);
    swap(As, Bs);
    swap(Ae, Be);
  }
  if (Av < Cv) {
    swap(Av, Cv);
    swap(As, Cs);
    swap(Ae, Ce);
  }
  if (Bv < Cv) {
    swap(Bv, Cv);
    swap(Bs, Cs);
    swap(Be, Ce);
  }
  // A > B > C
  assert(lm < MAX_N);
  for (int i = 0; i < lm; ++i) {
    sum[i] = i - 1 >= 0 ? sum[i - 1] : 0;
    if (i % Av < As || i % Av > Ae) continue;
    if (i % Bv < Bs || i % Bv > Be) continue;
    sum[i] += 1;
  }
  int s = Cs;
  int e = Ce;

  int num = lm / gcd(lm, Cv);
  auto GET = [](int l, int r) -> int {
    if (l > r) swap(l, r);
    if (l < 1) return sum[r];
    return sum[r] - sum[l - 1];
  };
  for (int i = 0; i < num; ++i) {
    if (GET(s % lm, e % lm) > 0) {
      for (int j = s; j <= e; ++j) {
        if (GET(j % lm, j % lm) == 1) {
          cout << j << "\n";
          return;
        }
      }
    }
    s += Cv;
    e += Cv;
  }
  cout << "-1\n";
}