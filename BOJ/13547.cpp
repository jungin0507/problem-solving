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

const int MAX_N = 1e5 + 5;
const int MAX_V = 1e6 + 5;

struct Query {
  int s, e;
  int idx;
  Query(int s = 0, int e = 0, int idx = 0) : s(s), e(e), idx(idx) {}
};

int N, M;
int A[MAX_N];
Query Q[MAX_N];
int cnt[MAX_V];
int res[MAX_N];

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int s, e;
    cin >> s >> e;
    Q[i] = Query(s, e, i);
  }

  sort(Q, Q + M, [&](const Query &x, const Query &y) {
    if (x.s / (int)sqrt(N) == y.s / (int)sqrt(N))
      return x.e < y.e;
    return x.s / sqrt(N) < y.s / sqrt(N);
  });

  int l = 1, r = 1;
  int ans = 1;
  ++cnt[A[1]];
  for (int i = 0; i < M; ++i) {
    while (Q[i].s < l) {
      ++cnt[A[--l]];
      if (cnt[A[l]] == 1)
        ++ans;
    };
    while (Q[i].s > l) {
      if (cnt[A[l]] == 1)
        --ans;
      --cnt[A[l++]];
    };
    while (Q[i].e < r) {
      if (cnt[A[r]] == 1)
        --ans;
      --cnt[A[r--]];
    };
    while (Q[i].e > r) {
      ++cnt[A[++r]];
      if (cnt[A[r]] == 1)
        ++ans;
    };
    res[Q[i].idx] = ans;
  }
  for (int i = 0; i < M; ++i) {
    cout << res[i] << "\n";
  }
}