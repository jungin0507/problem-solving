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

struct SuffixArray {
  int N;
  string S;
  vector<int> sa;
  vector<int> lcp;

  SuffixArray(string S) : S(S) {
    this->N = S.length();
    sa.resize(N);
    lcp.resize(N);
  }

  void buildSA() {
    int M = max(256, N) + 1;
    vector<int> rank(N + N), newRank(N + N), cnt(M), idx(N);
    for (int i = 0; i < N; ++i) {
      sa[i] = i;
      rank[i] = S[i];
    }

    for (int d = 1; d < N; d <<= 1) {
      auto cmp = [&](int i, int j) {
        if (rank[i] == rank[j])
          return rank[i + d] < rank[j + d];
        return rank[i] < rank[j];
      };

      //(i+d)rank 기준으로 counting sort
      for (int i = 0; i < M; ++i)
        cnt[i] = 0;
      for (int i = 0; i < N; ++i)
        cnt[rank[i + d]]++;
      for (int i = 1; i < M; ++i)
        cnt[i] += cnt[i - 1];
      for (int i = N - 1; i >= 0; --i)
        idx[--cnt[rank[i + d]]] = i;

      //(i)rank 기준으로 counting sort
      for (int i = 0; i < M; ++i)
        cnt[i] = 0;
      for (int i = 0; i < N; ++i)
        cnt[rank[i]]++;
      for (int i = 1; i < M; ++i)
        cnt[i] += cnt[i - 1];
      for (int i = N - 1; i >= 0; --i)
        sa[--cnt[rank[idx[i]]]] = idx[i];

      newRank[sa[0]] = 1;
      for (int i = 1; i < N; ++i)
        newRank[sa[i]] = newRank[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
      for (int i = 0; i < N; ++i)
        rank[i] = newRank[i];

      //모든 rank가 서로 다르다면 break
      if (rank[sa[N - 1]] == N)
        break;
    }
  }

  void buildLCP() {
    vector<int> isa(N);
    for (int i = 0; i < N; ++i)
      isa[sa[i]] = i;

    int k = 0;
    for (int i = 0; i < N; ++i) {
      if (isa[i] == 0)
        continue;
      int j = sa[isa[i] - 1];
      while (S[i + k] == S[j + k])
        ++k;
      lcp[isa[i]] = k;
      if (k > 0)
        --k;
    }
  }
};

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string S;
  cin >> S;

  SuffixArray SA(S);
  SA.buildSA();
  SA.buildLCP();

  ll ans = S.length() * (S.length() + 1) / 2;

  for (int i = 1; i < S.length(); ++i) {
    ans -= SA.lcp[i];
  }
  cout << ans << "\n";
}