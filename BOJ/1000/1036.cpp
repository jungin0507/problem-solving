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

const int MAX_N = 55, MAX_L = 100, MOD = 36;

int num[MAX_N][MAX_L];
vi profit[MOD];
int ans[MAX_L];
int len[MAX_N];
int N, K;

int c_to_36(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 10;
  } else {
    return c - '0';
  }
}

char _36_to_c(int n) {
  if (n >= 10) {
    return n - 10 + 'A';
  } else {
    return n + '0';
  }
}

void solve() {
  cin >> N;

  for (int i = 0; i < MOD; ++i) {
    profit[i].resize(MAX_L);
  }

  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    len[i] = S.length();
    for (int j = 0; j < S.length(); ++j) {
      num[i][j] = c_to_36(S[j]);
      ans[j] += c_to_36(S[j]);
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < len[i]; ++j) {
      profit[num[i][j]][j] += 35 - num[i][j];
    }
  }

  for (int i = 0; i < MOD; ++i) {
    for (int j = 0; j < MAX_L - 1; ++j) {
      profit[i][j + 1] += profit[i][j] / MOD;
      profit[i][j] %= MOD;
    }
  }

  sort(profit, profit + MOD, [&](const vi &a, const vi &b) {
    for (int i = MAX_L - 1; i >= 0; --i) {
      if (a[i] < b[i])
        return false;
      else if (a[i] > b[i])
        return true;
    }
    return false;
  });

  cin >> K;

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < MAX_L; ++j) {
      ans[j] += profit[i][j];
    }
  }

  for (int i = 0; i + 1 < MAX_L; ++i) {
    ans[i + 1] += ans[i] / MOD;
    ans[i] %= MOD;
  }

  int j = MAX_L - 1;
  while (j >= 0 && ans[j] == 0)
    --j;

  string ret = "";
  while (j >= 0) {
    ret += _36_to_c(ans[j]);
    --j;
  }
  if (ret == "")
    ret = "0";
  cout << ret << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
}