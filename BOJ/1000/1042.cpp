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

const int MAX_N = 2505;
const int MAX_M = 50;
const ll MOD = 1e9 + 7;

string DNA;
int N;
int M;
pair<string, string> tbl[MAX_M];
map<string, int> m;
ll cnt[MAX_N];
int DP1[MAX_N][4];
int DP2[MAX_N][4][4];
int DP3[MAX_N][4][4][4];

int translate(char c) {
  switch (c) {
  case 'A':
    return 0;
  case 'C':
    return 1;
  case 'G':
    return 2;
  case 'T':
    return 3;
  default:
    return -1;
  }
}

void solve() {
  cin >> DNA;
  N = DNA.length();
  cin >> M;
  for (int i = 0; i < M; ++i) {
    string cod, ami;
    cin >> cod >> ami;
    tbl[i] = make_pair(cod, ami);
    m[ami] = N;
  }

  for (int i = 0; i < MAX_N; ++i) {
    for (int j = 0; j < 4; ++j) {
      DP1[i][j] = N;
      for (int k = 0; k < 4; ++k) {
        DP2[i][j][k] = N;
        for (int l = 0; l < 4; ++l) {
          DP3[i][j][k][l] = N;
        }
      }
    }
  }

  for (int i = N - 1; i >= 0; --i) {
    for (int a = 0; a < 4; ++a) {
      DP1[i][a] = DP1[i + 1][a];
    }
    DP1[i][translate(DNA[i])] = i;

    for (int a = 0; a < 4; ++a)
      for (int b = 0; b < 4; ++b)
        DP2[i][a][b] = DP1[DP1[i][a] + 1][b];

    for (int a = 0; a < 4; ++a)
      for (int b = 0; b < 4; ++b)
        for (int c = 0; c < 4; ++c)
          DP3[i][a][b][c] = DP2[DP1[i][a] + 1][b][c];

    for (auto [cod, ami] : tbl) {
      int a = translate(cod[0]), b = translate(cod[1]), c = translate(cod[2]);
      m[ami] = min(m[ami], DP3[i][a][b][c]);
    }

    for (auto [ami, ind] : m) {
      if (ami == "" || ind >= N) continue;
      cnt[i] += cnt[ind + 1] + 1;
      cnt[i] %= MOD;
    }
  }
  cout << cnt[0] << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
}