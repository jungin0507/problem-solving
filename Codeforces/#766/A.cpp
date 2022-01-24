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

void testCase() {
  int N, M, R, C;
  int arr[55][55];
  cin >> N >> M >> R >> C;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      arr[i][j] = INF;

  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    for (int j = 0; j < M; ++j) {
      if (S[j] == 'B')
        arr[i][j] = 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr[i][j] != INF) {
        for (int k = 0; k < N; ++k) {
          arr[k][j] = min(arr[k][j], arr[i][j] + 1);
        }

        for (int k = 0; k < M; ++k) {
          arr[i][k] = min(arr[i][k], arr[i][j] + 1);
        }
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr[i][j] != INF) {
        for (int k = 0; k < N; ++k) {
          arr[k][j] = min(arr[k][j], arr[i][j] + 1);
        }

        for (int k = 0; k < M; ++k) {
          arr[i][k] = min(arr[i][k], arr[i][j] + 1);
        }
      }
    }
  }

  int ans = (arr[R - 1][C - 1] == INF) ? -1 : arr[R - 1][C - 1];
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    testCase();
}