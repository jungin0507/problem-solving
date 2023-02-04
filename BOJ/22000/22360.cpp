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
int N;
char S[MAX_N];
vector<int> adj[MAX_N];
map<pii, ll> m[MAX_N];
int point[MAX_N];
ll ans = 0;

std::pair<int, int> operator+(const std::pair<int, int> &x, const std::pair<int, int> &y) {
  return std::make_pair(x.first + y.first, x.second + y.second);
}

std::pair<int, int> operator-(const std::pair<int, int> &x, const std::pair<int, int> &y) {
  return std::make_pair(x.first - y.first, x.second - y.second);
}

std::pair<int, int> operator*(const int &c, const std::pair<int, int> &x) {
  return std::make_pair(c * x.first, c * x.second);
}

void dfs(int here, int parent, pii v) {
  pii cur = { 0, 0 };
  if (S[here] == 'U') {
    cur = { 1, 1 };
  } else if (S[here] == 'C') {
    cur = { 0, -1 };
  } else if (S[here] == 'P') {
    cur = { -1, 1 };
  }

  point[here] = here;
  m[here][v + cur] = 1;

  for (int there : adj[here]) {
    if (there == parent) continue;
    dfs(there, here, v + cur);
    auto &child = m[point[there]];
    if (child.size() > m[point[here]].size()) {
      for (auto &[val, cnt] : m[point[here]]) {
        if (child.find(2 * v + cur - val) != child.end()) {
          ans += child[2 * v + cur - val] * cnt;
        }
      }
      for (auto &[val, cnt] : m[point[here]]) {
        child[val] += cnt;
      }
      m[point[here]].clear();
      point[here] = point[there];
    } else {
      for (auto &[val, cnt] : child) {
        if (m[point[here]].find(2 * v + cur - val) != m[point[here]].end()) {
          ans += cnt * m[point[here]][2 * v + cur - val];
        }
      }
      for (auto &[val, cnt] : child) {
        m[point[here]][val] += cnt;
      }
      child.clear();
    }
  }
}

void solve() {
  cin >> N;
  cin >> S;
  for (int _ = 0; _ < N - 1; ++_) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1, { 0, 0 });
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}