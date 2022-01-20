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

pll A, B, C, D;

int ccw(pll a, pll b, pll c) {
  ll v = (a.first - c.first) * (b.second - c.second) - (a.second - c.second) * (b.first - c.first);
  if (v > 0)
    return 1;
  else if (v < 0)
    return -1;
  else
    return 0;
}

bool isIntersect() {
  if (A > B)
    swap(A, B);
  if (C > D)
    swap(C, D);

  int ab = ccw(A, B, C) * ccw(A, B, D);
  int cd = ccw(C, D, A) * ccw(C, D, B);

  if (ab == 0 && cd == 0)
    return C <= B && A <= D;

  return ab <= 0 && cd <= 0;
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x1, y1, x2, y2;
  ll x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  A = pll(x1, y1);
  B = pll(x2, y2);
  C = pll(x3, y3);
  D = pll(x4, y4);

  cout << isIntersect() << "\n";
}