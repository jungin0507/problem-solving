#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, pl, End;
ll k, x, co[15], ch[15], tmp[15];

struct Money {
  ll cost;
  int num;
} a[15];

bool cmp(Money p1, Money p2) {
  if (p1.cost == p2.cost) return p1.num > p2.num;
  return p1.cost < p2.cost;
}

int printLen() {
  End = pl = 0;
  if (k < a[1].cost) return 1;
  if (a[1].num == 0) {
    if (k < a[2].cost) return 2;
    k -= a[2].cost;
    pl = 1;
  }
  ch[a[1].num] = k / a[1].cost;
  ch[a[2].num] = pl;
  cout << k / a[1].cost + pl << '\n';
  k %= a[1].cost;
  return 0;
}

void Solve() {
  ll diff;
  for (int i = n - 1; i > a[1].num; i--) {
    diff = co[i] - a[1].cost;
    ll change = min(ch[a[1].num], k / diff);
    ch[i] += change;
    ch[a[1].num] -= change;
    k %= diff;
  }
  for (int i = 0; i < n; i++) tmp[i] = ch[i];
  for (int i = n - 1, go = 1; i >= 0; i--) {
    while (go <= 50 && ch[i]) {
      cout << i;
      go++;
      ch[i]--;
    }
  }
  cout << '\n';
  for (int i = 0; i < n; i++) ch[i] = tmp[i];
  vector<int> ans;
  for (int i = 0, go = 1; i < n; i++) {
    while (go <= 50 && ch[i]) {
      ans.push_back(i);
      go++;
      ch[i]--;
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) cout << i;
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n) {
    memset(ch, 0, sizeof(ch));
    if (n == 1) {
      cin >> x >> k;
      if (x > k)
        cout << "0\n\n\n";
      else
        cout << "1\n0\n0\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      cin >> co[i - 1];
      a[i] = { co[i - 1], i - 1 };
    }
    cin >> k;
    sort(a + 1, a + n + 1, cmp);
    x = printLen();
    if (x == 1) {
      cout << "0\n\n\n";
      continue;
    } // 아무것도 안되는 경우
    if (x == 2) {
      cout << "1\n0\n0\n";
      continue;
    } // 0만 되는 경우
    if (pl) {
      for (int i = n - 1; i > a[2].num; i--) {
        if (k >= co[i] - a[2].cost) {
          k -= co[i] - a[2].cost;
          ch[a[2].num]--;
          ch[i]++;
          break;
        }
      }
    }
    Solve();
  }
}