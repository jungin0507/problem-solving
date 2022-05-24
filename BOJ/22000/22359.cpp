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
#define rep(from, to, stride) for (auto i = (from); i < (to); i += (stride))
#define rrep(from, to, stride) for (auto i = (from)-1; i >= (to); i -= (stride))

using ll = long long;
using namespace std;

const int MAX_N = 1 << 10;

int arr[MAX_N][MAX_N];

void recursive_func(int lx, int ly, int rx, int ry, int c, int a, int b) {
  if (lx == rx && ly == ry) return;
  int mx = (lx + rx) >> 1;
  int my = (ly + ry) >> 1;

  int color = 0;
  if (rx - lx == 1) color = c;

  if (a <= mx) {
    if (b <= my) {  // 1
      arr[mx][my + 1] = arr[mx + 1][my] = arr[mx + 1][my + 1] = color;
      recursive_func(lx, ly, mx, my, 2, a, b);
      recursive_func(lx, my + 1, mx, ry, 1, mx, my + 1);
      recursive_func(mx + 1, ly, rx, my, 1, mx + 1, my);
      recursive_func(mx + 1, my + 1, rx, ry, 2, mx + 1, my + 1);
    } else {  // 2
      arr[mx][my] = arr[mx + 1][my] = arr[mx + 1][my + 1] = color;
      recursive_func(lx, ly, mx, my, 2, mx, my);
      recursive_func(lx, my + 1, mx, ry, 1, a, b);
      recursive_func(mx + 1, ly, rx, my, 1, mx + 1, my);
      recursive_func(mx + 1, my + 1, rx, ry, 2, mx + 1, my + 1);
    }
  } else {
    if (b <= my) {  // 3
      arr[mx][my] = arr[mx][my + 1] = arr[mx + 1][my + 1] = color;
      recursive_func(lx, ly, mx, my, 2, mx, my);
      recursive_func(lx, my + 1, mx, ry, 1, mx, my + 1);
      recursive_func(mx + 1, ly, rx, my, 1, a, b);
      recursive_func(mx + 1, my + 1, rx, ry, 2, mx + 1, my + 1);
    } else {  // 4
      arr[mx][my] = arr[mx][my + 1] = arr[mx + 1][my] = color;
      recursive_func(lx, ly, mx, my, 2, mx, my);
      recursive_func(lx, my + 1, mx, ry, 1, mx, my + 1);
      recursive_func(mx + 1, ly, rx, my, 1, mx + 1, my);
      recursive_func(mx + 1, my + 1, rx, ry, 2, a, b);
    }
  }
}

void solve(int a, int b, int k) {
  memset(arr, 0, sizeof(arr));

  recursive_func(0, 0, (1 << k) - 1, (1 << k) - 1, 0, a, b);

  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j < (1 << k); ++j) {
      if (i == a && j == b)
        cout << '@';
      else
        cout << char('a' + arr[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, k;
  cin >> t >> k;
  while (t-- > 0) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    solve(a, b, k);
  }
}