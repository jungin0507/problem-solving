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

const int MAX_N = 305;
const ll MOD = 1e9 + 7;

ll A[MAX_N][MAX_N][50];
ll S[MAX_N][MAX_N];
char arr[MAX_N][MAX_N];
int N, M, L;
string s;

ll query(int x1, int y1, int x2, int y2) {
  if (x1 > N || x1 <= 0) return 0;
  if (x2 > N || x2 <= 0) return 0;
  if (y1 > M || y1 <= 0) return 0;
  if (y2 > M || y2 <= 0) return 0;
  if (x1 > x2 || y1 > y2) return 0;
  return (S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]) % MOD;
}

void solve() {
  cin >> N >> M >> L;
  cin >> s;
  for (int i = 1; i <= N; ++i) {
    string input;
    cin >> input;
    for (int j = 1; j <= M; ++j) {
      arr[i][j] = input[j - 1];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      A[i][j][0] = (arr[i][j] == s[0]);
      S[i][j] = A[i][j][0] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    }
  }

  for (int l = 1; l < s.length(); ++l) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        if (arr[i][j] != s[l]) continue;
        if (i - 2 > 0 && j - 2 > 0) {
          A[i][j][l] += query(1, 1, i - 2, j - 2) - A[i - 2][j - 2][l - 1];
          A[i][j][l] = (A[i][j][l] + MOD) % MOD;
        }
        if (i - 2 > 0 && j + 2 <= M) {
          A[i][j][l] += query(1, j + 2, i - 2, M) - A[i - 2][j + 2][l - 1];
          A[i][j][l] = (A[i][j][l] + MOD) % MOD;
        }
        if (i + 2 <= N && j - 2 > 0) {
          A[i][j][l] += query(i + 2, 1, N, j - 2) - A[i + 2][j - 2][l - 1];
          A[i][j][l] = (A[i][j][l] + MOD) % MOD;
        }
        if (i + 2 <= N && j + 2 <= M) {
          A[i][j][l] += query(i + 2, j + 2, N, M) - A[i + 2][j + 2][l - 1];
          A[i][j][l] = (A[i][j][l] + MOD) % MOD;
        }
      }
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        S[i][j] = A[i][j][l] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        S[i][j] = (S[i][j] + MOD) % MOD;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      ans += A[i][j][s.length() - 1];
      ans %= MOD;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}