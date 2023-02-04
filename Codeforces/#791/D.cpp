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

const int MAX_N = 2e5 + 5;
vector<int> adj[MAX_N];
ll w[MAX_N];
int DP[MAX_N];
bool visited[MAX_N];
bool finished[MAX_N];
bool has_cycle = false;
void DFS(int here, ll limit) {
  DP[here] = 1;
  visited[here] = true;
  for (int there : adj[here]) {
    if (w[there] > limit) continue;
    if (!visited[there])
      DFS(there, limit);
    else if (!finished[there])
      has_cycle = true;
    DP[here] = max(DP[here], DP[there] + 1);
  }
  finished[here] = true;
}

void solve() {
  int N, M;
  ll K;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> w[i];
  }
  for (int _ = 0; _ < M; ++_) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  ll s = 1;
  ll e = 1e9 + 5;
  while (s < e) {
    ll m = (s + e) >> 1;
    memset(visited, false, sizeof(visited));
    memset(finished, false, sizeof(finished));
    memset(DP, 0, sizeof(DP));
    has_cycle = false;
    for (int i = 1; i <= N; ++i) {
      if (visited[i]) continue;
      if (w[i] > m) continue;
      DFS(i, m);
    }
    bool flag = false;
    for (int i = 1; i <= N; ++i) {
      if (DP[i] >= K) {
        flag = true;
        break;
      }
    }
    if (flag || has_cycle) {
      e = m;
    } else {
      s = m + 1;
    }
  }
  if (e > 1e9) {
    cout << -1 << "\n";
  } else {
    cout << e << "\n";
  }
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}