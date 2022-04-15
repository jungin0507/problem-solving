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

struct UnionFind {
  int N;
  vector<int> parent;
  vector<int> rank;

  UnionFind(int N) : N(N) {
    parent.resize(N);
    rank.resize(N);
    for (int i = 0; i < N; ++i) parent[i] = i;
  }

  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (rank[u] > rank[v]) swap(u, v);

    parent[u] = v;

    if (rank[u] == rank[v]) rank[v]++;
  }
};

int N, M;
int adj[55][55];

void solve() {
  cin >> N >> M;
  UnionFind UF(N);

  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    for (int j = 0; j < N; ++j) {
      if (S[j] == 'Y') adj[i][j] = 1;
    }
  }

  vector<int> res(N);
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (!adj[i][j] || UF.find(i) == UF.find(j)) continue;
      adj[i][j] = 2;
      res[i]++;
      res[j]++;
      ++cnt;
      UF.merge(i, j);
    }
  }

  if (cnt < N - 1) {
    cout << -1 << "\n";
    return;
  }

  M -= cnt;

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (adj[i][j] == 1 && M > 0) {
        res[i]++;
        res[j]++;
        --M;
      }
    }
  }

  if (M != 0) {
    cout << -1 << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}