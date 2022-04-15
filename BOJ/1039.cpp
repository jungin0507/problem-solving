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

int N, K;
int M;
int pw[8];
bool visited[10000][15];
vector<int> nn;

int swap_digit(int num, int i, int j) {
  return num - (num % pw[i + 1]) / pw[i] * pw[i] - (num % pw[j + 1]) / pw[j] * pw[j] + (num % pw[j + 1]) / pw[j] * pw[i] + (num % pw[i + 1]) / pw[i] * pw[j];
}

int n_to_ind(int num) {
  int l = 0, r = nn.size() - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (nn[m] == num)
      return m;
    else if (nn[m] < num)
      l = m + 1;
    else
      r = m - 1;
  }
  assert(false);
  return -1;
}

void solve() {
  cin >> N >> K;
  if (N < 10 || (N < 100 && N % 10 == 0)) {
    cout << -1 << "\n";
    return;
  }
  M = (int)log10(N) + 1;
  vector<int> p;

  int tmp = N;
  while (tmp) {
    p.push_back(tmp % 10);
    tmp /= 10;
  }
  sort(p.begin(), p.end());
  do {
    int num = 0;
    for (int n : p) {
      num = num * 10 + n;
    }
    nn.push_back(num);
  } while (next_permutation(p.begin(), p.end()));
  sort(nn.begin(), nn.end());
  nn.erase(unique(nn.begin(), nn.end()), nn.end());

  int ans = -1;
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));
  visited[n_to_ind(N)][0] = true;
  while (!q.empty()) {
    auto [num, cnt] = q.front();
    q.pop();
    if (cnt == K) {
      ans = max(ans, num);
      continue;
    }
    for (int i = 0; i < M; ++i) {
      for (int j = i + 1; j < M; ++j) {
        int nnum = swap_digit(num, i, j);
        if (visited[n_to_ind(nnum)][cnt + 1]) continue;
        q.push(make_pair(nnum, cnt + 1));
        visited[n_to_ind(nnum)][cnt + 1] = true;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pw[0] = 1;
  for (int i = 1; i <= 7; ++i) pw[i] = pw[i - 1] * 10;

  solve();
}