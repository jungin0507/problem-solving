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

const int MAX_N = 3e5 + 5;

int N;
string S;
int A[MAX_N];
vector<int> vec;

void solve() {
  cin >> N;
  cin >> S;
  for (int i = 0; i < N; ++i) cin >> A[i];
  int i = 0;
  while (i < N) {
    int mx = 0;
    int j = i;
    while (j < N && S[j] == S[i]) {
      mx = max(mx, A[j++]);
    }
    vec.push_back(mx);
    i = j;
  }
  N = vec.size();

  if (N <= 2) {
    cout << 0 << "\n";
    return;
  } else if (N == 3) {
    cout << vec[1] << "\n";
    return;
  }
  sort(vec.begin() + 1, vec.end() - 1, greater<int>());
  ll sum = 0;
  for (int i = 1; i <= (N - 2) / 2 + N % 2; ++i) {
    sum += vec[i];
  }
  cout << sum << "\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}