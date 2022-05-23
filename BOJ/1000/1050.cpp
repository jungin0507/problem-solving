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

const ll MAX = 1e9 + 1;

map<string, ll> cost;
string recipe[55];
int N, M;
void solve() {
  cin >> N >> M;

  while (N-- > 0) {
    string s;
    int c;
    cin >> s >> c;
    cost[s] = c;
  }

  for (int i = 0; i < M; ++i) {
    cin >> recipe[i];
  }

  while (true) {
    bool isUpdated = false;
    for (int i = 0; i < M; ++i) {
      istringstream ss(recipe[i]);
      string stringBuf;

      getline(ss, stringBuf, '=');
      string left = stringBuf;

      ll sum = 0;
      while (getline(ss, stringBuf, '+')) {
        int c = stringBuf[0] - '0';
        string right = stringBuf.substr(1);
        if (!cost.count(right)) {
          sum = 0;
          break;
        }
        sum = min(MAX, sum + c * cost[right]);
      }

      if (sum == 0) continue;
      if (!cost.count(left)) {
        cost[left] = sum;
        isUpdated = true;
      } else if (cost[left] > sum) {
        isUpdated = true;
        cost[left] = sum;
      }
    }
    if (!isUpdated) break;
  }

  cout << ((cost["LOVE"] != 0) ? cost["LOVE"] : -1) << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}