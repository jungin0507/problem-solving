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

const int MAX_N = 2e5 + 5;
const int MAX = 360000;

int N;
int A[MAX_N];
int B[MAX_N];
int S[2 * MAX_N];
int P[MAX_N];
int pi[MAX_N];

void get_pi() {
  int j = 0;
  pi[0] = 0;
  for (int i = 1; i < N; ++i) {
    while (j > 0 && P[i] != P[j]) {
      j = pi[j - 1];
    }
    if (P[i] == P[j])
      pi[i] = ++j;
  }
}

void solve() {
  get_pi();
  for (int i = N; i < 2 * N - 1; ++i) {
    S[i] = S[i - N];
  }

  int j = 0;
  for (int i = 0; i < 2 * N - 1; ++i) {
    while (j > 0 && S[i] != P[j]) {
      j = pi[j - 1];
    }
    if (S[i] == P[j]) {
      ++j;
    }
    if (j == N) {
      cout << "possible\n";
      return;
    }
  }
  cout << "impossible\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }

  sort(A, A + N);
  sort(B, B + N);

  for (int i = 0; i < N - 1; ++i) {
    S[i] = A[i + 1] - A[i];
    P[i] = B[i + 1] - B[i];
  }
  S[N - 1] = A[0] - A[N - 1] + MAX;
  P[N - 1] = B[0] - B[N - 1] + MAX;
  solve();
}